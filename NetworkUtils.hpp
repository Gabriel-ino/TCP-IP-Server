#ifndef NETWORKUTILS_HPP
#define NETWORKUTILS_HPP

#include <iostream>
#include <arpa/inet.h>
#include <string>
#include <cstring>

class Utils {

    public:
        const uint32_t network_p_to_n(std::string &ip_addr);
        const char* network_n_to_p(uint32_t &ip_addr, char* output_buffer);

};


#endif