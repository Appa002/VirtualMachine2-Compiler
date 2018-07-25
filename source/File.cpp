//
// Created by a_mod on 25.07.2018.
//

#include <sstream>
#include "../header/InputFile.h"
#include "../header/File.h"
#include "../header/utils.h"

compiler::classes::File::File(compiler::classes::InputFile file) {
    for(auto it : file.lines()){
        switch (it.at(0)){
            case ('#'):{

                break;
            }
            case('\''): {
                auto splitLines = utils::splitStr(it, ' ');
                std::string sym = splitLines.at(0);
                sym.erase(sym.begin());
                symbol_table.push_back(std::pair<std::string, uint32_t >(sym, 0x00));
                classes::Line line(utils::mergeStr(splitLines, 1));
                line.thisLineHasSymbol = true;
                line.sym = sym;
                lines.push_back(line);
                break;
            }
            default:{
                lines.push_back(Line(it));
                break;
            }
        }
    }
}
