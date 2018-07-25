//
// Created by a_mod on 25.07.2018.
//

#include "../header/ErrorFlags.h"

bool compiler::error::ErrorFlags::fileError() {
    bool temp = fileError_;
    fileError_ = false;
    return temp;
}

bool compiler::error::ErrorFlags::fileError(bool value) {
    fileError_ = value;
    return fileError_;
}
