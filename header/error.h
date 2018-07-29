//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_ERROR_H
#define VM2_0_COMPILER_ERROR_H

#include <exception>
#include <stdexcept>

namespace compiler::error{

    typedef std::runtime_error file_error;
    typedef std::runtime_error reference_error;
    typedef std::runtime_error unknown_instruction_error;

}

#endif //VM2_0_COMPILER_ERROR_H
