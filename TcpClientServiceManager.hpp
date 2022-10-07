#ifndef TCPCLIENTSERVICEMANAGER_HPP
#define TCPCLIENTSERVICEMANAGER_HPP

class TCPServerController;


class TCPClientServiceManager{

	TCPServerController *tcp_ctrl;

	public:
		TCPClientServiceManager(TCPServerController *tcp_ctrl): tcp_ctrl(tcp_ctrl){};

		const void StartTcpClientServiceManagerThread();
};



#endif
