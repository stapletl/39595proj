#ifndef CONTROLSTMT_H_
#define CONTROLSTMT_H_

#include <string>

/*
Inherent from Stmt class

*/

class ControlStmt {
private:
    std::string name = 0; // the name of the statement
    int opCode = 0; // the op code of the statement

public:
    ControlStmt(std::string _name, int _opCode);
    std::string getName();
    int getOpCode();
};
#endif /* CONTROLSTMT_H_ */