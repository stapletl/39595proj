#include "InstructionBuffer.h"
#include "Stmt.h"

#include <vector>
#include <memory>

InstructionBuffer *InstructionBuffer::instance = NULL;

InstructionBuffer::InstructionBuffer() { }

InstructionBuffer* InstructionBuffer::getInstance() {
    if (instance == NULL) {
        instance = new InstructionBuffer();
    }
    return instance;
}

// add a new statement to the buffer
void InstructionBuffer::addStmt(std::unique_ptr<Stmt> stmt) {
    buffer.push_back(std::move(stmt));
}

// returns the statement at the given index
Stmt* InstructionBuffer::getStmt(int index) {
    return buffer[index].get();
}

// get the size of the buffer
int InstructionBuffer::getSize() {
    return buffer.size();
}
