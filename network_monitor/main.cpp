#include <iostream>
#include "network.h"
#include "utils.h"
int main() {
    std::cout << "=== Network Monitor ===" << std::endl;
    printSystemInfo();
    TCPConnection conn("192.168.1.1", 8080);
    conn.displayInfo();
    std::cout << "Program completed successfully!" << std::endl;
    return 0;
}
