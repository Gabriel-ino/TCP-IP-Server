#ifndef TCPNEWCONNECTIONACCEPTOR_HPP
#define TCPNEWCONNECTIONACCEPTOR_HPP

#include <memory>

class TCPServerController;


class TCPNewConnectionAcceptor{

    TCPServerController *tcp_ctrl;

    public:
        TCPNewConnectionAcceptor(TCPServerController *tcp_ctrl): tcp_ctrl(tcp_ctrl) {}
        const void StartTCPNewAcceptorThread();


};

#endif
