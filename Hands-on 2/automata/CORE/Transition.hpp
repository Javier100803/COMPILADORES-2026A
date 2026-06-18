#ifndef TRANSITION_HPP
#define TRANSITION_HPP

class Transition {

private:
    int fromState;
    int toState;
    char symbol;

public:
    Transition(int fromState, int toState, char symbol);

    int getFromState() const;
    int getToState() const;
    char getSymbol() const;
};

#endif