#include "nova_iot.h"
void NovaIoT::flashFirmware(const std::string& target) {
    std::cout << "⚙️  [IoT KERNEL] Flashing bytecode firmware to " << target << "...\n";
    std::cout << "   ↳ Flash successful. Device rebooting.\n";
}
void NovaIoT::toggleGPIO(const std::string& pin, const std::string& state) {
    std::cout << "🔌 [HARDWARE] GPIO Pin " << pin << " set to " << state << ".\n";
}
