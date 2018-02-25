#pragma once

#include <string>
#include <functional>

namespace NTable {
    class CSymbol {
    public:
        CSymbol() = delete;
        CSymbol(const std::string &src, size_t ind);

        CSymbol(const CSymbol &other) = default;
        CSymbol &operator=(const CSymbol &other) = default;

        CSymbol(CSymbol &&other) = default;
        CSymbol &operator=(CSymbol &&other) = default;

        const std::string &ToString() const;

    private:
        const std::string name;
    };
}