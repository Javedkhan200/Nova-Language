#include "parser.h"

Parser::Parser(const std::vector<Token>& t) : tokens(t), pos(0) {}

Token Parser::peek(int offset) {
    if (pos + offset >= tokens.size()) return tokens.back();
    return tokens[pos + offset];
}

Token Parser::advance() {
    if (pos >= tokens.size()) return tokens.back();
    return tokens[pos++];
}

std::unique_ptr<ASTNode> Parser::parseStatement() {
    if (peek().value == "Nova" && peek(1).type == TokenType::DOT) {
        advance(); advance(); 
        std::string domain = advance().value;
        std::string action = "";
        while (peek().type == TokenType::DOT) {
            advance();
            action += advance().value;
            if (peek().type == TokenType::DOT) action += ".";
        }
        std::string arg = "";
        if (peek().type == TokenType::LPAREN) {
            advance(); 
            while (peek().type != TokenType::RPAREN && peek().type != TokenType::END_OF_FILE) {
                arg += advance().value;
            }
            if (peek().type == TokenType::RPAREN) advance();
        }
        
        // Handle Nova.define (Custom Functions)
        if (domain == "define" && peek().type == TokenType::LBRACE) {
            advance(); // Skip '{'
            auto funcNode = std::make_unique<FunctionNode>(arg);
            while (peek().type != TokenType::RBRACE && peek().type != TokenType::END_OF_FILE) {
                if (auto stmt = parseStatement()) {
                    funcNode->body.push_back(std::move(stmt));
                } else advance();
            }
            if (peek().type == TokenType::RBRACE) advance(); // Skip '}'
            return funcNode;
        }
        return std::make_unique<CommandNode>(domain, action, arg);
    } 
    else if (peek().type == TokenType::IDENTIFIER && peek(1).type == TokenType::ASSIGN) {
        std::string varName = advance().value;
        advance(); 
        std::string value = advance().value;
        return std::make_unique<AssignmentNode>(varName, value);
    }
    return nullptr;
}

std::vector<std::unique_ptr<ASTNode>> Parser::parse() {
    std::vector<std::unique_ptr<ASTNode>> statements;
    while (peek().type != TokenType::END_OF_FILE) {
        if (auto stmt = parseStatement()) statements.push_back(std::move(stmt));
        else advance();
    }
    return statements;
}
