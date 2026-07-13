#ifndef NOVA_GRAPHICS_H
#define NOVA_GRAPHICS_H
#include <string>
#include <iostream>
class NovaGraphics {
public:
    static void initVulkan();
    static void loadShader(const std::string& shaderName);
    static void drawFrame();
};
#endif
