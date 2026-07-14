#include "parser.h"
#include <stdexcept>
#include <iostream>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}

std::vector<std::unique_ptr<ASTNode>> Parser::parse() {
    std::vector<std::unique_ptr<ASTNode>> ast;
    while (pos < tokens.size()) {
        if (tokens[pos].type == TokenType::IDENTIFIER) {
            std::string id = tokens[pos].value;

            // Variable Assignment (A = 7)
            if (pos + 2 < tokens.size() && tokens[pos+1].type == TokenType::EQUALS) {
                ast.push_back(std::make_unique<AssignmentNode>(id, tokens[pos+2].value));
                pos += 3;
                continue;
            }

            // Nova Commands
            if (id.find("Nova.") == 0) {
                std::string fullCmd = id.substr(5);
                std::string domain = fullCmd, action = "";
                size_t dotPos = fullCmd.find('.');
                if (dotPos != std::string::npos) {
                    domain = fullCmd.substr(0, dotPos);
                    action = fullCmd.substr(dotPos + 1);
                }

                std::string arg = "";
                if (pos + 1 < tokens.size()) {
                    if (tokens[pos+1].type == TokenType::STRING) {
                        arg = tokens[pos+1].value;
                        if (!arg.empty() && arg.front() == '"') arg.erase(0, 1);
                        if (!arg.empty() && arg.back() == '"') arg.pop_back();
                    } else if (tokens[pos+1].type == TokenType::IDENTIFIER || tokens[pos+1].type == TokenType::NUMBER) {
                        arg = tokens[pos+1].value;
                    }
                    // Handle math inside arguments like A+B
                    if (pos + 3 < tokens.size() && tokens[pos+2].type == TokenType::OPERATOR) {
                        arg += tokens[pos+2].value + tokens[pos+3].value;
                        pos += 2;
                    }
                    pos += 2;
                } else { pos++; }

                ast.push_back(std::make_unique<CommandNode>(domain, action, arg));
            } else {
                throw std::runtime_error("SyntaxError: Unknown command '" + id + "'");
            }
        }
        else if (tokens[pos].type == TokenType::NUMBER) {
            if (pos + 2 < tokens.size() && tokens[pos+1].type == TokenType::OPERATOR) {
                std::string domain = "math_calc";
                std::string arg = tokens[pos].value + tokens[pos+1].value + tokens[pos+2].value;
                ast.push_back(std::make_unique<CommandNode>(domain, "", arg));
                pos += 3;
            } else { throw std::runtime_error("Invalid Math Expression."); }
        }
        else { throw std::runtime_error("Unexpected token."); }
    }
    return ast;
}
