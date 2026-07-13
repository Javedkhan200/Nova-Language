#ifndef NOVA_QUANTUM_H
#define NOVA_QUANTUM_H
#include <string>
#include <iostream>
class NovaQuantum {
public:
    static void initQubits(const std::string& count);
    static void runSuperposition();
};
#endif
