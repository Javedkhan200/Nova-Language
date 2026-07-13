#include "bytecode.h"
#include <iostream>
#include <fstream>

void BytecodeCompiler::emit(OpCode op, std::string a1, std::string a2) {
    instructions.push_back({op, a1, a2});
}

void BytecodeCompiler::compile(const std::vector<std::unique_ptr<ASTNode>>& ast) {
    for (const auto& node : ast) {
        if (auto* assign = dynamic_cast<AssignmentNode*>(node.get())) {
            emit(OpCode::STORE_VAR, assign->varName, assign->value);
        }
        else if (auto* cmd = dynamic_cast<CommandNode*>(node.get())) {
            if (cmd->domain == "show") {
                // Simplified math check for compiler
                if (cmd->argument.find('+') != std::string::npos || cmd->argument.find('-') != std::string::npos) {
                    emit(OpCode::CALL_MATH, "EVAL", cmd->argument);
                } else {
                    emit(OpCode::PRINT_OUT, cmd->argument);
                }
            }
            else if (cmd->domain == "os") emit(OpCode::CALL_OS, cmd->action, cmd->argument);
            else if (cmd->domain == "hardware") emit(OpCode::CALL_HW, cmd->action, cmd->argument);
            else if (cmd->domain == "ai") emit(OpCode::CALL_AI, cmd->action, cmd->argument);
            else if (cmd->domain == "robot") emit(OpCode::CALL_ROBOT, cmd->action, cmd->argument);
            else if (cmd->domain == "app" || cmd->domain == "web") emit(OpCode::CALL_WEB, cmd->action, cmd->argument);
        }
    }
    emit(OpCode::HALT);
}

void BytecodeCompiler::printBytecode() {
    std::cout << "\n==========================================\n";
    std::cout << " 🛠️  NOVA BYTECODE (.nbc) GENERATED\n";
    std::cout << "==========================================\n";
    for (size_t i = 0; i < instructions.size(); i++) {
        std::cout << "[" << i << "] ";
        switch (instructions[i].op) {
            case OpCode::LOAD_VAL: std::cout << "LOAD_VAL    "; break;
            case OpCode::STORE_VAR: std::cout << "STORE_VAR   "; break;
            case OpCode::CALL_MATH: std::cout << "CALL_MATH   "; break;
            case OpCode::CALL_OS: std::cout << "CALL_OS     "; break;
            case OpCode::CALL_HW: std::cout << "CALL_HW     "; break;
            case OpCode::CALL_AI: std::cout << "CALL_AI     "; break;
            case OpCode::CALL_ROBOT: std::cout << "CALL_ROBOT  "; break;
            case OpCode::CALL_WEB: std::cout << "CALL_WEB    "; break;
            case OpCode::PRINT_OUT: std::cout << "PRINT_OUT   "; break;
            case OpCode::HALT: std::cout << "HALT        "; break;
        }
        std::cout << " | " << instructions[i].arg1 << " | " << instructions[i].arg2 << "\n";
    }
    std::cout << "==========================================\n\n";
}

void BytecodeCompiler::saveToFile(const std::string& filename) {
    std::ofstream out(filename + ".nbc");
    for (const auto& inst : instructions) {
        out << (int)inst.op << " " << inst.arg1 << " " << inst.arg2 << "\n";
    }
    out.close();
    std::cout << "✅ Compiled successfully to: " << filename << ".nbc\n";
}
