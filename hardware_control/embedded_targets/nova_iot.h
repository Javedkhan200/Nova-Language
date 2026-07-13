#ifndef NOVA_IOT_H
#define NOVA_IOT_H
#include <string>
#include <iostream>
class NovaIoT {
public:
    static void flashFirmware(const std::string& target);
    static void toggleGPIO(const std::string& pin, const std::string& state);
};
#endif
