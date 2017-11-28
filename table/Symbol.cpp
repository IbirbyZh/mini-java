#include "Symbol.hpp"
#include <iostream>


NTable::CSymbol::CSymbol(const std::string &src, size_t ind) : name(src) {}


const std::string &NTable::CSymbol::ToString() const {
    return name;
}
