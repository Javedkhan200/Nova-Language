#ifndef PY_INTEROP_H
#define PY_INTEROP_H
#include <string>
#include <iostream>

class PythonBridge {
public:
    static void initEmbed();
    static void executeScript(const std::string& script);
    static void pipInstall(const std::string& pkg);
};
#endif
