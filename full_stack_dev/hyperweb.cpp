#include "hyperweb.h"
#include "../runtime/ffi.h"

void HyperWebEngine::initProject(const std::string& name) {
    std::cout << "📦 [NOVA HYPERWEB] Initializing workspace: " << name << "...\n";
    std::cout << "   ↳ [Virtual DOM] Framework ready.\n";
}

void HyperWebEngine::applyTheme(const std::string& theme) {
    std::cout << "🎨 [UI/UX] Theme injected: " << theme << "\n";
    std::cout << "   ↳ [CSS Engine] Compiling styles...\n";
}

void HyperWebEngine::addUIElement(const std::string& type, const std::string& value) {
    if (type == "button") std::cout << "🔘 [UI/UX] Appended Button component: [" << value << "]\n";
    else if (type == "text_box") std::cout << "📝 [UI/UX] Appended TextBox component: " << value << "\n";
    else if (type == "title") std::cout << "🏷️  [UI/UX] Set DOM Title: " << value << "\n";
    else if (type == "image") std::cout << "🖼️  [UI/UX] Loaded Static Asset: " << value << "\n";
    else if (type == "link") std::cout << "🔗 [UI/UX] Created Router Link: " << value << "\n";
}

void HyperWebEngine::deployApp(const std::string& target) {
    std::cout << "☁️  [DEPLOY] Packaging and compiling for " << target << "...\n";
    std::cout << "   ↳ [Build Tools] Minifying assets and generating APK/IPA/Web Bundle.\n";
    FFI_Bridge::executeJS("deployToCloud('" + target + "')");
}
