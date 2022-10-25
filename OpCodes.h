#ifndef OPCODES_H_
#define OPCODES_H_

#include <string>
#include <map>

// Control Statements
static const int OP_JUMP = 0x00000010;
static const int OP_JUMPZERO = 0x00000011;
static const int OP_JUMPNZERO = 0x00000012;
static const int OP_GOSUB = 0x00000013;
static const int OP_RETURN = 0x00000014;
static const int OP_ENTER_SUBROUTINE = 0x00000015;
static const int OP_EXIT_SUBROUTINE = 0x00000016;
static const int OP_START_PROGRAM = 0x00000017;
static const int OP_EXIT_PROGRAM = 0x00000018;

// Push Statements
static const int OP_PUSHSCALAR = 0x00000020;
static const int OP_PUSHARRAY = 0x00000021;
static const int OP_PUSHI = 0x00000022;

// Pop Statements
static const int OP_POPSCALAR = 0x00000030;
static const int OP_POPARRAY = 0x00000031;
static const int OP_POP = 0x00000032;

// Helper Statements
static const int OP_DUP = 0x00000040;
static const int OP_SWAP = 0x00000041;

// Arithmetic Statements
static const int OP_ADD = 0x00000050;
static const int OP_NEGATE = 0x00000051;
static const int OP_MUL = 0x00000052;
static const int OP_DIV = 0x00000053;

// Print Statements
static const int OP_PRINTS = 0x00000060;
static const int OP_PRINTTOS = 0x00000061;

extern std::map<std::string, int> opCodeMap;

#endif /* OPCODES_H_ */