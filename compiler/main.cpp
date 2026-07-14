#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "parser.h"
#include "bytecode.h"
#include "../runtime/vm.h"

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

        try {
            Lexer lexer(line);
            auto tokens = lexer.tokenize();
            if(tokens.empty()) continue;
            Parser parser(tokens);
            auto ast = parser.parse();
            vm.execute(ast);
        } catch (const std::exception& e) {
            std::cout << "❌ SyntaxError: " << e.what() << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) { runREPL(); return 0; }
    
    std::ifstream file(argv[1]);
    if (!file.is_open()) { std::cout << "❌ Error: File not found.\n"; return 1; }
    std::stringstream buffer; buffer << file.rdbuf();
    
    try {
        Lexer lexer(buffer.str());
        Parser parser(lexer.tokenize());
        auto ast = parser.parse();
        VirtualMachine vm;
        vm.execute(ast);
    } catch (const std::exception& e) {
        std::cout << "❌ Fatal SyntaxError: " << e.what() << "\n";
    }
    return 0;
}
