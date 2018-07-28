//
// Created by a_mod on 25.07.2018.
//

#include <sstream>
#include "../header/InputFile.h"
#include "../header/File.h"
#include "../header/utils.h"

compiler::data::File::File(compiler::data::InputFile file) {
    for(auto it : file.lines()){
        switch (it.at(0)){
            case ('#'):{
                break;
            }
            case('\''): {
                data::Line line(it, true, file.fileLoadingNum());
                lines.push_back(line);
                break;
            }
            case('-'):{
                if(it.at(1) == '-')
                    break;
            }
            default:{
                lines.push_back(Line(it, false, file.fileLoadingNum()));
                break;
            }
        }
    }
}
