#ifndef TCPCLIENTSERVICEMANAGER_HPP
#define TCPCLIENTSERVICEMANAGER_HPP

#include "TcpClient.hpp"
#include <vector>

class TCPServerController;


class TCPClientServiceManager{

	TCPServerController *tcp_ctrl;
	std::vector<TCPClient *>tcp_client_db;

	public:
		TCPClientServiceManager(TCPServerController *tcp_ctrl): tcp_ctrl(tcp_ctrl){};

		const void StartTcpClientServiceManagerThread();
		const void ClientFDStartListen(TCPClient *tcp_client);
};



#endif
