#include "../builder/AutomataBuilder.hpp"

FiniteStateAutomata buildNumberAutomata() {
    AutomataBuilder builder;

    builder.addState("q0", false);
    builder.addState("q1", true);
    builder.addState("q2", false);
    builder.addState("q3", true);

    builder.setStartState("q0");

    // transiciones
    builder.addTransition("q0", "q1", "digit");
    builder.addTransition("q1", "q1", "digit");
    builder.addTransition("q1", "q2", ".");
    builder.addTransition("q2", "q3", "digit");
    builder.addTransition("q3", "q3", "digit");

    return builder.build();
}