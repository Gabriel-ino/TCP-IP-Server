#ifndef TCPNEWCONNECTIONACCEPTOR_HPP
#define TCPNEWCONNECTIONACCEPTOR_HPP

#include <arpa/inet.h>
#include <netinet/in.h>

#include <iostream>
#include <pthread.h>
#include <memory>
#include <stdexcept>

class TCPServerController;

#include "TcpServerController.hpp"

class TCPNewConnectionAcceptor{

    TCPServerController *tcp_ctrl;
    int accept_fd;

    pthread_t *startNewConnectionThread;

    public:
        TCPNewConnectionAcceptor(TCPServerController *tcp_ctrl): tcp_ctrl(tcp_ctrl) {
            accept_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (accept_fd < 0){
                throw std::invalid_argument("Connection Refused.");
            }
            startNewConnectionThread = (pthread_t*)calloc(1, sizeof(pthread_t));
        }
        const void StartTCPNewAcceptorThread();
        const void StartTCPNewAcceptorThreadInternal();


};

#endif
