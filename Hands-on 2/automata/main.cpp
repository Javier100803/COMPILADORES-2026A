#include <iostream>
#include "examples/NumberAutomata.cpp"

int main() {
    auto automata = buildNumberAutomata();

    std::string input;
    std::cin >> input;

    if (automata.evaluate(input))
        std::cout << "Numero valido\n";
    else
        std::cout << "Numero invalido\n";

    return 0;
}