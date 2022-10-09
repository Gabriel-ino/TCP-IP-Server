#include "TcpServerController.hpp"

const void TCPServerController::Start(){
    tcp_new_conn_acc->StartTCPNewAcceptorThread();
    tcp_client_svc_mgr->StartTcpClientServiceManagerThread();
    tcp_client_db_mgr->StartDbManager();

    std::cout << "Server running at: (" << network_utils->network_n_to_p(ip_addr, 0) << ", " << port << ")\n";
}

const void TCPServerController::Stop(){
    
}




