//
// Created by a_mod on 29.07.2018.
//

#ifndef VM2_0_COMPILER_INSTRUCTIONMAP_H
#define VM2_0_COMPILER_INSTRUCTIONMAP_H

#include <unordered_map>
#include <cstdint>

namespace compiler::data::InstructionMap{

     const std::unordered_map<std::string, uint8_t> nameToOp = {
             {"readRegister0", 0xa0}, {"readRegister1", 0xa1}, {"readRegister2", 0xa2},
             {"readRegister3", 0xa3}, {"readRegister4", 0xa4}, {"readRegister5", 0xa5},
             {"readRegister6", 0xa6}, {"readRegister7", 0xa7}, {"readRegister8", 0xa8},
             {"readRegister9", 0xa9},

             {"setRegister0", 0xb0}, {"setRegister1", 0xb1}, {"setRegister2", 0xb2},
             {"setRegister3", 0xb3}, {"setRegister4", 0xb4}, {"setRegister5", 0xb5},
             {"setRegister6", 0xb6}, {"setRegister7", 0xb7}, {"setRegister8", 0xb8},
             {"setRegister9", 0xb9},

             {"setSize", 0xc0}, {"move", 0xc1}, {"read", 0xc2}, {"alloc", 0xc3},
             {"push", 0xd0}, {"remove", 0xd1}, {"uadd", 0xe0}, {"sadd", 0xe1},
             {"fadd", 0xe2}, {"usub", 0xe3}, {"ssub", 0xe4}, {"fsub", 0xe5},
             {"umult", 0xe6}, {"smult", 0xe7}, {"fmult", 0xe8}, {"udiv", 0xe9},
             {"sdiv", 0xea}, {"fdiv", 0xeb}, {"utof", 0xec}, {"stof", 0xed},
             {"abs", 0xee}, {"ucmp", 0xef}, {"scmp", 0xf0}, {"fcmp", 0xf1},
             {"jmp", 0x01}, {"jless", 0x02}, {"jgreater", 0x03}, {"jequal", 0x04},
             {"jNequal", 0x05}, {"call", 0x06}, {"return", 0x07}, {"int", 0x10},
             {"halt", 0x11}, {"noop", 0x12}, {"unsignedOut", 0x13}, {"signedOut", 0x14},
             {"floatOut", 0x15}, {"charOut", 0x16}
     };
}

#endif //VM2_0_COMPILER_INSTRUCTIONMAP_H
