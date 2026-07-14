#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& src) : src(src), pos(0) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos < src.length()) {
        char current = src[pos];
        if (std::isspace(current)) { pos++; continue; }
        
        if (std::isalpha(current) || current == '_') {
            std::string value;
            while (pos < src.length() && (std::isalnum(src[pos]) || src[pos] == '_' || src[pos] == '.')) {
                value += src[pos++];
            }
            tokens.push_back({TokenType::IDENTIFIER, value});
        }
        else if (std::isdigit(current)) {
            std::string value;
            while (pos < src.length() && std::isdigit(src[pos])) value += src[pos++];
            tokens.push_back({TokenType::NUMBER, value});
        }
        else if (current == '=') {
            tokens.push_back({TokenType::EQUALS, "="});
            pos++;
        }
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            std::string op(1, current);
            tokens.push_back({TokenType::OPERATOR, op});
            pos++;
        }
        else if (current == '(') {
            pos++;
            std::string value;
            while (pos < src.length() && src[pos] != ')') {
                value += src[pos++];
            }
            tokens.push_back({TokenType::STRING, value});
            if (pos < src.length() && src[pos] == ')') pos++;
        }
        else { pos++; }
    }
    return tokens;
}
