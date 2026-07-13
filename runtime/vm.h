#ifndef VM_H
#define VM_H
#include "../compiler/parser.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

class VirtualMachine {
public:
    std::unordered_map<std::string, std::string> memory;
    // Store Functions in memory too!
    std::unordered_map<std::string, FunctionNode*> functions; 
    
    void execute(const std::vector<std::unique_ptr<ASTNode>>& ast);
private:
    void executeNode(ASTNode* node); 
};
#endif
