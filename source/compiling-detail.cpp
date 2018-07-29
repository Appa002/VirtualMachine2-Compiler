//
// Created by a_mod on 29.07.2018.
//

#include "../header/compiling-detail.h"

compiler::data::CompilationFile compiler::compiling::details::compile(compiler::data::File file) {
    return compiler::data::CompilationFile(file);
}

compiler::data::CompilationFile
compiler::compiling::details::resolveSymbols(compiler::data::CompilationFile compiledFile) {
    compiledFile.resolveSymbolReferences();
    return compiledFile;
}
