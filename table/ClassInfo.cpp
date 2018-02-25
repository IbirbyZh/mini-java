#include "ClassInfo.hpp"
#include "StringInternist.hpp"

NTable::CClassInfo::CClassInfo(const std::shared_ptr<const NNodes::CClass> &_class)
        : name(NTable::CStringInternist::GetInstance().Intern(_class->GetName())),
          extendsName(
                  _class->GetExtendsName().size() > 0 ?
                  NTable::CStringInternist::GetInstance().Intern(_class->GetExtendsName()) :
                  nullptr) {
    CStringInternist &stringInternist = NTable::CStringInternist::GetInstance();
    for (auto &&item: _class->GetVariables()) {
        variables.insert(
                std::make_pair(stringInternist.Intern(item->GetName()),
                               std::make_shared<const CVariableInfo>(item))
        );
    }
    for (auto &&item: _class->GetMethods()) {
        methods.insert(
                std::make_pair(stringInternist.Intern(item->GetSignature()->GetName()),
                               std::make_shared<const CMethodInfo>(item, name))
        );
    }
}

const NTable::CSymbol *NTable::CClassInfo::GetName() const {
    return name;
}

const NTable::CSymbol *NTable::CClassInfo::GetExtendsName() const {
    return extendsName;
}

const std::unordered_map<const NTable::CSymbol *, const std::shared_ptr<const NTable::CVariableInfo>> &
NTable::CClassInfo::GetVariables() const {
    return variables;
}

const std::unordered_map<const NTable::CSymbol *, const std::shared_ptr<const NTable::CMethodInfo>> &
NTable::CClassInfo::GetMethods() const {
    return methods;
}
