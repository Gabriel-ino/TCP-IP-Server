#ifndef TCPCLIENTSERVICEMANAGER_HPP
#define TCPCLIENTSERVICEMANAGER_HPP

#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <memory>

#include "TcpClient.hpp"

#define TCP_CLIENT_RECV_BUFFER_SIZE 1024
static unsigned char client_received_buffer[TCP_CLIENT_RECV_BUFFER_SIZE];

class TCPServerController;


class TCPClientServiceManager{

	int max_fd{};
	fd_set active_fd_set;
	fd_set backup_fd_set;
	bool hasOnlyOneClient{true};

	pthread_t *client_svc_mgr_thread;


	TCPServerController *tcp_ctrl;
	std::vector<TCPClient *>tcp_client_db;

	const int GetMaxFd();

	const void CopyClientFDToFDSet(fd_set *fdset);

	public:
		TCPClientServiceManager(TCPServerController *tcp_ctrl): tcp_ctrl(tcp_ctrl){
			FD_ZERO(&active_fd_set);
			FD_ZERO(&backup_fd_set);
			this->client_svc_mgr_thread = (pthread_t *)calloc(1, sizeof(pthread_t));
		};

		const void StartTcpClientServiceManagerThread();
		const void StopTcpClientServiceManagerThread();
		const void StartTcpClientServiceManagerThreadInternal();
		const void ClientFDStartListen(TCPClient *tcp_client);
		const void AddClientToDB(TCPClient *);
};



#endif
