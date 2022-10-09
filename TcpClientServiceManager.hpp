#ifndef TCPCLIENTSERVICEMANAGER_HPP
#define TCPCLIENTSERVICEMANAGER_HPP

#include "TcpClient.hpp"

class TCPServerController;


class TCPClientServiceManager{

	TCPServerController *tcp_ctrl;

	public:
		TCPClientServiceManager(TCPServerController *tcp_ctrl): tcp_ctrl(tcp_ctrl){};

		const void StartTcpClientServiceManagerThread();
		const void ClientFDStartListen(TCPClient *tcp_client);
};



#endif
