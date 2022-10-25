#include "StringBuffer.h"

#include <string>

StringBuffer *StringBuffer::instance = NULL;

StringBuffer::StringBuffer() { }

StringBuffer* StringBuffer::getInstance() {
    if (instance == NULL) {
        instance = new StringBuffer();
    }
    return instance;
}

// add a new string to the buffer
void StringBuffer::addString(std::string str) {
    buffer.push_back(str);
}

// returns the string at the given index
std::string StringBuffer::getString(int index) {
    return buffer[index];
}

// get the size of the buffer
int StringBuffer::getSize() {
    return buffer.size();
}
