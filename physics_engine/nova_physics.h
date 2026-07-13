#ifndef NOVA_PHYSICS_H
#define NOVA_PHYSICS_H
#include <string>
#include <iostream>
class NovaPhysics {
public:
    static void enableGravity(const std::string& value);
    static void simulateFluid(const std::string& container);
};
#endif
