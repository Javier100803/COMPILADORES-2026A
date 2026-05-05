#ifndef MACHINE_CYCLE_H
#define MACHINE_CYCLE_H

#include "../MEMORY/Memory.h"
#include "../REGISTERS/Registers.h"
#include "../CPU/ControlUnit.h"

class MachineCycle {
private:
    ControlUnit cu;

public:
    void run(Memory &mem, Registers &reg);
};

#endif