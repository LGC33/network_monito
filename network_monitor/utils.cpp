#include "utils.h"
#include <iostream>
#include <cstring>
bool isValidIP(const char* ip) {
    return strlen(ip) > 0;
}
void printSystemInfo() {
    std::cout << "Network Monitor v1.0" << std::endl;
}
