#ifndef NOVA_TEST_H
#define NOVA_TEST_H
#include <string>
#include <iostream>

class NovaTest {
public:
    static void runUnitTests();
    static void runE2ETests();
    static void assertEqual(const std::string& expected, const std::string& actual);
};
#endif
