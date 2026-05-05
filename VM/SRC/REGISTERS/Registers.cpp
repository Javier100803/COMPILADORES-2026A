#include "Registers.h"
#include <iostream>

Registers::Registers() {
    PC = 0;
    IR = "";

    ACC = MAR = MBR = 0;
    AL = AH = BL = BH = 0;
}

void Registers::print() {
    std::cout << "PC: " << PC
              << " IR: " << IR
              << " ACC: " << ACC
              << " MAR: " << MAR
              << " MBR: " << MBR
              << " AL: " << AL
              << " AH: " << AH
              << " BL: " << BL
              << " BH: " << BH
              << "\n";
}