#include "NetworkUtils.hpp"



const uint32_t Utils::network_p_to_n(std::string &ip_addr){
    const char *c = ip_addr.c_str();
    uint32_t binary_prefix{};

    inet_pton(AF_INET, c, &binary_prefix);
    binary_prefix = htonl(binary_prefix);

    return binary_prefix;
    
}

const char* Utils::network_n_to_p(uint32_t &ip_addr, char *output_buffer){

    char *out = NULL;
    static char str_ip[16];
    out = !output_buffer ? str_ip : output_buffer;
    memset(out, 0, 16);

    ip_addr = htonl(ip_addr);
    inet_ntop(AF_INET, &ip_addr, out, 16);
    out[15] = '\0';

    return out;

}
