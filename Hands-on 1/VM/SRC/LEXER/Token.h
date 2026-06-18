#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    DELIMITER,
    UNKNOWN
};

class Token {
public:
    TokenType type;
    std::string value;

    Token(TokenType t, std::string v);
};

#endif