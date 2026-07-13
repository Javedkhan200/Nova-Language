#ifndef NOVA_LSP_H
#define NOVA_LSP_H
#include <string>
#include <iostream>

class NovaLanguageServer {
public:
    static void startServer();
    static void provideIntelliSense(const std::string& keyword);
    static void checkSyntaxError(const std::string& line);
};
#endif
