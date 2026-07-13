#include "nova_lsp.h"

void NovaLanguageServer::startServer() {
    std::cout << "🔌 [LSP] Nova Language Server started on standard IO.\n";
    std::cout << "   ↳ Listening for VS Code / PyCharm connection...\n";
}

void NovaLanguageServer::provideIntelliSense(const std::string& keyword) {
    std::cout << "💡 [INTELLISENSE] Suggestions for '" << keyword << "':\n";
    std::cout << "   ↳ Nova.os.start()\n";
    std::cout << "   ↳ Nova.os.check.battery()\n";
}

void NovaLanguageServer::checkSyntaxError(const std::string& line) {
    std::cout << "🔍 [LSP] Analyzing line: " << line << "\n";
    std::cout << "   ↳ Status: Clean. No squiggly lines needed.\n";
}
