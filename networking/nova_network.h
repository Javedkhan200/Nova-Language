#ifndef NOVA_NETWORK_H
#define NOVA_NETWORK_H
#include <string>
#include <iostream>

class NovaNetwork {
public:
    static void connectWifi(const std::string& ssid);
    static void pingServer(const std::string& ip);
    static void startServer(const std::string& port);
    static void sendData(const std::string& data);
};
#endif
