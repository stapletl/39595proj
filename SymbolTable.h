#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "TableEntry.h"
#include <vector>
#include <string>
#include <map>

/*
The symbol table is a map from a variable or label that is the key to a
table entry. The symbol table should be implemented as a singleton.
*/

class SymbolTable {
private:
   // memSize[0] is the size of the global scope
   // memSize[1] is the size of the local scope
   static std::vector<int> memSize; // static size of the memory
   static std::vector<int> numVar; // static number of variables
   static int scope; // static scope
   static SymbolTable *instance; // the singleton instance
   SymbolTable();

   // table[0] holds the SymbolTable for the outer scope
   // table[1] holds the SymbolTable for the inner scope
   std::vector<std::map<std::string, TableEntry>> table; // the array of statements

public:
   static SymbolTable *getInstance(); // returns the singleton instance

   void addEntry(std::string key, TableEntry entry); // adds a new entry to the table
   TableEntry getEntry(std::string key); // returns the entry for the given key
   static int getSize();
   static int getNumVar();

   void setScope(int _scope);
};
#endif /* SYMBOLTABLE_H_ */
