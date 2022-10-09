#ifndef TCPCLIENT_HPP
#define TCPCLIENT_HPP

#include <iostream>

class TCPServerController;
#include "TcpServerController.hpp"

class TCPClient {


    public:
        uint32_t ip_addr;
        uint16_t port_no;
        int comm_fd;
        TCPServerController *tcp_ctrl;

        TCPClient(uint32_t ip_addr, uint16_t port_no): ip_addr(ip_addr), port_no(port_no){} 

};


#endif

