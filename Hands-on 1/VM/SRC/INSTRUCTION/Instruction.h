#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <vector>

class Instruction {
private:
    std::string name;
    std::vector<std::string> args;

public:
    Instruction(std::string name, std::vector<std::string> args);

    std::string getName();
    std::vector<std::string> getArgs();
    int getLength();
};

#endif