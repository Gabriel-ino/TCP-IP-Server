#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory>

const uint16_t DEST_PORT = 40000;
#define SERVER_IP_ADDR "127.0.0.1"

const uint16_t SRC_PORT = 40001;
#define LOCAL_IP_ADDRESS "127.0.0.1"


typedef struct _test_struct{
	unsigned int a;
	unsigned int b;

}test_struct_t;

typedef struct result_struct_{

	unsigned int c;
}result_struct_t;


static test_struct_t client_data;
static result_struct_t result;

const void setup_tcp_communication(){
	int sockfd{};
	int sent_recv_bytes{};

	socklen_t addr_len{0};

	addr_len = sizeof(struct sockaddr);

	struct sockaddr_in dest;

	dest.sin_family = AF_INET;

	dest.sin_port = htons(DEST_PORT);

	struct hostent *host = (struct hostent *)gethostbyname(SERVER_IP_ADDR);
	
	dest.sin_addr = *((struct in_addr *)host->h_addr);

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	std::cout << "Connecting to server...\n";

	int rc = connect(sockfd, (struct sockaddr *)&dest, sizeof(struct sockaddr));

	switch(rc){
		case 0:
			std::cout << "Connected!\n";
			break;
		default:
			std::cout << "Connection Failed, err: " << errno;
			exit(0);
	}

  while (1){
	std::cout << "Enter A:\n";
	try{
		std::cin >>  client_data.a;

	}catch(std::invalid_argument& e){
		std::cerr << e.what() << '\n';
		exit(-1);
	}

	std::cout << "Enter B:\n";
	try{
		std::cin >> client_data.b;
	}catch (std::invalid_argument& e){
		std::cerr << e.what() << '\n';
		exit(-1);
	}


	if (!client_data.a && !client_data.b){
		std::cout << "Closing Connection...\n";
		close(sockfd);
		exit(0);
	}

	sent_recv_bytes = sendto(sockfd, &client_data, sizeof(test_struct_t),
			         0, (struct sockaddr *)&dest, sizeof(struct sockaddr));

	std::cout << "Number of bytes sent: " << sent_recv_bytes << '\n';

	std::cout << "Waiting response...\n";

	sent_recv_bytes = recvfrom(sockfd, (char *)&result, sizeof(result_struct_t), 0, (struct sockaddr *)&dest, &addr_len);

	std::cout << "Number of bytes received: " << sent_recv_bytes << '\n';

	std::cout << "Information received: " << result.c << '\n';

  }

}



inline void removeBlankSpaces(std::string &m_str){
    m_str.erase(std::remove(m_str.begin(), m_str.end(), ' '), m_str.end());
}


int main(int argc, char** argv){

	std::string ip_addr;
	std::uint32_t port_no;

    if (argc < 3){
        throw std::invalid_argument("Follow the structure to invoke this program corretly:<software executable> <ip_address> <port_number>");
    }

    try{
        ip_addr = argv[1];
        port_no = std::stoi(argv[2]);
        removeBlankSpaces(ip_addr);
    }catch (std::exception &Exception){
        throw("An error ocurred");

    }
 
    setup_tcp_communication();
    std::cout << "Bye!\n";

    return 0;
}

