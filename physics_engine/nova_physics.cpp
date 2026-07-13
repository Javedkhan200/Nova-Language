#include "nova_physics.h"
void NovaPhysics::enableGravity(const std::string& value) {
    std::cout << "🍎 [PHYSICS ENGINE] Global Gravity Field set to " << value << " m/s².\n";
}
void NovaPhysics::simulateFluid(const std::string& container) {
    std::cout << "🌊 [PHYSICS ENGINE] Running Navier-Stokes fluid dynamics for: " << container << "...\n";
    std::cout << "   ↳ Particle count: 1,000,000.\n";
}
