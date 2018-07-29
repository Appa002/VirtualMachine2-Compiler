//
// Created by a_mod on 29.07.2018.
//

#ifndef VM2_0_COMPILER_COMPILING_H
#define VM2_0_COMPILER_COMPILING_H

#include "compiling-detail.h"
#include "pipes.h"

namespace compiler::compiling{
    const utils::pipe_closure<details::compile_f> compile = {};
    const utils::pipe_closure<details::resolveSymbols_f> resolveSymbols = {};
}

#endif //VM2_0_COMPILER_COMPILING_H
