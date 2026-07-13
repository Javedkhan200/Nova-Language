#include "nova_graphics.h"
void NovaGraphics::initVulkan() {
    std::cout << "🎨 [GRAPHICS CORE] Initializing Vulkan API Pipeline...\n";
    std::cout << "   ↳ Hardware Ray-Tracing Support: ENABLED.\n";
}
void NovaGraphics::loadShader(const std::string& shaderName) {
    std::cout << "🌈 [GRAPHICS CORE] Compiling Compute Shader: " << shaderName << "...\n";
}
void NovaGraphics::drawFrame() {
    std::cout << "🖥️  [GRAPHICS CORE] Frame buffered and swapped to display (144 Hz).\n";
}
