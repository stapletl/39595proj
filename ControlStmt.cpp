#include "ControlStmt.h"
#include "Stmt.h"

#include <string>

ControlStmt::ControlStmt(std::string _name, int _opCode) : name(_name), opCode(_opCode) { }

std::string ControlStmt::getName() {
    return name;
}

int ControlStmt::getOpCode() {
    return opCode;
}