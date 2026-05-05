#include "ControlUnit.h"
#include <iostream>

void ControlUnit::execute(Instruction instr, Registers &reg, Memory &mem) {
    std::string op = instr.getName();
    auto args = instr.getArgs();

    if (op == "START") {
        std::cout << "Inicio del programa\n";
    }

    else if (op == "STOP") {
        std::cout << "Fin del programa\n";
    }

    else if (op == "MOVE") {
    if (args[0] == "AL") {
        reg.AL = std::stoi(args[1]);
        std::cout << "AL <- " << reg.AL << "\n";
    }

    else if (args[0] == "BL") {
        reg.BL = std::stoi(args[1]);
        std::cout << "BL <- " << reg.BL << "\n";
    }
}

    else if (op == "ADD") {
        reg.ACC = reg.AL + reg.BL;
        std::cout << "Resultado ADD: " << reg.ACC << "\n";
    }

    else if (op == "STORE") {
        reg.MBR = reg.ACC;
        std::cout << "Guardado en MBR: " << reg.MBR << "\n";
    }
}