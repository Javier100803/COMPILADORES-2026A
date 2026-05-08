#include "Memory.h"

void Memory::loadProgram(std::vector<Instruction> p) {
    program = p;
}

Instruction Memory::getInstruction(int address) {
    return program[address];
}

int Memory::size() {
    return program.size();
}