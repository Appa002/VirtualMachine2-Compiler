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


void compiler::pre_processing::check_existence_of_all_files$(compiler::data::InputFile file) {
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

std::vector<compiler::data::InputFile>
compiler::pre_processing::details::fetchIncludeFiles(compiler::data::InputFile file) {
    std::vector<compiler::data::InputFile> vec;
    vec.push_back(file);
    return fetchIncludeFiles(file, vec);
}

std::vector<compiler::data::InputFile>
compiler::pre_processing::details::fetchIncludeFiles(compiler::data::InputFile file,
                                            std::vector<compiler::data::InputFile> files) {
    for(std::string it : file.lines()){
        if(it.at(0) == '#') {
            it.erase(it.begin());
            data::InputFile f(io::open$(it), it, files.size());
            files.push_back(f);
            fetchIncludeFiles(f, files);
        }
    }
    return files;
}

compiler::data::File
compiler::pre_processing::details::merge_include_files(std::vector<compiler::data::File> files) {
    data::File master;
    for(auto file : files){
        for(auto line : file.lines){
            master.lines.push_back(line);
        }
    }
    return master;
}

std::vector<compiler::data::File>
compiler::pre_processing::details::makeSymbolsUnique(std::vector<compiler::data::File> files) {
    for(uint32_t i = 0; i < files.size(); i++){
        for(auto& line : files.at(i).lines){
            if(line.hasSymbol)
                line.symbol = std::to_string(i) + line.symbol;
        }
    }
    return files;
}

std::vector<compiler::data::File>
compiler::pre_processing::details::transformInputFiles(std::vector<compiler::data::InputFile> files) {
    std::vector<compiler::data::File> out;
    for(auto it : files){
        out.push_back(data::File(it));
    }
    return out;
}

