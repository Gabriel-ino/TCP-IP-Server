#include "TcpServerController.hpp"

const void TCPServerController::Start(){
    tcp_new_conn_acc->StartTCPNewAcceptorThread();
    tcp_client_svc_mgr->StartTcpClientServiceManagerThread();
    tcp_client_db_mgr->StartDbManager();

    std::cout << "Server running at: (" << network_utils->network_n_to_p(ip_addr, 0) << ", " << port << ")\n";
}

const void TCPServerController::Stop(){
    
}


const void TCPServerController::ProcessNewClient(TCPClient *tcp_client){
    tcp_client_db_mgr->AddClientToDb(tcp_client);

    tcp_client_svc_mgr->ClientFDStartListen(tcp_client);
}

const void TCPServerController::SetServerNotifyCallbacks(
    void(*client_connected)(const TCPServerController *, const TCPClient *),
	void(*client_disconnected)(const TCPServerController *, const TCPClient *),
	void (*client_msg_rvcd)(const TCPServerController *, const TCPClient *, unsigned char*, uint16_t)
){
    this->client_connected = client_connected;
    this->client_disconnected = client_disconnected;
    this->client_msg_rvcd = client_msg_rvcd;
}

const void TCPServerController::Display(){
    std::cout << "Server Name: " << this->m_Name << '\n';
    std::cout << "Listening on: [" << network_utils->network_n_to_p(this->ip_addr, 0) << ", " << this->port << '\n';

    this->tcp_client_db_mgr->DisplayClientDb();
}

        

