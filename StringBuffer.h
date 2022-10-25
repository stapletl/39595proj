#ifndef STRINGBUFFER_H_
#define STRINGBUFFER_H_

#include <vector>
#include <string>

/*
The prints instruction specifies a string to be printed. This buffer holds these strings.
*/

class StringBuffer {
private:
    static StringBuffer *instance; // the singleton instance
    StringBuffer();

    std::vector<std::string> buffer; // the array of strings

public:
    static StringBuffer *getInstance(); // returns the singleton instance

    void addString(std::string str); // adds a new string to the buffer
    std::string getString(int index); // returns the string at the given index
    int getSize(); // get the size of the buffer

};
#endif /* STRINGBUFFER_H_ */
