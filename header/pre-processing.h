//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_PRE_PROCESSING_H
#define VM2_0_COMPILER_PRE_PROCESSING_H

#include <string>
#include "InputFile.h"
#include "File.h"

namespace compiler::pre_processing{
    void check_existence_of_all_files$(compiler::data::InputFile file);
    void check_existence_of_all_files$(compiler::data::InputFile file,
                                           std::vector<compiler::data::InputFile> includeStack);


    std::vector<compiler::data::InputFile>
            fetchIncludeFiles(compiler::data::InputFile file);

    std::vector<compiler::data::InputFile>
            fetchIncludeFiles(compiler::data::InputFile file,
                              std::vector<compiler::data::InputFile> files);

    compiler::data::File
            merge_include_files(std::vector<compiler::data::File> files);

    std::vector<compiler::data::File>
            makeSymbolsUnique(std::vector<compiler::data::File> files);


    std::vector<compiler::data::File>
            transformInputFiles(std::vector<compiler::data::InputFile> files);
}

#endif //VM2_0_COMPILER_PRE_PROCESSING_H
