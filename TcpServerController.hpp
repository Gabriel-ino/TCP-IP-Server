#ifndef TCPSERVERCONTROLLER_HPP
#define TCPSERVERCONTROLLER_HPP

#include <iostream>
#include <stdint.h>
#include <string>
#include <memory>

class TCPClientDbManager;
#include "TcpClientDbManager.hpp"

class TCPClientServiceManager;
#include "TcpClientServiceManager.hpp"

class TCPNewConnectionAcceptor;
#include "TcpNewConnectionAcceptor.hpp"
#include "NetworkUtils.hpp"



class TCPServerController{
	std::shared_ptr<TCPNewConnectionAcceptor> tcp_new_conn_acc = std::make_shared<TCPNewConnectionAcceptor>(this);
	std::shared_ptr<TCPClientDbManager> tcp_client_db_mgr = std::make_shared<TCPClientDbManager>(this);
	std::shared_ptr<TCPClientServiceManager> tcp_client_svc_mgr = std::make_shared<TCPClientServiceManager>(this);

	protected:
		std::unique_ptr<Utils> network_utils = std::make_unique<Utils>();



	public:
		std::string m_Name;
		uint32_t ip_addr;
		uint16_t port;


		TCPServerController(std::string &ip_addr, uint16_t &port, std::string &name): ip_addr(network_utils->network_p_to_n(ip_addr)), port(port), m_Name(name) {};

		const void Start();
		const void Stop();

		void(*client_connected)(const TCPServerController *, const TCPClient *);
		void(*client_disconnected)(const TCPServerController *, const TCPClient *);
		void (*client_msg_rvcd)(const TCPServerController *, const TCPClient *, unsigned char*, uint16_t);


		const void SetServerNotifyCallbacks(
			void(*client_connected)(const TCPServerController *, const TCPClient *),
			void(*client_disconnected)(const TCPServerController *, const TCPClient *),
			void (*client_msg_rvcd)(const TCPServerController *, const TCPClient *, unsigned char*, uint16_t)
		);

		const void ProcessNewClient(TCPClient *tcp_client);

		const void Display();


	};


#endif
