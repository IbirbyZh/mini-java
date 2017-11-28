#include "MethodInfo.hpp"
#include "StringInternist.hpp"

NTable::CMethodInfo::CMethodInfo(const std::shared_ptr<const NNodes::CMethod> &method)
        : name(NTable::CStringInternist::GetInstance().Intern(method->GetSignature()->GetName())),
          type(NTable::CStringInternist::GetInstance().Intern(method->GetSignature()->GetType()->ToString())) {
    NTable::CStringInternist &internist = NTable::CStringInternist::GetInstance();
    CStringInternist &stringInternist = NTable::CStringInternist::GetInstance();
    for (auto &&item: method->GetSignature()->GetParameters()) {
        positionParameters.push_back(stringInternist.Intern(item->GetType()->ToString()));
        parameters.insert(std::make_pair(stringInternist.Intern(item->GetName()), std::make_shared<CVariableInfo>(item)));
    }
    for (auto &&item: method->GetVariables()) {
        variables.insert(
                std::make_pair(stringInternist.Intern(item->GetName()), std::make_shared<CVariableInfo>(item))
        );
    }
}

const NTable::CSymbol *NTable::CMethodInfo::GetType() const {
    return type;
}

const NTable::CSymbol *NTable::CMethodInfo::GetName() const {
    return name;
}

const std::unordered_map<const NTable::CSymbol *, const std::shared_ptr<const NTable::CVariableInfo>> &
NTable::CMethodInfo::GetVariables() const {
    return variables;
}

const std::unordered_map<const NTable::CSymbol *, const std::shared_ptr<const NTable::CVariableInfo>> &
NTable::CMethodInfo::GetParameters() const {
    return parameters;
}

const std::vector<const NTable::CSymbol *> &NTable::CMethodInfo::GetPositionParameters() const {
    return positionParameters;
}
