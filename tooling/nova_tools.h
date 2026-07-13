#ifndef NOVA_TOOLS_H
#define NOVA_TOOLS_H
#include <string>
#include <iostream>

class NovaTools {
public:
    static void runLinter();
    static void formatCode(const std::string& file);
    static void startDebugger();
    static void generateDocs();
};
#endif
