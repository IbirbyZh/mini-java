#include "Symbol.hpp"


NTable::CSymbol::CSymbol(const std::string &src, size_t ind) : name(src), index(ind) {}

bool NTable::CSymbol::operator==(const NTable::CSymbol &other) const {
    return index == other.index;
}

const std::string &NTable::CSymbol::ToString() const {
    return name;
}
