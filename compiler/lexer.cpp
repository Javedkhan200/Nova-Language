#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& source) : src(source), pos(0) {}

char Lexer::peek() {
    if (pos >= src.length()) return '\0';
    return src[pos];
}

char Lexer::advance() {
    if (pos >= src.length()) return '\0';
    return src[pos++];
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos < src.length()) {
        char current = peek();

        if (std::isspace(current)) { advance(); continue; }
        if (current == '/' && pos + 1 < src.length() && src[pos+1] == '/') {
            while (peek() != '\n' && peek() != '\0') advance();
            continue;
        }

        if (std::isalpha(current) || current == '_') {
            std::string id = "";
            while (std::isalnum(peek()) || peek() == '_') id += advance();
            tokens.push_back({TokenType::IDENTIFIER, id});
            continue;
        }

        if (std::isdigit(current)) {
            std::string num = "";
            while (std::isdigit(peek())) num += advance();
            tokens.push_back({TokenType::NUMBER, num});
            continue;
        }

        if (current == '"') {
            advance();
            std::string str = "";
            while (peek() != '"' && peek() != '\0') str += advance();
            if(peek() == '"') advance();
            tokens.push_back({TokenType::STRING, str});
            continue;
        }

        switch (current) {
            case '.': tokens.push_back({TokenType::DOT, "."}); advance(); break;
            case '=': 
                advance(); 
                if (peek() == '=') { tokens.push_back({TokenType::EQUAL_EQUAL, "=="}); advance(); }
                else tokens.push_back({TokenType::ASSIGN, "="}); 
                break;
            case '>': tokens.push_back({TokenType::GREATER, ">"}); advance(); break;
            case '<': tokens.push_back({TokenType::LESS, "<"}); advance(); break;
            case '+': tokens.push_back({TokenType::PLUS, "+"}); advance(); break;
            case '-': tokens.push_back({TokenType::MINUS, "-"}); advance(); break;
            case '*': tokens.push_back({TokenType::MULTIPLY, "*"}); advance(); break;
            case '/': tokens.push_back({TokenType::DIVIDE, "/"}); advance(); break;
            case '(': tokens.push_back({TokenType::LPAREN, "("}); advance(); break;
            case ')': tokens.push_back({TokenType::RPAREN, ")"}); advance(); break;
            case '{': tokens.push_back({TokenType::LBRACE, "{"}); advance(); break;
            case '}': tokens.push_back({TokenType::RBRACE, "}"}); advance(); break;
            default: advance(); break;
        }
    }
    tokens.push_back({TokenType::END_OF_FILE, ""});
    return tokens;
}
