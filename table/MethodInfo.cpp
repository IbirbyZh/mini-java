#include "MethodInfo.hpp"

NTable::CMethodInfo::CMethodInfo(const std::shared_ptr<const NNodes::CMethod> &method)
        : name(NTable::CStringInternist::GetInstance().Intern(method->GetSignature()->GetName())),
          type(NTable::CStringInternist::GetInstance().Intern(method->GetSignature()->GetType()->ToString())) {
    NTable::CStringInternist &internist = NTable::CStringInternist::GetInstance();
    for (auto &&item: method->GetSignature()->GetParameters()) {
        parameters.emplace_back(item);
    }
    for (auto &&item: method->GetVariables()) {
        variables.emplace_back(item);
    }
}
