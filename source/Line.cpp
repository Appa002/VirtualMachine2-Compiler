//
// Created by a_mod on 25.07.2018.
//

#include "../header/Line.h"
#include "../header/InputFile.h"
#include "../header/utils.h"

compiler::data::Line::Line(std::string str, bool hasSym, size_t fileNum) {
    auto splitStr = utils::splitStr(str, ' ');
    for(int64_t i = splitStr.size() - 1; i >= 0; i--){
        if(splitStr.at(i) == "")
            splitStr.erase(splitStr.begin() + i);
    }

    this->hasSymbol = hasSym;
    if(hasSym){
        this->symbol = splitStr[0];
        this->symbol.erase(this->symbol.begin());
        splitStr.erase(splitStr.begin());
    }

    this->instructionName = splitStr[0];
    splitStr.erase(splitStr.begin());

    for(auto arg : splitStr){
        if(arg[0] == '@'){
            arg.erase(arg.begin());
            arg = '@' + std::to_string(fileNum) + arg;
        }

        this->args.push_back(arg);
    }

}
