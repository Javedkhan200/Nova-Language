#ifndef J_KERNEL_H
#define J_KERNEL_H
#include <string>
#include <iostream>

class JKernel {
public:
    static void bootSystem(const std::string& osName);
    static void checkBattery();
    static void scanHardware(const std::string& target);
    static void setCpuOverclock(const std::string& state);
};
#endif
