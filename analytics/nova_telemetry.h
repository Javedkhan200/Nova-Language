#ifndef NOVA_TELEMETRY_H
#define NOVA_TELEMETRY_H
#include <string>
#include <iostream>

class NovaTelemetry {
public:
    static void logCrash(const std::string& error);
    static void trackPerformance();
};
#endif
