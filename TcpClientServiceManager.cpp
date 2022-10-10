#include "TcpClientServiceManager.hpp"


void * tcp_client_svc_manager_thread_fn(void *arg){
    TCPClientServiceManager *svc_manager = (TCPClientServiceManager *)arg;
    svc_manager->StartTcpClientServiceManagerThreadInternal();
    return NULL;
}

const void TCPClientServiceManager::StartTcpClientServiceManagerThreadInternal(){

}

const void TCPClientServiceManager::StartTcpClientServiceManagerThread(){
    pthread_attr_t attr;
    pthread_attr_init (&attr);
    pthread_create(client_svc_mgr_thread, &attr, tcp_client_svc_manager_thread_fn, (void*)this);
}

const void TCPClientServiceManager::ClientFDStartListen(TCPClient *tcp_client){
    
}


const int TCPClientServiceManager::GetMaxFd(){
    int max_fd_lcl{0};

    for(auto &i:tcp_client_db){
        if (i->comm_fd > max_fd_lcl){
            max_fd_lcl = i->comm_fd;
        }

    }

    return max_fd_lcl;
}


