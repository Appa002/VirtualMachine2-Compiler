#include <iostream>
#include "./header/io.h"
#include "header/InputFile.h"
#include "header/pre-processing.h"

void usage();

int main(int argc, char* argv[]) {
    if(argc < 2){
        usage();
        return 1;
    }

    std::string file = compiler::io::open(argv[1]);
    compiler::data::InputFile f(file, argv[1], 0);
    compiler::pre_processing::check_existence_of_all_files$(f);

    auto files = compiler::pre_processing::fetchIncludeFiles(f);
    auto itemFile = compiler::pre_processing::transformInputFiles(files);
    itemFile = compiler::pre_processing::makeSymbolsUnique(itemFile);
    auto preprocessedFile = compiler::pre_processing::merge_include_files(itemFile);
    return 0;
}

void usage(){
    std::cout << "Usage: vmcp [FILE]" << std::endl;
}