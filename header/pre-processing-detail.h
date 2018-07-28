//
// Created by a_mod on 29.07.2018.
//

#ifndef VM2_0_COMPILER_PRE_PROCESSING_DETAIL_H
#define VM2_0_COMPILER_PRE_PROCESSING_DETAIL_H


#include "InputFile.h"
#include "File.h"

namespace compiler::pre_processing::details{
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

    struct fetchIncludeFiles_f {
        template<class T>
        auto operator()(T x) const {
            return fetchIncludeFiles(x);
        }
    };

    struct merge_include_files_f {
        template<class T>
        auto operator()(T x) const {
            return merge_include_files(x);
        }
    };

    struct makeSymbolsUnique_f {
        template<class T>
        auto operator()(T x) const {
            return makeSymbolsUnique(x);
        }
    };

    struct transformInputFiles_f {
        template<class T>
        auto operator()(T x) const {
            return transformInputFiles(x);
        }
    };
}

#endif //VM2_0_COMPILER_PRE_PROCESSING_DETAIL_H
