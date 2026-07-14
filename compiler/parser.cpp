#include "parser.h"
#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}

std::vector<std::unique_ptr<ASTNode>> Parser::parse() {
    std::vector<std::unique_ptr<ASTNode>> ast;
    while (pos < tokens.size()) {
        if (tokens[pos].type == TokenType::IDENTIFIER) {
            std::string id = tokens[pos].value;
            
            if (pos + 2 < tokens.size() && tokens[pos+1].type == TokenType::EQUALS) {
                ast.push_back(std::make_unique<AssignmentNode>(id, tokens[pos+2].value));
                pos += 3;
                continue;
            }
            
            if (id.find("Nova.") == 0) {
                std::string fullCmd = id.substr(5);
                std::string domain = fullCmd, action = "";
                size_t dotPos = fullCmd.find('.');
                if (dotPos != std::string::npos) {
                    domain = fullCmd.substr(0, dotPos);
                    action = fullCmd.substr(dotPos + 1);
                }
                
                std::string arg = "";
                if (pos + 1 < tokens.size() && tokens[pos+1].type == TokenType::STRING) {
                    arg = tokens[pos+1].value;
                    if (!arg.empty() && arg.front() == '"') arg.erase(0, 1);
                    if (!arg.empty() && arg.back() == '"') arg.pop_back();
                    pos += 2;
                } else { pos++; }
                
                ast.push_back(std::make_unique<CommandNode>(domain, action, arg));
            } else {
                throw std::runtime_error("Invalid Syntax. Unknown command: '" + id + "'");
            }
        } 
        else if (tokens[pos].type == TokenType::NUMBER) {
            if (pos + 2 < tokens.size() && tokens[pos+1].type == TokenType::OPERATOR) {
                std::string domain = tokens[pos].value + tokens[pos+1].value;
                std::string action = tokens[pos+2].value;
                ast.push_back(std::make_unique<CommandNode>(domain, action, ""));
                pos += 3;
            } else {
                throw std::runtime_error("Invalid Math Expression.");
            }
        }
        else {
            throw std::runtime_error("Unexpected token encountered.");
        }
    }
    return ast;
}
