#ifndef INSTRUCTIONBUFFER_H_
#define INSTRUCTIONBUFFER_H_

#include "Stmt.h"

#include <vector>
#include <memory>

/*
As code is generated for statements, the code is put into an array of Stmt
smart unique pointers. All statements (except label statements and declaration
statements) occupy one location in the program buffer. This should be implemented as a singleton.
*/

class InstructionBuffer {
private:
    static InstructionBuffer *instance; // the singleton instance
    InstructionBuffer();

    std::vector<std::unique_ptr<Stmt>> buffer; // the array of statements

public:
    static InstructionBuffer* getInstance(); // returns the singleton instance

    void addStmt(std::unique_ptr<Stmt> stmt); // adds a new statement to the buffer
    Stmt* getStmt(int index); // returns the statement at the given index
    int getSize(); // get the size of the buffer
};
#endif /* INSTRUCTIONBUFFER_H_ */
