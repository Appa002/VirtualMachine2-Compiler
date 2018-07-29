//
// Created by a_mod on 29.07.2018.
//

#ifndef VM2_0_COMPILER_COMPILING_DETAIL_H
#define VM2_0_COMPILER_COMPILING_DETAIL_H

#include "CompilationFile.h"

namespace compiler::compiling::details{
    data::CompilationFile compile(data::File file);
    data::CompilationFile resolveSymbols(data::CompilationFile compiledFile);

    struct compile_f {
        template<class T>
        auto operator()(T x) const {
            return compile(x);
        }
    };

    struct resolveSymbols_f {
        template<class T>
        auto operator()(T x) const {
            return resolveSymbols(x);
        }
    };
}


#endif //VM2_0_COMPILER_COMPILING_DETAIL_H
