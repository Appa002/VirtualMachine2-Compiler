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
        void resolveArg(std::string arg);
        uint32_t readNum(std::string in);
        uint32_t readHex(std::string in);
        uint32_t readFloat(std::string in);
    public:
        void resolveSymbolReferences();
        std::vector<uint8_t> byteCode;
    };
}

#endif //VM2_0_COMPILER_COMPILATIONFILE_H
