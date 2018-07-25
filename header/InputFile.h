//
// Created by a_mod on 25.07.2018.
//

#ifndef VM2_0_COMPILER_INPUTFILE_H
#define VM2_0_COMPILER_INPUTFILE_H

#include <string>
#include <vector>

namespace compiler::classes {
    class InputFile {
    public:
        InputFile() = delete;
        InputFile(std::string data, std::string path);

    private:
        std::string data_;
        std::string path_;
        std::vector<std::string> lines_;

    public:
        const std::string& data();
        const std::vector<std::string>& lines();
        const std::string& path();

        const std::string& data(std::string val);
        const std::vector<std::string>& lines(std::vector<std::string> val);
        const std::string& path(std::string val);
    };
}

#endif //VM2_0_COMPILER_INPUTFILE_H
