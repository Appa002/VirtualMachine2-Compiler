//
// Created by a_mod on 25.07.2018.
//

#include "../header/Line.h"
#include "../header/InputFile.h"
#include "../header/utils.h"

compiler::classes::Line::Line(std::string str, bool hasSym, size_t fileNum) {
    auto splitStr = utils::splitStr(str, ' ');
    this->hasSymbol = hasSym;
    if(hasSym){
        this->symbol = splitStr[0];
        this->symbol.erase(this->symbol.begin());
        splitStr.erase(splitStr.begin());
    }

    this->name = splitStr[0];
    splitStr.erase(splitStr.begin());

    for(auto arg : splitStr){
        if(arg[0] == '@'){
            arg.erase(arg.begin());
            arg = '@' + std::to_string(fileNum) + arg;
        }

        this->args.push_back(arg);
    }

}
