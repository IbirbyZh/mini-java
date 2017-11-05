#include "ClassInfo.hpp"

NTable::CClassInfo::CClassInfo(const std::shared_ptr<const NNodes::CClass> &_class)
        : name(NTable::CStringInternist::GetInstance().Intern(_class->GetName())),
          extendsName(NTable::CStringInternist::GetInstance().Intern(_class->GetExtendsName())) {
    for (auto &&item: _class->GetVariables()) {
        variables.emplace_back(item);
    }
    for (auto &&item: _class->GetMethods()) {
        methods.emplace_back(item);
    }
}
