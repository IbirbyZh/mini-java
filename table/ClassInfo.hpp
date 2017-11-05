#pragma once

#include "StringInternist.hpp"
#include "Symbol.hpp"
#include "VariableInfo.hpp"
#include "MethodInfo.hpp"
#include "Nodes.hpp"
#include <memory>
#include <vector>

namespace NTable {
    class CClassInfo {
    public:
        CClassInfo() = delete;
        explicit CClassInfo(const std::shared_ptr<const NNodes::CClass> &_class);
    private:
        const CSymbol &name;
        const CSymbol &extendsName;
        std::vector<CVariableInfo> variables;
        std::vector<CMethodInfo> methods;
    };
}
