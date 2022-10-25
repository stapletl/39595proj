#include <iostream>
#include "SymbolTable.h"
#include "TableEntry.h"
#include <vector>
#include <string>
#include <map>

SymbolTable *SymbolTable::instance = NULL;
std::vector<int> SymbolTable::memSize {0, 0};
std::vector<int> SymbolTable::numVar {0, 0};
int SymbolTable::scope = 0; // 0 for global, 1 for local

SymbolTable::SymbolTable() { }

SymbolTable *SymbolTable::getInstance() {
    if (instance == NULL) {
        instance = new SymbolTable();
    }
    return instance;
}

void SymbolTable::addEntry(std::string key, TableEntry entry) {
    // if table[scope] does not exist, create it
    if (table.size() <= scope) {
        table.push_back(std::map<std::string, TableEntry>());
    }
    table[scope][key] = entry;
    memSize[scope] += entry.getLength();
    numVar[scope]++;
}

TableEntry SymbolTable::getEntry(std::string key) {
    return table[scope][key];
}

int SymbolTable::getSize() {
    return memSize[scope];
}

int SymbolTable::getNumVar() {
    return numVar[scope];
}

void SymbolTable::setScope(int _scope) {
    scope = _scope;

    // if setting scope to global, reset memsize[1], numVar[1], and table[1]
    if (scope == 0) {
        memSize[1] = 0;
        numVar[1] = 0;
        table[1].clear();
    }
}

