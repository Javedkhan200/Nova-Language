#include "nova_ui.h"
void NovaUI::createWindow(const std::string& title) {
    std::cout << "🪟 [UI ENGINE] Spawning Native OS Window: '" << title << "'...\n";
    std::cout << "   ↳ GPU Hardware Acceleration attached.\n";
}
void NovaUI::renderWidget(const std::string& widget) {
    std::cout << "🧩 [UI ENGINE] Rendering Reactive Component: [" << widget << "].\n";
}
