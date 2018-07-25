//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_LINE_H
#define VM2_0_COMPILER_LINE_H

#include <string>
#include <vector>
#include "InputFile.h"

namespace compiler::classes {
    class Line {
    public:
        Line() = default;
        Line(std::string str);
    private:
    public:
        std::string name;
        std::vector<std::string> args;
        bool thisLineHasSymbol = false;
        std::string sym;
    };
}

#endif //VM2_0_COMPILER_LINE_H
