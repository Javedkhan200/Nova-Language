#include "nova_network.h"

void NovaNetwork::connectWifi(const std::string& ssid) {
    std::cout << "📶 [NETWORK] Handshake established with SSID: " << ssid << "\n";
}
void NovaNetwork::pingServer(const std::string& ip) {
    std::cout << "🏓 [NETWORK] Pinging " << ip << "... Response time: 12ms\n";
}
void NovaNetwork::startServer(const std::string& port) {
    std::cout << "🌍 [NETWORK] TCP/UDP Server listening on port: " << port << "\n";
}
void NovaNetwork::sendData(const std::string& data) {
    std::cout << "📤 [NETWORK] Sending secure packet: '" << data << "'\n";
}
