#include "TableEntry.h"

TableEntry::TableEntry() { }

TableEntry::TableEntry(int _location, int _length) : location(_location), length(_length) { }

int TableEntry::getLocation() {
    return location;
}

int TableEntry::getLength() {
    return length;
}