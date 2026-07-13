#ifndef NOVA_PM_H
#define NOVA_PM_H
#include <string>
#include <iostream>

class NovaPackageManager {
public:
    static void installPackage(const std::string& pkgName);
    static void removePackage(const std::string& pkgName);
    static void updateRegistry();
    static void resolveDependencies();
};
#endif
