//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_PRE_PROCESSING_H
#define VM2_0_COMPILER_PRE_PROCESSING_H

#include <string>
#include "InputFile.h"
#include "File.h"

namespace compiler::pre_processing{
    void check_existence_of_all_files$(compiler::classes::InputFile file);
    void check_existence_of_all_files$(compiler::classes::InputFile file,
                                           std::vector<compiler::classes::InputFile> includeStack);


    std::vector<compiler::classes::InputFile>
            fetchIncludeFiles(compiler::classes::InputFile file);

    std::vector<compiler::classes::InputFile>
            fetchIncludeFiles(compiler::classes::InputFile file,
                              std::vector<compiler::classes::InputFile> files);

    compiler::classes::File
            merge_include_files(std::vector<compiler::classes::File> files);

    std::vector<compiler::classes::File>
            makeSymbolsUnique(std::vector<compiler::classes::File> files);


    std::vector<compiler::classes::File>
            transformInputFiles(std::vector<compiler::classes::InputFile> files);
}

#endif //VM2_0_COMPILER_PRE_PROCESSING_H
