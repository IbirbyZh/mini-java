#pragma once

#include "Symbol.hpp"

#include <unordered_map>
#include <string>

namespace NTable {

    class CStringInternist {
    public:
        static CStringInternist &GetInstance() {
            static CStringInternist instance;
            return instance;
        }

        const CSymbol *Intern(const std::string &src);
        const void PRINT();

        CStringInternist(CStringInternist const &) = delete;
        void operator=(CStringInternist const &)  = delete;
    private:
        CStringInternist() = default;

        std::unordered_map<std::string, CSymbol> stringToSymbol;
    };
}