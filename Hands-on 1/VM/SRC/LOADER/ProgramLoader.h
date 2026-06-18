#ifndef PROGRAM_LOADER_H
#define PROGRAM_LOADER_H

#include <vector>
#include <string>
#include "../instruction/Instruction.h"

class ProgramLoader {
public:
    std::vector<Instruction> loadFromFile(const std::string& filename);
};

#endif