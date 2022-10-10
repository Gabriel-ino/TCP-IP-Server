#include "TcpClientServiceManager.hpp"



void * tcp_client_svc_manager_thread_fn(void *arg){
    TCPClientServiceManager *svc_manager = (TCPClientServiceManager *)arg;
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcancelstate(PTHREAD_CANCEL_DEFERRED, NULL);

    svc_manager->StartTcpClientServiceManagerThreadInternal();

    return NULL;
}

const void TCPClientServiceManager::StartTcpClientServiceManagerThreadInternal(){
    int recv_bytes;
    TCPClient *tcp_client, *next_tcp_client;

    struct sockaddr_in client_addr;

    socklen_t addr_len = sizeof(client_addr);

    this->max_fd = this->GetMaxFd();

    FD_ZERO(&backup_fd_set);

    CopyClientFDToFDSet(&backup_fd_set);

    while (1){
        memcpy(&this->active_fd_set, &this->backup_fd_set, sizeof(fd_set));
        select(this->max_fd+1, &this->active_fd_set, 0, 0, 0);

        for (auto &i:tcp_client_db){
            next_tcp_client = ++i;

            if(FD_ISSET(tcp_client->comm_fd, &this->active_fd_set)){
                recv_bytes = recvfrom(tcp_client->comm_fd,
                                     client_received_buffer,
                                     TCP_CLIENT_RECV_BUFFER_SIZE,
                                     0,
                                     (struct sockaddr *)&client_addr, &addr_len);


                if (this->tcp_ctrl->client_msg_rvcd){
                    this->tcp_ctrl->client_msg_rvcd(this->tcp_ctrl, tcp_client,
                                                    client_received_buffer, recv_bytes);
                }

            }
            tcp_client = next_tcp_client;
        }

    }

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

const void TCPClientServiceManager::CopyClientFDToFDSet(fd_set *fdset) {
		for (auto &i:tcp_client_db){
        	FD_SET(i->comm_fd, fdset);
    	}	
	}


const void TCPClientServiceManager::StopTcpClientServiceManagerThread(){
    pthread_cancel(*client_svc_mgr_thread);
    pthread_join(*client_svc_mgr_thread, NULL);
    free(client_svc_mgr_thread);
    client_svc_mgr_thread = NULL;
}
