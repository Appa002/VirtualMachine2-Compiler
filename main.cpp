#include <iostream>
#include "./header/io.h"
#include "header/InputFile.h"
#include "header/pre-processing.h"

using namespace compiler;

void usage();

int main(int argc, char* argv[]) {
    if(argc < 2){
        usage();
        return 1;
    }

    compiler::data::InputFile file(compiler::io::open$(argv[1]), argv[1], 0);
    compiler::pre_processing::check_existence_of_all_files$(file);

    auto out = file
            | pre_processing::fetchIncludeFiles
            | pre_processing::transformInputFiles
            | pre_processing::makeSymbolsUnique
            | pre_processing::mergeIncludeFiles;

    return 0;
}

void usage(){
    std::cout << "Usage: vmcp [FILE]" << std::endl;
}