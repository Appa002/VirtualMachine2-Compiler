//
// Created by a_mod on 29.07.2018.
//

#ifndef VM2_0_COMPILER_COMPILATIONFILE_H
#define VM2_0_COMPILER_COMPILATIONFILE_H

#include <list>
#include "File.h"

namespace compiler::data {
    class CompilationFile {
    public:
        CompilationFile() = delete;
        CompilationFile(File file);

    private:
        //                  Sym name,       value
        std::unordered_map<std::string, uint32_t> symbolTable_;

        //                  Sym name,     whereToInsert
        std::unordered_map<std::string, uint32_t> symbolReferences;

        std::vector<uint8_t> byteCode;

        void resolveArg(std::string arg);
    public:
        void resolveSymbolReferences();
    };
}

#endif //VM2_0_COMPILER_COMPILATIONFILE_H
