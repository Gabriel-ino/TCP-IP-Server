#ifndef TCPCLIENT_HPP
#define TCPCLIENT_HPP

#include <iostream>

class TCPServerController;
#include "TcpServerController.hpp"
#include <arpa/inet.h>
#include "NetworkUtils.hpp"


class TCPClient {

    std::unique_ptr<Utils> network_utils = std::make_unique<Utils>();

    public:
        uint32_t ip_addr;
        uint16_t port_no;
        int comm_fd;
        TCPServerController *tcp_ctrl;

        TCPClient(uint32_t &ip_addr, uint16_t &port_no): ip_addr(ip_addr), port_no(port_no){} 

    inline void Display() const{
        uint32_t ipval = htonl(ip_addr);
        std::cout << "TCP Client: [" << network_utils->network_n_to_p(ipval, 0) << ", " << this->port_no << '\n';
    }


};


#endif

