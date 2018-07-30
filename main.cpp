#include <iostream>
#include <fstream>

#include "./header/io.h"
#include "header/InputFile.h"
#include "header/pre-processing.h"
#include "header/compiling.h"
#include "header/error.h"

using namespace compiler;

void usage();

int main(int argc, char* argv[]) {
    if(argc < 2){
        usage();
        return 1;
    }


    compiler::data::InputFile inputFile(compiler::io::open$(argv[1]), argv[1], 0);
    compiler::pre_processing::checkExistenceOfAllFiles$(inputFile);

    auto out = inputFile
            | pre_processing::fetchIncludeFiles
            | pre_processing::transformInputFiles
            | pre_processing::makeSymbolsUnique
            | pre_processing::mergeIncludeFiles
            | compiling::compile
            | compiling::resolveSymbols;


    std::ofstream outputFile;
    outputFile.open("./out.vm2", std::ios::binary | std::ios::out);
    if(!outputFile.is_open())
        throw error::file_error("Can't open output file!");


    outputFile.write((char*)&out.byteCode.at(0), out.byteCode.size());
    outputFile.close();
    return 0;
}

void usage(){
    std::cout << "Usage: vmcp [FILE]" << std::endl;
}