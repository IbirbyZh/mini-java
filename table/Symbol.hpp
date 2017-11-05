#pragma once

#include <string>

namespace NTable {
    class CSymbol {
    public:
        CSymbol() = delete;
        CSymbol(const std::string &src, size_t ind);

        bool operator==(const CSymbol &other) const;
        const std::string &ToString() const;

    private:
        const std::string name;
        const size_t index;
    };
}