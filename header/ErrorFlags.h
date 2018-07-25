//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_ERRORFLAGS_H
#define VM2_0_COMPILER_ERRORFLAGS_H

#include "Singleton.h"

namespace compiler::error {
    class ErrorFlags : public utils::Singleton<ErrorFlags> {
    public:
        ErrorFlags() = default;

    private:
        bool fileError_ = false;

    public:
        bool fileError();
        bool fileError(bool value);
    };
}

#endif //VM2_0_COMPILER_ERRORFLAGS_H
