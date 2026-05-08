#include "FiniteStateAutomata.hpp"

FiniteStateAutomata::FiniteStateAutomata()
{
    startState = 0;
    currentState = 0;
}

void FiniteStateAutomata::addState(const State& state) {
    states.push_back(state);
}

void FiniteStateAutomata::addTransition(const Transition& transition) {
    transitions.push_back(transition);
}

void FiniteStateAutomata::setStartState(int id) {
    startState = id;
    currentState = id;
}

void FiniteStateAutomata::reset() {
    currentState = startState;
}

bool FiniteStateAutomata::processSymbol(char symbol) {

    for (const auto& t : transitions) {

        if (t.getFromState() == currentState &&
            t.getSymbol() == symbol)
        {
            currentState = t.getToState();
            return true;
        }
    }

    return false;
}

bool FiniteStateAutomata::isAccepting() const {

    for (const auto& s : states) {
        if (s.getId() == currentState)
            return s.isAccepting();
    }

    return false;
}

TokenType FiniteStateAutomata::getTokenType() const {

    for (const auto& s : states) {
        if (s.getId() == currentState)
            return s.getTokenType();
    }

    return TokenType::NONE;
}