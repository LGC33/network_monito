#ifndef NETWORK_H
#define NETWORK_H
class NetworkConnection {
public:
    virtual ~NetworkConnection() {}
    virtual void displayInfo() const = 0;
};
class TCPConnection : public NetworkConnection {
public:
    TCPConnection(const char* ip, int port);
    void displayInfo() const override;
private:
    char* ipAddress;
    int port;
};
#endif
