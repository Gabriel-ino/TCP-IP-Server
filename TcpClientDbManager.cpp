#include "TcpClientDbManager.hpp"


const void TCPClientDbManager::StartDbManager(){
    
}


const void TCPClientDbManager::AddClientToDb(TCPClient *tcp_client){
    tcp_client_db.push_back(tcp_client);
}

const void TCPClientDbManager::DisplayClientDb(){
    for (auto &i:tcp_client_db){
        i->Display();

    }

}



