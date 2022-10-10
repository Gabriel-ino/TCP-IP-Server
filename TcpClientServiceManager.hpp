#ifndef TCPCLIENTSERVICEMANAGER_HPP
#define TCPCLIENTSERVICEMANAGER_HPP

#include "TcpClient.hpp"
#include <vector>

class TCPServerController;


class TCPClientServiceManager{

	int max_fd{};
	fd_set active_fd_set;
	fd_set backup_fd_set;

	pthread_t *client_svc_mgr_thread;


	TCPServerController *tcp_ctrl;
	std::vector<TCPClient *>tcp_client_db;

	public:
		TCPClientServiceManager(TCPServerController *tcp_ctrl): tcp_ctrl(tcp_ctrl){
			FD_ZERO(&active_fd_set);
			FD_ZERO(&backup_fd_set);
			client_svc_mgr_thread = (pthread_t *)calloc(1, sizeof(pthread_t));
		};

		const void StartTcpClientServiceManagerThread();
		const void StartTcpClientServiceManagerThreadInternal();
		const void ClientFDStartListen(TCPClient *tcp_client);
};



#endif
