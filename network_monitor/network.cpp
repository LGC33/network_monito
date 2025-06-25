#include "network.h"
#include <iostream>
#include <cstring>
TCPConnection::TCPConnection(const char* ip, int p) : port(p) {
    ipAddress = new char[strlen(ip) + 1];
    strcpy(ipAddress, ip);
}
void TCPConnection::displayInfo() const {
    std::cout << "TCP Connection: " << ipAddress << ":" << port << std::endl;
}
