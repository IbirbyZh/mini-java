#pragma once

#include "StringInternist.hpp"
#include "Symbol.hpp"
#include "Nodes.hpp"
#include <memory>

namespace NTable {

    class CVariableInfo {
    public:
        CVariableInfo() = delete;

        CVariableInfo(const CVariableInfo &other) = default;
        CVariableInfo &operator=(const CVariableInfo &other) = default;

        CVariableInfo(CVariableInfo &&other) = default;
        CVariableInfo &operator=(CVariableInfo &&other) = default;

        explicit CVariableInfo(const std::shared_ptr<const NNodes::CTypedId> &typedId);
        CVariableInfo(const CSymbol *nameSymbol, const CSymbol *typeSymbol);

        const CSymbol *GetType() const;
        const CSymbol *GetName() const;

    private:
        const CSymbol *type;
        const CSymbol *name;
    };
}

