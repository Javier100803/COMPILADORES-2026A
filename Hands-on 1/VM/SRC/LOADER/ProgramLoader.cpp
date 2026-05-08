#include "ProgramLoader.h"
#include "../lexer/Lexer.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Instruction> ProgramLoader::loadFromFile(const std::string& filename) {
    std::vector<Instruction> program;
    std::ifstream file(filename);
    std::string line;

    Lexer lexer;
    std::cout << "Cargando programa...\n";
    while (getline(file, line)) {
        auto tokens = lexer.tokenize(line);

        if (tokens.empty()) continue;

        std::string name = tokens[0].value;
        std::vector<std::string> args;

        for (size_t i = 1; i < tokens.size(); i++) {
            args.push_back(tokens[i].value);
        }

        program.push_back(Instruction(name, args));
    }

    return program;
}