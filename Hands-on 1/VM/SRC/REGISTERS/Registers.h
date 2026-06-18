#ifndef REGISTERS_H
#define REGISTERS_H

#include <string>

class Registers {
public:
    int PC;
    std::string IR;

    int ACC;
    int MAR;
    int MBR;

    int AL, AH, BL, BH;

    Registers();

    void print();
};

#endif              