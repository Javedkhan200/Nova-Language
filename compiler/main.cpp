#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "parser.h"
#include "bytecode.h"
#include "../runtime/vm.h"
#include "../system_logs/nova_logger.h"

void runREPL() {
    std::cout << "Nova 1.0.0 (default, Jul 13 2026, 13:42:07) [Clang C++17] on termux\n";
    std::cout << "Type \"help\", \"copyright\", or \"exit\" for more information.\n";
    VirtualMachine vm;
    std::string line;
    while (true) {
        std::cout << ">>> ";
        if (!std::getline(std::cin, line)) break;
        if (line == "exit" || line == "quit") break;
        if (line.empty()) continue;

        NovaLogger::logEvent("REPL", "Executed command: " + line);
        Lexer lexer(line);
        Parser parser(lexer.tokenize());
        auto ast = parser.parse();
        vm.execute(ast);
    }
}

int main(int argc, char* argv[]) {
    NovaLogger::logEvent("SYSTEM", "Nova Engine Boot Sequence Initiated.");
    
    if (argc < 2) {
        runREPL();
        return 0;
    }

    std::string command = argv[1];
    
    // COMPILER MODE: Generate .nbc file
    if (command == "build" && argc == 3) {
        NovaLogger::logEvent("COMPILER", "Building bytecode for: " + std::string(argv[2]));
        std::ifstream file(argv[2]);
        if (!file.is_open()) return 1;
        std::stringstream buffer; buffer << file.rdbuf();
        
        Lexer lexer(buffer.str());
        Parser parser(lexer.tokenize());
        auto ast = parser.parse();
        
        BytecodeCompiler bcc;
        bcc.compile(ast);
        bcc.printBytecode();
        
        std::string outName = argv[2];
        outName = outName.substr(0, outName.find_last_of(".")); 
        bcc.saveToFile(outName);
        NovaLogger::logEvent("COMPILER", "Bytecode build successful.");
        return 0;
    }

    // RUN MODE: Execute file directly
    NovaLogger::logEvent("EXECUTION", "Running script: " + std::string(argv[1]));
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "❌ Error: File not found.\n";
        NovaLogger::logEvent("ERROR", "File not found: " + std::string(argv[1]));
        return 1;
    }
    std::stringstream buffer; buffer << file.rdbuf();
    
    Lexer lexer(buffer.str());
    Parser parser(lexer.tokenize());
    auto ast = parser.parse();

    VirtualMachine vm;
    std::cout << "--- STARTING NOVA EXECUTION ---\n";
    vm.execute(ast);
    std::cout << "--- EXECUTION FINISHED ---\n";
    NovaLogger::logEvent("SYSTEM", "Nova Engine Shutdown gracefully.");
    return 0;
}
