//
// Created by a_mod on 29.07.2018.
//

#include "../header/CompilationFile.h"
#include "../header/InstructionMap.h"
#include "../header/error.h"

compiler::data::CompilationFile::CompilationFile(compiler::data::File file) {
    for (auto line : file.lines) {
        uint32_t address = static_cast<uint32_t>(byteCode.size());

        for (int64_t i = line.args.size() - 1; i >= 0; i--) {
            resolveArg(line.args.at(static_cast<unsigned long>(i)));
        }

        if(InstructionMap::nameToOp.find(line.instructionName) == InstructionMap::nameToOp.cend())
            throw error::unknown_instruction_error("Unknown instruction \"" + line.instructionName + "\".");

        byteCode.push_back(InstructionMap::nameToOp.at(line.instructionName));
        if (line.hasSymbol)
            symbolTable_[line.symbol] = address;
    }
}

void compiler::data::CompilationFile::resolveArg(std::string arg) {
    if (arg == "STACK")
        return;

    switch (arg[0]) {
        case ('@'): {
            byteCode.push_back(data::InstructionMap::nameToOp.at("push"));
            arg.erase(arg.begin());
            symbolReferences[arg] = static_cast<const uint32_t &>(byteCode.size() - 1);
            byteCode.push_back(0x00);
            byteCode.push_back(0x00);
            byteCode.push_back(0x00);
            byteCode.push_back(0x00);
            break;
        }

        case ('$'): {
            arg.erase(arg.begin());
            char num[2] = {'\0'};
            num[0] = arg[0];
            byteCode.push_back(static_cast<uint8_t &&>(0xa0 + std::stoi(std::string(num))));
            break;
        }

        case ('*'): {
            arg.erase(arg.begin());
            resolveArg(arg);
            byteCode.push_back(data::InstructionMap::nameToOp.at("read"));
            break;
        }


        default: {
            //TODO: Interpret numbers as floats, signed, unsigned or hex values.
            byteCode.push_back(data::InstructionMap::nameToOp.at("push"));
            uint32_t value = static_cast<uint32_t>(std::stoi(arg));

            uint8_t a = static_cast<uint8_t>(value >> 24);
            uint8_t b = static_cast<uint8_t>(value << 8 >> 24);
            uint8_t c = static_cast<uint8_t>(value << 16 >> 24);
            uint8_t d = static_cast<uint8_t>(value << 24 >> 24);

            byteCode.push_back(a);
            byteCode.push_back(b);
            byteCode.push_back(c);
            byteCode.push_back(d);
            break;
        }
    }
}

void compiler::data::CompilationFile::resolveSymbolReferences() {
    for(auto reference : symbolReferences){
        if(symbolTable_.find(reference.first) == symbolTable_.cend())
            throw error::reference_error("Unresolvable symbol \"" + reference.first + "\".");

        uint8_t a = static_cast<uint8_t>(symbolTable_.at(reference.first) >> 24);
        uint8_t b = static_cast<uint8_t>(symbolTable_.at(reference.first) << 8 >> 24);
        uint8_t c = static_cast<uint8_t>(symbolTable_.at(reference.first) << 16 >> 24);
        uint8_t d = static_cast<uint8_t>(symbolTable_.at(reference.first) << 24 >> 24);

        byteCode.at(reference.second + 1) = a;
        byteCode.at(reference.second + 2) = b;
        byteCode.at(reference.second + 3) = c;
        byteCode.at(reference.second + 4) = d;

    }
}
