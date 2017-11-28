#include "TableScope.hpp"

NTable::CTableScope::CTableScope(
        const std::shared_ptr<const NTable::CClassInfo> &classInfo,
        const std::shared_ptr<const NTable::CMethodInfo> &methodInfo,
        const std::unordered_map<const NTable::CSymbol *, const std::shared_ptr<const NTable::CClassInfo>> &classesInfo
)
        : methodParameters(methodInfo->GetParameters()),
          methodVariables(methodInfo->GetVariables()),
          currentClass(classInfo->GetName()),
          currentMethod(methodInfo->GetName()) {
    classVariables.push_back(&classInfo->GetVariables());
    auto &&parentClass = classInfo->GetName();
    while (parentClass != nullptr) {
        auto &&parentClassInfo = classesInfo.find(parentClass)->second;
        classVariables.push_back(&parentClassInfo->GetVariables());
        parentClass = parentClassInfo->GetExtendsName();
    }
}

const std::shared_ptr<const NTable::CVariableInfo> &NTable::CTableScope::FindName(const NTable::CSymbol *name) const {
    auto &&localName = methodParameters.find(name);
    if (localName != methodParameters.end()) {
        return localName->second;
    }
    localName = methodVariables.find(name);
    if (localName != methodVariables.end()) {
        return localName->second;
    }
    for (auto &&item: classVariables) {

        localName = item->find(name);
        if (localName != item->end()) {
            return localName->second;
        }
    }
    return nullptr;
}

const NTable::CSymbol *NTable::CTableScope::GetCurrentClass() const {
    return currentClass;
}

const NTable::CSymbol *NTable::CTableScope::GetCurrentMethod() const {
    return currentMethod;
}

