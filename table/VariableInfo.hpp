#pragma once

#include "StringInternist.hpp"
#include "Symbol.hpp"
#include "Nodes.hpp"
#include <memory>

namespace NTable {

    class CVariableInfo {
    public:
        CVariableInfo() = delete;
        explicit CVariableInfo(const std::shared_ptr<const NNodes::CTypedId>& typedId);
    private:
        const CSymbol& type;
        const CSymbol& name;
    };
}

