#include "OpCodes.h"

#include <string>
#include <map>

std::map<std::string, int> opCodeMap = {
    {"jump", OP_JUMP},
    {"jumpzero", OP_JUMPZERO},
    {"jumpnzero", OP_JUMPNZERO},
    {"gosub", OP_GOSUB},
    {"return", OP_RETURN},
    {"gosublabel", OP_ENTER_SUBROUTINE},
    {"exit", OP_EXIT_SUBROUTINE},
    {"start", OP_START_PROGRAM},
    {"exit", OP_EXIT_PROGRAM},
    {"pushscal", OP_PUSHSCALAR},
    {"pusharr", OP_PUSHARRAY},
    {"pushi", OP_PUSHI},
    {"popscal", OP_POPSCALAR},
    {"poparr", OP_POPARRAY},
    {"pop", OP_POP},
    {"dup", OP_DUP},
    {"swap", OP_SWAP},
    {"add", OP_ADD},
    {"negate", OP_NEGATE},
    {"mul", OP_MUL},
    {"div", OP_DIV},
    {"prints", OP_PRINTS},
    {"printtos", OP_PRINTTOS}
};
/*
Commands with no opCode

declscal: declares a scalar variable. The variable name is the second word of the statement.
declarr: declares an array variable. The variable name is the second word of the statement, the size is the third word of the statement.
label: defines a label. The label name is the second word of the statement.
*/
