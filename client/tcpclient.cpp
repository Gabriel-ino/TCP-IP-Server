#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

#include <memory>

#include "TcpServerController.hpp"

inline void removeBlankSpaces(std::string &m_str){
    m_str.erase(std::remove(m_str.begin(), m_str.end(), ' '), m_str.end());
}


int main(int argc, char** argv){
    std::string ip_addr;
    uint16_t port_no;


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

    std::string nameConnection = "TCP Connection";

   TCPServerController *tcpserver = new TCPServerController(ip_addr, port_no, nameConnection);
   tcpserver->Start();
   std::cin.get();

   std::cout << "Closing Connection...";
   tcpserver->Stop();

   delete tcpserver;





    return 0;
}

