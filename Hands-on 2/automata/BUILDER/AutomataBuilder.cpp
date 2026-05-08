
#include "AutomataBuilder.hpp"
#include <cctype>

/*
    KEYWORDS soportadas por la VM:

    start
    stop
    move
    add
    sto
*/

FiniteStateAutomata AutomataBuilder::buildKeywordAutomata()
{
    FiniteStateAutomata dfa;

    // Estados
    dfa.addState(State(0,false));
    dfa.addState(State(1,false));
    dfa.addState(State(2,false));
    dfa.addState(State(3,false));
    dfa.addState(State(4,false));
    dfa.addState(State(5,true,TokenType::KEYWORD));

    dfa.setStartState(0);

    // add
    dfa.addTransition(Transition(0,1,'a'));
    dfa.addTransition(Transition(1,2,'d'));
    dfa.addTransition(Transition(2,5,'d'));

    // sto
    dfa.addTransition(Transition(0,1,'s'));
    dfa.addTransition(Transition(1,2,'t'));
    dfa.addTransition(Transition(2,5,'o'));

    // stop
    dfa.addTransition(Transition(2,3,'o'));
    dfa.addTransition(Transition(3,5,'p'));

    // start
    dfa.addTransition(Transition(2,3,'a'));
    dfa.addTransition(Transition(3,4,'r'));
    dfa.addTransition(Transition(4,5,'t'));

    // move
    dfa.addTransition(Transition(0,1,'m'));
    dfa.addTransition(Transition(1,2,'o'));
    dfa.addTransition(Transition(2,3,'v'));
    dfa.addTransition(Transition(3,5,'e'));

    return dfa;
}



FiniteStateAutomata AutomataBuilder::buildRegisterAutomata()
{
    FiniteStateAutomata dfa;

    dfa.addState(State(0,false));
    dfa.addState(State(1,false));
    dfa.addState(State(2,true,TokenType::REGISTER));

    dfa.setStartState(0);

    // Primer caracter
    dfa.addTransition(Transition(0,1,'A'));
    dfa.addTransition(Transition(0,1,'B'));

    // Segundo caracter
    dfa.addTransition(Transition(1,2,'L'));
    dfa.addTransition(Transition(1,2,'H'));

    return dfa;
}



FiniteStateAutomata AutomataBuilder::buildNumberAutomata()
{
    FiniteStateAutomata dfa;

    dfa.addState(State(0,false));
    dfa.addState(State(1,true,TokenType::NUMBER));

    dfa.setStartState(0);

    for(char c='0'; c<='9'; c++)
    {
        dfa.addTransition(Transition(0,1,c));
        dfa.addTransition

