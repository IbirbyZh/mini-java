#include "StringInternist.hpp"
#include <iostream>

const NTable::CSymbol *NTable::CStringInternist::Intern(const std::string &src) {
    auto cached = stringToSymbol.find(src);
    if (cached != stringToSymbol.end()) {
        return &(cached->second);
    }
    stringToSymbol.insert({src, CSymbol(src, stringToSymbol.size())});
    return &(stringToSymbol.find(src)->second);
}

const void NTable::CStringInternist::PRINT() {
    std::cout << std::endl;
    for (auto &&item: stringToSymbol) {
        std::cout << &item.second << ' ' << item.first << std::endl;
    }
}
