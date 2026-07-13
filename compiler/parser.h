#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print() const = 0;
};

class CommandNode : public ASTNode {
public:
    std::string domain, action, argument;
    CommandNode(std::string d, std::string a, std::string arg) : domain(d), action(a), argument(arg) {}
    void print() const override {}
};

class AssignmentNode : public ASTNode {
public:
    std::string varName, value;
    AssignmentNode(std::string var, std::string val) : varName(var), value(val) {}
    void print() const override {}
};

class FunctionNode : public ASTNode {
public:
    std::string funcName;
    std::vector<std::unique_ptr<ASTNode>> body;
    FunctionNode(std::string name) : funcName(name) {}
    void print() const override {}
};

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::vector<std::unique_ptr<ASTNode>> parse();
private:
    std::vector<Token> tokens;
    size_t pos;
    Token peek(int offset = 0);
    Token advance();
    std::unique_ptr<ASTNode> parseStatement();
};
#endif
