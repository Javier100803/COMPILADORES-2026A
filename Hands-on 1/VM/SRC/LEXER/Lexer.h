#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>
#include "Token.h"

class Lexer {
public:
    std::vector<Token> tokenize(const std::string& line);
};

#endif