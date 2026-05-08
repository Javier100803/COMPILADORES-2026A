#ifndef FINITESTATEAUTOMATA_HPP
#define FINITESTATEAUTOMATA_HPP

#include <vector>
#include "State.hpp"
#include "Transition.hpp"
#include "string"

bool evaluate(const std::string& input);
class FiniteStateAutomata {

private:
    std::vector<State> states;
    std::vector<Transition> transitions;

    int currentState;
    int startState;

public:
    FiniteStateAutomata();

    void addState(const State& state);
    void addTransition(const Transition& transition);

    void setStartState(int id);

    void reset();

    bool processSymbol(char symbol);

    bool isAccepting() const;

    TokenType getTokenType() const;
};

#endif