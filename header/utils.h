//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_UTILS_H
#define VM2_0_COMPILER_UTILS_H

#include <vector>
#include <string>
#include <sstream>

namespace compiler::utils{

    std::vector<std::string> splitStr(std::string in, char c);
    std::string mergeStr(std::vector<std::string> strs, int n = 0);

}

#endif //VM2_0_COMPILER_UTILS_H
