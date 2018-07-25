//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_UTILS_H
#define VM2_0_COMPILER_UTILS_H

#include <vector>
#include <string>
#include <sstream>

namespace compiler::utils{
    std::vector<std::string> splitStr(std::string in, char c){
        std::vector<std::string> out;
        std::string line;
        std::istringstream str(in);
        while(std::getline(str, line, c)){
            out.push_back(line);
        }
        return out;
    }

    std::string mergeStr(std::vector<std::string> strs, int n = 0){
        std::string out;
        for(int i = n; i < strs.size(); i++){
            out += strs.at(static_cast<unsigned long>(i));
        }
        return out;
    }
}

#endif //VM2_0_COMPILER_UTILS_H
