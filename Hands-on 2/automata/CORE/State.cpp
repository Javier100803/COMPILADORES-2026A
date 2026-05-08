#include "State.hpp"

State::State(int id, bool accepting, TokenType tokenType)
    : id(id), accepting(accepting), tokenType(tokenType) {}

int State::getId() const {
    return id;
}

bool State::isAccepting() const {
    return accepting;
}

TokenType State::getTokenType() const {
    return tokenType;
}