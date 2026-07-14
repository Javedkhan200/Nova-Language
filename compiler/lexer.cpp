#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& src) : src(src), pos(0) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos < src.length()) {
        char current = src[pos];
        
        // इग्नोर कमेंट्स //
        if (current == '/' && pos + 1 < src.length() && src[pos+1] == '/') {
            while (pos < src.length() && src[pos] != '\n') pos++;
            continue;
        }

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
            tokens.push_back({TokenType::OPERATOR, std::string(1, current)});
            pos++;
        }
        else if (current == '(') {
            pos++;
            std::string value;
            // ब्रैकेट के अंदर का सब कुछ उठा लेगा (चाहे कोट्स हो या स्पेस)
            while (pos < src.length() && src[pos] != ')') {
                value += src[pos++];
            }
            tokens.push_back({TokenType::STRING, value});
            if (pos < src.length() && src[pos] == ')') pos++;
        }
        else { pos++; } // फालतू सिंबल्स को बिना क्रैश हुए इग्नोर करेगा
    }
    return tokens;
}
