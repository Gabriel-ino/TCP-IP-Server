#include "TcpServerController.hpp"
#include <string>


int main(int argc, char** argv){
    uint16_t PORT = 4000;
    std::string ip = "127.0.0.1";
    std::string name = "Default TCP Server";

    TCPServerController *server = new TCPServerController(ip, PORT, name);
    server->Start();
    std::cout << "Server connection has started\n";
    std::cin.get();
    std::cout << "Closing server connection...\n";
    server->Stop();


    return 0;
}



