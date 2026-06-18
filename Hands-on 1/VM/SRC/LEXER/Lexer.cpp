#include "Lexer.h"
#include <sstream>
#include <cctype>

bool isKeyword(const std::string& str) {
    return str == "START" || str == "STOP" ||
           str == "MOVE" || str == "ADD" ||
           str == "STORE";
}

std::vector<Token> Lexer::tokenize(const std::string& line) {
    std::vector<Token> tokens;
    std::stringstream ss(line);
    std::string word;

    while (ss >> word) {

        if (isKeyword(word)) {
            tokens.push_back(Token(KEYWORD, word));
        }

        else if (isdigit(word[0])) {
            tokens.push_back(Token(NUMBER, word));
        }

        else if (isalpha(word[0])) {
            tokens.push_back(Token(IDENTIFIER, word));
        }

        else if (word == "," || word == ";") {
            tokens.push_back(Token(DELIMITER, word));
        }

        else {
            tokens.push_back(Token(UNKNOWN, word));
        }
    }

    return tokens;
}