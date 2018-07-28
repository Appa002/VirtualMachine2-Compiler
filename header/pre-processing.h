//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_PRE_PROCESSING_H
#define VM2_0_COMPILER_PRE_PROCESSING_H

#include <string>
#include "InputFile.h"
#include "File.h"

namespace compiler::pre_processing {
    namespace details {
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

        template<class F>
        struct pipe_closure : F {
            template<class... Xs>
            pipe_closure(Xs&&... xs) : F(std::forward<Xs>(xs)...)
            {}
        };
    }

    const details::pipe_closure<details::fetchIncludeFiles_f> fetchIncludeFiles = {};
    const details::pipe_closure<details::merge_include_files_f> merge_include_files = {};
    const details::pipe_closure<details::makeSymbolsUnique_f> makeSymbolsUnique = {};
    const details::pipe_closure<details::transformInputFiles_f> transformInputFiles = {};

    void check_existence_of_all_files$(compiler::data::InputFile file);

    void check_existence_of_all_files$(compiler::data::InputFile file,
                                       std::vector<compiler::data::InputFile> includeStack);

}
template <class T, class F>
decltype(auto) operator| (T&& x, const compiler::pre_processing::details::pipe_closure<F>& p){
    return p(std::forward<T>(x));
};


#endif //VM2_0_COMPILER_PRE_PROCESSING_H
