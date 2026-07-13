#ifndef NOVA_SECURITY_H
#define NOVA_SECURITY_H
#include <string>
#include <iostream>

class NovaSecurity {
public:
    static void startFirewall();
    static void scanNetwork(const std::string& target);
    static void blockIP(const std::string& ip);
    static void encryptFile(const std::string& file);
    static void enableSandbox();
    static void runAudit();
};
#endif
