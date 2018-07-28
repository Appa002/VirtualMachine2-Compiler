//
// Created by a_mod on 25.07.2018.
//

#include "../header/InputFile.h"

compiler::classes::InputFile::InputFile(std::string file, std::string path, size_t fileLoadNum) {
    this->data_ = file;
    this->path_ = path;
    this->fileLoadingNum_ = fileLoadNum;

    std::string temp;
    size_t i = 0;

    for(auto it : file){
        if(it != '\n')
            temp += it;

        if(it == '\n' || i == file.size() - 1){
            if(i != file.size() - 1)
                temp.erase(temp.begin() + (temp.size() - 1));
            this->lines_.push_back(temp);
            temp.clear();
        }
        i++;
    }
}

const std::string &compiler::classes::InputFile::data() {
    return this->data_;
}

const std::vector<std::string> &compiler::classes::InputFile::lines() {
    return this->lines_;
}

const std::string &compiler::classes::InputFile::path() {
    return this->path_;
}

const std::string &compiler::classes::InputFile::data(std::string val) {
    this->data_ = val;
    return this->data_;
}

const std::vector<std::string> &compiler::classes::InputFile::lines(std::vector<std::string> val){
    this->lines_ = val;
    return this->lines_;
}

const std::string &compiler::classes::InputFile::path(std::string val) {
    this->path_ = val;
    return this->path_;
}

const size_t &compiler::classes::InputFile::fileLoadingNum() {
    return this->fileLoadingNum_;
}

const size_t &compiler::classes::InputFile::fileLoadingNum(size_t val) {
    this->fileLoadingNum_  = val;
    return this->fileLoadingNum_;
}
