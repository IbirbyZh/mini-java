#pragma once

#include "Symbol.hpp"
#include "VariableInfo.hpp"
#include "Nodes.hpp"
#include <memory>
#include <unordered_map>
#include <vector>

namespace NTable {
    class CMethodInfo {
    public:
        CMethodInfo() = delete;
        explicit CMethodInfo(const std::shared_ptr<const NNodes::CMethod> &method);
        const CSymbol *GetType() const;
        const CSymbol *GetName() const;
        const std::unordered_map<const CSymbol *, const std::shared_ptr<const CVariableInfo>> &GetVariables() const;
        const std::unordered_map<const CSymbol *, const std::shared_ptr<const CVariableInfo>> &GetParameters() const;
        const std::vector<const CSymbol *> &GetPositionParameters() const;
    private:
        const CSymbol *type;
        const CSymbol *name;
        std::unordered_map<const CSymbol *, const std::shared_ptr<const CVariableInfo>> variables;
        std::unordered_map<const CSymbol *, const std::shared_ptr<const CVariableInfo>> parameters;
        std::vector<const CSymbol *> positionParameters;
    };
}

