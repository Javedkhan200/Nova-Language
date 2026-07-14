#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>

enum class TokenType {
    IDENTIFIER, NUMBER, STRING, EQUALS, OPERATOR, END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
    std::string src;
    size_t pos;
public:
    Lexer(const std::string& src);
    std::vector<Token> tokenize();
};
#endif
