#ifndef TABLEENTRY_H_
#define TABLEENTRY_H_

#include <string>

/*
This is the data part for the symbol table, and is a <location, length> double which gives the
location in memory (variable) or in the program (label) of the symbol and the length of the data
associated with the symbol. For scalar variables the length is 1, for array variables it is the
length of the array, and for labels the length is 0.
*/

class TableEntry {
private:
   int location; // location in memory or in the program
   int length; // length of the data associated with the symbol
public:
   TableEntry();
   TableEntry(int _location, int _length);
   int getLocation();
   int getLength();
};
#endif /* TABLEENTRY_H_ */
