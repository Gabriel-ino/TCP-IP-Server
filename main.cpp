#include "TcpServerController.hpp"
#include "TcpClient.hpp"
#include "NetworkUtils.hpp"
#include <arpa/inet.h>

#include <string>

Utils network_utils;


static void print_client(const TCPClient *tcpclient){
    uint32_t ipval = htonl(tcpclient->ip_addr);
    uint16_t port = htons(tcpclient->port_no);
    std::cout << "[" << network_utils.network_n_to_p(ipval, 0) << ", " << port << "]\n";
}

static void print_server(const TCPServerController *tcpserver){
    uint32_t ipval = htonl(tcpserver->ip_addr);
    uint16_t port = htons(tcpserver->port);

    std::cout << '[' << network_utils.network_n_to_p(ipval, 0) << ", " << port << "]\n";

}


static void app_client_connected(const TCPServerController *tcpserver, const TCPClient *tcpclient){
    print_server(tcpserver);
    std::cout << "Client: ";
    print_client(tcpclient);
}

static void app_client_disconnected(const TCPServerController *tcpserver, const TCPClient *tcpclient){

}

static void app_client_received(const TCPServerController *tcpserver, const TCPClient *tcpclient, unsigned char* msg, uint16_t msg_size){

}


int main(int argc, char** argv){
    uint16_t PORT = 40000;
    std::string ip = "127.0.0.1";
    std::string name = "Default TCP Server";

    TCPServerController *server = new TCPServerController(ip, PORT, name);
    server->Start();
    server->SetServerNotifyCallbacks(app_client_connected, app_client_disconnected, app_client_received);
    
    std::cin.get();
    server->Display();

    delete server;


    return 0;
}



