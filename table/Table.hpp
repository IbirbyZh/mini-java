#pragma once

#include "ClassInfo.hpp"
#include "Nodes.hpp"
#include "Symbol.hpp"
#include "TableScope.hpp"
#include "StringInternist.hpp"
#include <unordered_map>
#include <vector>
#include <memory>

namespace NTable {
    class CTable {
    public:
        CTable() = delete;
        explicit CTable(const NNodes::CProgram *const program);

        void AddScope(const CSymbol *className, const CSymbol *methodName);
        void PopScope();

        const std::shared_ptr<const CVariableInfo> &FindNameInScope(const CSymbol *name) const;
        const std::shared_ptr<const CVariableInfo> &FindNameInScope(const std::string &name) const;

        const CSymbol *GetCurrentClass() const;

        const std::shared_ptr<const CMethodInfo> &
        GetMethodInfo(const CSymbol *className, const CSymbol *methodName) const;
        const std::shared_ptr<const CMethodInfo> &
        GetMethodInfo(const std::string &className, const std::string &methodName) const;

        const std::shared_ptr<const CClassInfo> &GetClassInfo(const CSymbol *className) const;
        const std::shared_ptr<const CClassInfo> &GetClassInfo(const std::string &className) const;

        bool IsValidParentClasses(const CSymbol *className) const;
        bool IsValidParentClasses(const std::string &className) const;

    private:
        std::unordered_map<const CSymbol *, const std::shared_ptr<const CClassInfo>> classesInfo;
        std::vector<const CTableScope> scopes;

    };
}