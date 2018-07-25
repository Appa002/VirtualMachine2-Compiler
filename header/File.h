//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_FILE_H
#define VM2_0_COMPILER_FILE_H

#include <vector>
#include <string>
#include <unordered_map>

#include "Line.h"

namespace compiler::classes{
    class File{
    public:
        File() = default;
        File(classes::InputFile file);

    private:
    public:
        std::vector<classes::Line> lines;
        std::vector<std::pair<std::string, uint32_t>> symbol_table;
    };
}

#endif //VM2_0_COMPILER_FILE_H
