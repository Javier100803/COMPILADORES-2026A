#include <iostream>
#include "MEMORY/Memory.h"
#include "REGISTERS/Registers.h"
#include "CPU/MachineCycle.h"
#include "LOADER/ProgramLoader.h"

int main() {

    ProgramLoader loader;
    auto program = loader.loadFromFile("../PROGRAMS/program.txt");

    Memory mem;
    mem.loadProgram(program);

    Registers reg;
    MachineCycle mc;

    mc.run(mem, reg);

    return 0;
}