#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include "../instruction/Instruction.h"

class Memory {
private:
    std::vector<Instruction> program;

public:
    void loadProgram(std::vector<Instruction> p);
    Instruction getInstruction(int address);
    int size();
};

#endif