#ifndef NOVA_WEB3_H
#define NOVA_WEB3_H
#include <string>
#include <iostream>

class NovaWeb3 {
public:
    static void startNode();
    static void deployContract(const std::string& name);
    static void connectWallet(const std::string& provider);
    static void mintNFT(const std::string& artName);
};
#endif
