#include "MachineCycle.h"
#include <iostream>

void MachineCycle::run(Memory &mem, Registers &reg) {

    while (reg.PC < mem.size()) {

        std::cout << "\n--- FETCH ---\n";
        Instruction instr = mem.getInstruction(reg.PC);
        reg.IR = instr.getName();

        std::cout << "PC: " << reg.PC << " IR: " << reg.IR << "\n";

        std::cout << "--- DECODE ---\n";
        std::cout << "Instruccion: " << instr.getName() << "\n";

        std::cout << "--- EXECUTE ---\n";
        
        cu.execute(instr, reg, mem);
        reg.print();

        reg.PC++;
    }
}