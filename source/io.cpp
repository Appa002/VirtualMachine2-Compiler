//
// Created by a_mod on 25.07.2018.
//

#include "../header/io.h"
#include "../header/error.h"
#include "../header/ErrorFlags.h"

#include <string>
#include <fstream>
#include <sstream>

std::string compiler::io::open$(std::string path) {
    std::ifstream file;
    file.open(path, std::ios::binary);
    if(!file.is_open())
        throw error::file_error(("File \"" + path + "\" doesn't exist.").c_str());

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string str = buffer.str();
    return str;
}

std::string compiler::io::open(std::string path) {
    std::ifstream file;
    file.open(path, std::ios::binary);
    if(!file.is_open()){
        error::ErrorFlags::get().fileError(true);
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string str = buffer.str();
    return str;
}
