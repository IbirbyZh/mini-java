#pragma once

#include "Symbol.hpp"

#include <unordered_map>
#include <string>

namespace NTable {

    class CStringInternist {
    public:
        static CStringInternist &GetInstance();
        const CSymbol &Intern(const std::string &src);

        CStringInternist(CStringInternist const &) = delete;
        void operator=(CStringInternist const &)  = delete;
    private:
        CStringInternist() = default;;

        std::unordered_map<std::string, CSymbol> stringToSymbol;
    };
}