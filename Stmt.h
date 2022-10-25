#ifndef STMT_H_
#define STMT_H_

#include <string>

/*
Stmt will be an abstract class, and different statements will have their own
concrete classes that extend the Stmt class

possible statement types:
stmt
stmt var
stmt var length
stmt label
stmt int
stmt location

var is a variable name
length is the length of the array
label is a label name
int is an integer
location is a location in memory

*/

class Stmt {
private:
    int intOperand; // integer operand
    std::string stringOperand; // string operand
public:
    std::string name; // the name of the statement
    int opCode; // the op code of the statement
    int lineNum; // the line number of the statement

    int needsOperand(); // 0 if no, 1 if int, 2 if string, 3 if special function
    int opInitialized; // 0 if not, 1 if int initialized, 2 if string initialized, 3 if both initialized
    virtual void setOperand(int operand); // sets the operand
    virtual void setOperand(std::string operand); // sets the operand
    virtual void setOperand(std::string operand1, int operand2); // sets the operands
    int getIntOperand(); // returns the integer operand
    std::string getStringOperand(); // returns the string operand

    void printOperand(); // prints the operand(s)

    Stmt(std::string _name, int _opCode, int _lineNum);

    // serialize, check opInitialized
    //virtual void serialize();

};
#endif /* STMT_H_ */