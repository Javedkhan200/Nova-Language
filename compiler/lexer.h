#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>

enum class TokenType {
    IDENTIFIER, NUMBER, STRING, DOT, ASSIGN, PLUS, MINUS, MULTIPLY, DIVIDE,
    GREATER, LESS, EQUAL_EQUAL, // New math comparators
    LPAREN, RPAREN, LBRACE, RBRACE, END_OF_FILE, UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();
private:
    std::string src;
    size_t pos;
    char peek();
    char advance();
};
#endif
