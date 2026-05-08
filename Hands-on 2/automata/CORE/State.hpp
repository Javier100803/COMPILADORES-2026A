#ifndef STATE_HPP
#define STATE_HPP

#include "TokenType.hpp"

class State {

private:
    int id;
    bool accepting;
    TokenType tokenType;

public:
    State(int id, bool accepting=false, TokenType tokenType=TokenType::NONE);

    int getId() const;
    bool isAccepting() const;
    TokenType getTokenType() const;
};

#endif