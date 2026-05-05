#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include "../instruction/Instruction.h"
#include "../registers/Registers.h"
#include "../memory/Memory.h"

class ControlUnit {
public:
    void execute(Instruction instr, Registers &reg, Memory &mem);
};

#endif