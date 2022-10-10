#include "TcpClientServiceManager.hpp"


void * tcp_client_svc_manager_thread_fn(void *arg){
    TCPClientServiceManager *svc_manager = (TCPClientServiceManager *)arg;
    svc_manager->StartTcpClientServiceManagerThreadInternal();
    return NULL;
}

const void TCPClientServiceManager::StartTcpClientServiceManagerThread(){
    pthread_attr_t attr;
    pthread_attr_init (&attr);
    pthread_create(client_svc_mgr_thread, &attr, tcp_client_svc_manager_thread_fn, (void*)this);
}

const void TCPClientServiceManager::ClientFDStartListen(TCPClient *tcp_client){
    
}


