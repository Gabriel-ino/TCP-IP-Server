#include "TcpNewConnectionAcceptor.hpp"
#include "NetworkUtils.hpp"
#include "TcpClient.hpp"


const void TCPNewConnectionAcceptor::StartTCPNewAcceptorThreadInternal(){

    Utils networkUtils;
    int opt{1};

    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(tcp_ctrl->port);
    serv_addr.sin_addr.s_addr = htonl(tcp_ctrl->ip_addr);

    if (setsockopt(accept_fd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) < 0){
        std::cout << "Set Socket Failed\n" << strerror(errno) << '\n';
        exit(0);
    }

    std::cout << "Here";

    // Bind Socket
    if(bind(this->accept_fd, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr)) == -1){
        std::cout << "Error: Accept socket bind failed\n";
        exit(0);
    }

    if (listen(accept_fd, 5) < 0){
        std::cout << "Listen Failed\n";
        exit(0);
    }

    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int comm_sock_fd;

    while (1){
        comm_sock_fd = accept(accept_fd, (struct sockaddr *)&client_addr, &addr_len);
        
        if (comm_sock_fd < 0){
            std::cout << "Error Accepting new connections\n";
            continue;
        }

        auto client = std::make_shared<TCPClient>(client_addr.sin_addr.s_addr, client_addr.sin_port);

        client->tcp_ctrl = tcp_ctrl;
        client->comm_fd = comm_sock_fd;

        //if (tcp_ctrl->client_connected){

        tcp_ctrl->client_connected(tcp_ctrl, client.get());

      //  }

        tcp_ctrl->ProcessNewClient(client.get());

        uint32_t ip_val = htonl(client_addr.sin_addr.s_addr);

        std::cout << "Connection accepted from client[" << networkUtils.network_n_to_p(ip_val, 0) << ", " << client_addr.sin_port << "]\n";
    }
}


static void* listenNewConn(void *arg){
    TCPNewConnectionAcceptor *tcp_new_conn_acc = (TCPNewConnectionAcceptor*)arg;

    tcp_new_conn_acc->StartTCPNewAcceptorThreadInternal();

}

const void TCPNewConnectionAcceptor::StartTCPNewAcceptorThread(){
    if (pthread_create(startNewConnectionThread, NULL, listenNewConn, (void*)this)){
        std::cout << "Thread Creation Failed\n";
        exit(0);
    }

    std::cout << "Service Started!\n";
}


