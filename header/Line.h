//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_LINE_H
#define VM2_0_COMPILER_LINE_H

#include <string>
#include <vector>

namespace compiler::data {
    class Line {
    public:
        Line() = delete;
        explicit Line(std::string str, bool hasSym, size_t fileNum);
    private:
    public:
        std::string instructionName;
        std::vector<std::string> args;
        bool hasSymbol = false;
        bool globalSymbol = false;
        std::string symbol;
    };
}

#endif //VM2_0_COMPILER_LINE_H
