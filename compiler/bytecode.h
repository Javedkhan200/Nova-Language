#ifndef BYTECODE_H
#define BYTECODE_H
#include "parser.h"
#include <vector>
#include <string>

// NeuraStudio Proprietary OPCodes
enum class OpCode {
    LOAD_VAL,       // Load string/number
    STORE_VAR,      // Store in memory
    CALL_MATH,      // ALU Operations
    CALL_OS,        // J-Kernel Operations
    CALL_HW,        // Hardware Operations
    CALL_AI,        // NeuraBrain Operations
    CALL_ROBOT,     // Robotics Operations
    CALL_WEB,       // HyperWeb Operations
    PRINT_OUT,      // Show on screen
    HALT            // End of execution
};

struct Instruction {
    OpCode op;
    std::string arg1;
    std::string arg2;
};

class BytecodeCompiler {
public:
    std::vector<Instruction> instructions;
    void emit(OpCode op, std::string a1 = "", std::string a2 = "");
    void compile(const std::vector<std::unique_ptr<ASTNode>>& ast);
    void printBytecode();
    void saveToFile(const std::string& filename);
};
#endif
