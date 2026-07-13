#ifndef NOVA_HEALTH_H
#define NOVA_HEALTH_H
#include <string>
#include <iostream>

class NovaHealth {
public:
    static void scanVitals();
    static void analyzeDNA(const std::string& sample);
    static void trackCalories(const std::string& amount);
    static void monitorSleep(const std::string& state);
    static void emergencyAlert();
};
#endif
