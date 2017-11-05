#pragma once

#include "StringInternist.hpp"
#include "Symbol.hpp"
#include "VariableInfo.hpp"
#include "Nodes.hpp"
#include <memory>
#include <vector>

namespace NTable {
    class CMethodInfo {
    public:
        CMethodInfo() = delete;
        explicit CMethodInfo(const std::shared_ptr<const NNodes::CMethod> &method);
    private:
        const CSymbol &type;
        const CSymbol &name;
        std::vector<CVariableInfo> variables;
        std::vector<CVariableInfo> parameters;
    };
}

