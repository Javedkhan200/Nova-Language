#ifndef NOVA_FINANCE_H
#define NOVA_FINANCE_H
#include <string>
#include <iostream>

class NovaFinance {
public:
    static void createWallet(const std::string& name);
    static void checkBalance();
    static void sendTransaction(const std::string& amount);
    static void convertCurrency(const std::string& from, const std::string& to);
    static void calculateTax(const std::string& rate);
};
#endif
