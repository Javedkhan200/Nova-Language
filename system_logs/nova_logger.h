#ifndef NOVA_LOGGER_H
#define NOVA_LOGGER_H
#include <string>
#include <fstream>
#include <iostream>

class NovaLogger {
public:
    static void logEvent(const std::string& level, const std::string& message);
};
#endif
