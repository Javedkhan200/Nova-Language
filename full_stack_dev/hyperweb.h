#ifndef HYPERWEB_H
#define HYPERWEB_H
#include <string>
#include <iostream>

class HyperWebEngine {
public:
    static void initProject(const std::string& name);
    static void applyTheme(const std::string& theme);
    static void addUIElement(const std::string& type, const std::string& value);
    static void deployApp(const std::string& target);
};
#endif
