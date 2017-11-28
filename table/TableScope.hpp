#pragma once

#include "ClassInfo.hpp"
#include "MethodInfo.hpp"
#include "VariableInfo.hpp"
#include "Nodes.hpp"
#include "Symbol.hpp"
#include "StringInternist.hpp"
#include <unordered_map>
#include <vector>
#include <memory>
#include <functional>

namespace NTable {
    class CTableScope {
    public:
        CTableScope() = delete;
        CTableScope(
                const std::shared_ptr<const CClassInfo> &classInfo,
                const std::shared_ptr<const CMethodInfo> &methodInfo,
                const std::unordered_map<const CSymbol *, const std::shared_ptr<const CClassInfo>> &classesInfo
        );

        const std::shared_ptr<const CVariableInfo> &FindName(const CSymbol *name) const;
        const CSymbol *GetCurrentClass() const;
        const CSymbol *GetCurrentMethod() const;
    private:
        const CSymbol *currentClass;
        const CSymbol *currentMethod;
        const std::unordered_map<const CSymbol *, const std::shared_ptr<const CVariableInfo>> &methodParameters;
        const std::unordered_map<const CSymbol *, const std::shared_ptr<const CVariableInfo>> &methodVariables;
        std::vector<const std::unordered_map<const CSymbol *, const std::shared_ptr<const CVariableInfo>> *> classVariables;
    };
}