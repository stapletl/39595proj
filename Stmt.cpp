#include "Stmt.h"
#include "OpCodes.h"
#include "StringBuffer.h"

#include <string>
#include <iostream>

Stmt::Stmt(std::string _name, int _opCode, int _lineNum) : name(_name), opCode(_opCode), lineNum(_lineNum) { }

int Stmt::needsOperand(){ // 0 if no, 1 if int, 2 if string, 3 if special function
    switch(opCode){
        case OP_PUSHI:
            return 1;
            break;
        case -1: // no case?
            return 2;
            break;
        case OP_PUSHSCALAR:
        case OP_POPSCALAR:
        case OP_POPARRAY:
        case OP_PUSHARRAY:
        case OP_ENTER_SUBROUTINE:
        case OP_GOSUB:
        case OP_JUMP:
        case OP_JUMPZERO:
        case OP_JUMPNZERO:
        case OP_PRINTS:
        case OP_START_PROGRAM:
        case OP_RETURN:
            return 3;
            break;
        default:
            return 0;
            break;
    }


    if(opCode == OP_PUSHI){
        return 1;
    }
    return 0;
}

void Stmt::setOperand(int operand) {
    intOperand = operand;
    opInitialized = 1;
}

void Stmt::setOperand(std::string operand) {
    stringOperand = operand;
    opInitialized = 2;
}

void Stmt::setOperand(std::string operand1, int operand2) {
    stringOperand = operand1;
    intOperand = operand2;
    opInitialized = 3;
}

int Stmt::getIntOperand() {
    return intOperand;
}

std::string Stmt::getStringOperand() {
    return stringOperand;
}

void Stmt::printOperand() {
    if(opCode == OP_PRINTS){
        std::cout << StringBuffer::getInstance()->getString(intOperand);
        return;
    }
    else if(opCode == OP_PUSHSCALAR || opCode == OP_PUSHARRAY || opCode == OP_POPSCALAR || opCode == OP_POPARRAY){
        // print the variable name from the symbol table then the location
        std::cout << stringOperand << " " << intOperand;
        return;
    }
    if(opInitialized == 1){
        std::cout << intOperand;
    }
    else if(opInitialized == 2){
        std::cout << stringOperand;
    }
    else if(opInitialized == 3){
        std::cout << stringOperand << " " << intOperand;
    }
}