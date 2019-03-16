//
// Created by Ali A. Kooshesh on 2/5/19.
//

#ifndef EXPRINTER_SYMTAB_HPP
#define EXPRINTER_SYMTAB_HPP

#include "TypeDescriptor.hpp"
#include <string>
#include <map>

// This is a flat symbol table. It allows for variables to be
// initialized, determines if a give variable has been defined or not, and if
// a variable has been defined, it returns its value.

class SymTab {
public:
    void setValueFor(std::string vName, int value);
    bool isDefined(std::string vName);
    int getValueFor(std::string vName);

private:
    std::map<std::string, int> symTab;
};

#endif //EXPRINTER_SYMTAB_HPP
