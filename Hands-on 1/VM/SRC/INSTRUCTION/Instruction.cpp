#include "Instruction.h"

Instruction::Instruction(std::string name, std::vector<std::string> args)
    : name(name), args(args) {}

std::string Instruction::getName() {
    return name;
}

std::vector<std::string> Instruction::getArgs() {
    return args;
}

int Instruction::getLength() {
    return args.size();
}