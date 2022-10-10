#ifndef TCPCLIENTDBMANAGER_HPP
#define TCPCLIENTDBMANAGER_HPP

#include <vector>

class TCPClient;
#include "TcpClient.hpp"

class TCPServerController;


class TCPClientDbManager{


	std::vector<TCPClient *> tcp_client_db;

	public:
		TCPServerController *tcp_ctrl;
		TCPClientDbManager(TCPServerController *tcp_ctrl): tcp_ctrl(tcp_ctrl) {};

		const void StartDbManager();
		const void AddClientToDb(TCPClient *tcp_client);
		const void DisplayClientDb();

};




#endif
