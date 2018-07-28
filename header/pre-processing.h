//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_PRE_PROCESSING_H
#define VM2_0_COMPILER_PRE_PROCESSING_H

#include <string>
#include "pre-processing-detail.h"
#include "pipes.h"
#include "InputFile.h"
#include "File.h"

namespace compiler::pre_processing {
    const utils::pipe_closure<details::fetchIncludeFiles_f> fetchIncludeFiles = {};
    const utils::pipe_closure<details::merge_include_files_f> merge_include_files = {};
    const utils::pipe_closure<details::makeSymbolsUnique_f> makeSymbolsUnique = {};
    const utils::pipe_closure<details::transformInputFiles_f> transformInputFiles = {};

    void check_existence_of_all_files$(compiler::data::InputFile file);

    void check_existence_of_all_files$(compiler::data::InputFile file,
                                       std::vector<compiler::data::InputFile> includeStack);

}


#endif //VM2_0_COMPILER_PRE_PROCESSING_H
