#pragma once

#include "Symbol.hpp"
#include "VariableInfo.hpp"
#include "MethodInfo.hpp"
#include "Nodes.hpp"
#include <memory>
#include <unordered_map>

namespace NTable {
    class CClassInfo {
    public:
        CClassInfo() = delete;
        const CSymbol *GetName() const;
        const CSymbol *GetExtendsName() const;
        const std::unordered_map<const CSymbol *, const std::shared_ptr<const CVariableInfo>> &GetVariables() const;
        const std::unordered_map<const CSymbol *, const std::shared_ptr<const CMethodInfo>> &GetMethods() const;
        explicit CClassInfo(const std::shared_ptr<const NNodes::CClass> &_class);
    private:
        const CSymbol *name;
        const CSymbol *extendsName;
        std::unordered_map<const CSymbol *, const std::shared_ptr<const CVariableInfo>> variables;
        std::unordered_map<const CSymbol *, const std::shared_ptr<const CMethodInfo>> methods;
    };
}
