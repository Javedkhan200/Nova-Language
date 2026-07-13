#ifndef NOVA_UI_H
#define NOVA_UI_H
#include <string>
#include <iostream>
class NovaUI {
public:
    static void createWindow(const std::string& title);
    static void renderWidget(const std::string& widget);
};
#endif
