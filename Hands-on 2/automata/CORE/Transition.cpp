#include "Transition.hpp"

Transition::Transition(int fromState, int toState, char symbol)
    : fromState(fromState), toState(toState), symbol(symbol) {}

int Transition::getFromState() const {
    return fromState;
}

int Transition::getToState() const {
    return toState;
}

char Transition::getSymbol() const {
    return symbol;
}