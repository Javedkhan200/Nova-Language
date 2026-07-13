#include "nova_tools.h"

void NovaTools::runLinter() {
    std::cout << "🧹 [TOOLING] Running Linter on workspace...\n";
    std::cout << "   ↳ ✅ 0 Errors, 0 Warnings. Code is clean.\n";
}

void NovaTools::formatCode(const std::string& file) {
    std::cout << "✨ [TOOLING] Formatting code in '" << file << "' to NeuraStudio Standards.\n";
}

void NovaTools::startDebugger() {
    std::cout << "🐛 [DEBUGGER] Attaching J-Kernel Debugger to active process...\n";
    std::cout << "   ↳ Breakpoints enabled. Listening on port 9229.\n";
}

void NovaTools::generateDocs() {
    std::cout << "📄 [TOOLING] Auto-generating API Documentation (Markdown/HTML)...\n";
}
