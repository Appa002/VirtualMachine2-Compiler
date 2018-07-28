//
// Created by a_mod on 28.07.2018.
//

#include "../header/utils.h"

std::vector<std::string> compiler::utils::splitStr(std::string in, char c){
    std::vector<std::string> out;
    std::string line;
    std::istringstream str(in);
    while(std::getline(str, line, c)){
        out.push_back(line);
    }
    return out;
}

std::string compiler::utils::mergeStr(std::vector<std::string> strs, int n){
    std::string out;
    for(int i = n; i < strs.size(); i++){
        out += strs.at(static_cast<unsigned long>(i));
    }
    return out;
}