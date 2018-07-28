//
// Created by a_mod on 25.07.2018.
//

#include <string>
#include <iostream>
#include <algorithm>
#include "../header/pre-processing.h"
#include "../header/InputFile.h"
#include "../header/io.h"
#include "../header/ErrorFlags.h"
#include "../header/error.h"


void compiler::pre_processing::checkExistenceOfAllFiles$(compiler::data::InputFile file) {
    std::vector<compiler::data::InputFile> stack;
    stack.push_back(file);
    check_existence_of_all_files$(file, stack);
}

void compiler::pre_processing::check_existence_of_all_files$(compiler::data::InputFile file,
                                                             std::vector<compiler::data::InputFile> includeStack) {
    for(std::string it : file.lines()){
        if(it.at(0) == '#') {
            it.erase(it.begin());
            io::open(it);
            if(error::ErrorFlags::get().fileError()){
                std::string includeStackString;
                int i = 0;
                std::reverse(includeStack.begin(), includeStack.end());
                for(auto include : includeStack){
                    includeStackString += "\n\t" + include.path();
                    if(i != includeStack.size() - 1)
                        includeStackString += ", requested from";
                    i++;
                }
                throw error::file_error("File \"" + it + "\", requested from"+ includeStackString + " could not be opened!");
            }

            data::InputFile requestedFile(io::open$(it), it, 0);
            includeStack.push_back(requestedFile);
            check_existence_of_all_files$(requestedFile, includeStack);
        }
    }
}
