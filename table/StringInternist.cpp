#include "StringInternist.hpp"

NTable::CStringInternist &NTable::CStringInternist::GetInstance() {
    static CStringInternist instance;
    return instance;
}

const NTable::CSymbol &NTable::CStringInternist::Intern(const std::string &src) {
    auto cached = stringToSymbol.find(src);
    if (cached != stringToSymbol.end()) {
        return cached->second;
    }
    stringToSymbol.insert({src, CSymbol(src, stringToSymbol.size())});
    return stringToSymbol.find(src)->second;
}
