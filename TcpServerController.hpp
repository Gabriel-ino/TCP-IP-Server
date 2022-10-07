#ifndef TCPSERVERCONTROLLER_HPP
#define TCPSERVERCONTROLLER_HPP

#include <iostream>
#include <stdint.h>
#include <string>
#include <memory>

#include "TcpClientDbManager.hpp"
#include "TcpClientServiceManager.hpp"
#include "TcpNewConnectionAcceptor.hpp"
#include "NetworkUtils.hpp"



class TCPServerController{
	std::shared_ptr<TCPNewConnectionAcceptor> tcp_new_conn_acc = std::make_shared<TCPNewConnectionAcceptor>(this);
	std::shared_ptr<TCPClientDbManager> tcp_client_db_mgr = std::make_shared<TCPClientDbManager>(this);
	std::shared_ptr<TCPClientServiceManager> tcp_client_svc_mgr = std::make_shared<TCPClientServiceManager>(this);

	std::unique_ptr<Utils> network_utils = std::make_unique<Utils>();



	public:
		std::string m_Name;
		uint32_t ip_addr;
		uint16_t port;


		TCPServerController(std::string &ip_addr, uint16_t &port, std::string &name): ip_addr(network_utils->network_p_to_n(ip_addr)), port(port), m_Name(name) {};

		const void Start();
		const void Stop();


	};






#endif
