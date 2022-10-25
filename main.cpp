#include "InstructionBuffer.h"
#include "StringBuffer.h"
#include "SymbolTable.h"
#include "TableEntry.h"
#include "OpCodes.h"
#include "Stmt.h"

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <map>

/*
compile your program and produce an executable called comp
for the compiler part and vm for the interpreter part.

.pout is a text dump of you instruction buffer for the sake of debug 
(graded for part 1)

.out is a binary file that you will use in step 2. It needs to have all
information needed to run your program, which us likely both the 
instruction buffer and the string buffer (along with the amount of memory
reserved by the symbol table)
*/

int parseStatement(std::string statement){
    // returns 0 if no errors, 1 if error, 2 if end of program

    //get the first word of the statement
    std::string firstWord = statement.substr(0, statement.find(" "));

    // get the second word of the statement
    std::string secondWord = statement.substr(statement.find(" ") + 1, statement.length());

    // get the third word of the statement
    std::string thirdWord = statement.substr(statement.find(" ", statement.find(" ") + 1) + 1, statement.length());

    /*
    end: denotes the end of the source file. If non-blank characters follow the end statement 
    an error should be issued. If no end statement exists, and error should be issued. 
    */
    if(firstWord == "end"){
        // may need to be changed later
        if(statement.length() != firstWord.length()){
            std::cout << "Error: end statement should not have any characters after it" << std::endl;
            return 1; // error
        }
        else{
            return 2; // end statement found
        }
    }

    //else  if the command doesn't have an op code from the map
    else if(opCodeMap.find(firstWord) == opCodeMap.end()){
        if(firstWord == "declscal"){
            // create a table entry for the scalar variable
            TableEntry tableEntry(SymbolTable::getSize(), 1);
            // add the variable to the symbol table
            SymbolTable::getInstance()->addEntry(secondWord, tableEntry);
        }
        else if(firstWord == "declarr"){
            // get the third word of the statement (length of the array)
            std::string thirdWord = statement.substr(statement.find(" ", statement.find(" ") + 1) + 1, statement.length());
            // create a table entry for the array variable
            TableEntry tableEntry(SymbolTable::getSize(), std::stoi(thirdWord));
            // add the array to the symbol table
            SymbolTable::getInstance()->addEntry(secondWord, tableEntry);
        }
        else if(firstWord == "label"){
            // set line number equal to the size of the instruction buffer
            int lineNum = InstructionBuffer::getInstance()->getSize();
            // create a table entry for the label
            TableEntry tableEntry(lineNum, 0);
            // add the label to the symbol table
            SymbolTable::getInstance()->addEntry(secondWord, tableEntry);
        }
        else{
            std::cout << "Error: invalid command " << firstWord << std::endl;
            return 1; // error
        }
    }

    //the command has an op code from the map
    else{
        // get the op code from the map]
        int opCode = opCodeMap[firstWord];

        // set line number equal to the size of the instruction buffer
        int lineNum = InstructionBuffer::getInstance()->getSize();

        // create a new statement
        std::unique_ptr<Stmt> stmt = std::make_unique<Stmt>(firstWord, opCode, lineNum);

        // check if the statement needs an operand
        switch(stmt->needsOperand()){
            case 1: // int operand needed
                stmt->setOperand(std::stoi(secondWord));
                break;
            case 2: // string operand needed
                stmt->setOperand(secondWord);
                break;
            case 3: // special function
                if(firstWord == "prints"){ // send secondWord to the string buffer
                    StringBuffer::getInstance()->addString(secondWord);
                    // set the operand to the size of the string buffer
                    stmt->setOperand(StringBuffer::getInstance()->getSize() - 1);
                }
                if(firstWord == "jump" || firstWord == "jumpzero" || firstWord == "jumpnzero"){
                    // set the operand to the name of the label to be filled in later
                    stmt->setOperand(secondWord);
                }
                if(firstWord == "gosub"){ // set the operand to the name of the label to be filled in later
                    stmt->setOperand(secondWord);
                }
                if(firstWord == "gosublabel"){ // set the operand to the size of the instruction buffer upon completion
                    // set the symbol table scope to 1 (local)
                    SymbolTable::getInstance()->setScope(1);
                    // declares a label that can be the target of a gosub
                    TableEntry tableEntry(lineNum, 0);
                    // add the label to the symbol table
                    SymbolTable::getInstance()->addEntry(secondWord, tableEntry);
                }
                if(firstWord == "start"){}
                if(firstWord == "return"){
                    // set gosublabel's operand to the size of the local instruction buffer
                    
                    // set the symbol table scope to 0 (global)
                    SymbolTable::getInstance()->setScope(0);
                }
                if(firstWord == "pushscal" || firstWord == "pusharr" || firstWord == "popscal" || firstWord == "poparr"){
                    // set the operand to the name of the variable
                    stmt->setOperand(secondWord);
                    // get the table entry for the scalar variable
                    TableEntry tableEntry = SymbolTable::getInstance()->getEntry(secondWord);
                    // set the operand to the location of the scalar variable
                    // this will set the operand type to int so when serialized it will be an int
                    stmt->setOperand(tableEntry.getLocation());
                }
            case 0: // no operand needed
            default:
                break;
        }

        // add the statement to the instruction buffer
        InstructionBuffer::getInstance()->addStmt(std::move(stmt));
    }

    return 0; //return 0 if no errors
}


int main(int argc, char *argv[]) {

    // check if the user entered a file name
    if(argc < 2){
        std::cout << "Error: no file name entered" << std::endl;
        return 1;
    }

    std::string line;
    // open the file with the name given by the first argument
    std::ifstream myfile(argv[1]);
    if (myfile.is_open())
    {

        // initialize the instruction buffer with a smart pointer
        InstructionBuffer *instBuffer = InstructionBuffer::getInstance();
        // initialize the string buffer
        StringBuffer *strBuffer = StringBuffer::getInstance();
        // initialize the symbol table
        SymbolTable *symTable = SymbolTable::getInstance();

        int status = 0; // 0 if no errors, 1 if error, 2 if end of program

        while ( getline (myfile,line) && status == 0 )
        {
            // parse each statement line by line
            status = parseStatement(line);
        }
        myfile.close();

        // go back and fill in stack allocation as well as jump addresses
        instBuffer->getStmt(0)->setOperand(symTable->getSize());

        // print the instruction buffer
        for(int i = 0; i < instBuffer->getSize(); i++){
            // get a pointer to the current statement
            Stmt *stmt = instBuffer->getStmt(i);

            // if the statement is a jump statement
            if(stmt->name == "jump" || stmt->name == "jumpzero" || stmt->name == "jumpnzero"){
                // get the name of the label
                std::string labelName = stmt->getStringOperand();
                // get the line number of the label
                int lineNum = symTable->getEntry(labelName).getLocation();
                // set the operand to the line number of the label
                stmt->setOperand(lineNum);
            }
            std::cout << stmt->name << " ";
            if (stmt->opInitialized){
                stmt->printOperand();
            }
            std::cout << std::endl;
            delete stmt;
        }

        // print the symbol table
        

        // free pointers
        delete instBuffer;
        delete strBuffer;
        delete symTable;
    }

    else std::cout << "Unable to open file";
}
