#include "VariableInfo.hpp"

NTable::CVariableInfo::CVariableInfo(const std::shared_ptr<const NNodes::CTypedId> &typedId)
        : name(NTable::CStringInternist::GetInstance().Intern(typedId->GetName())),
          type(NTable::CStringInternist::GetInstance().Intern(typedId->GetType()->ToString())) {

}

const NTable::CSymbol *NTable::CVariableInfo::GetType() const {
    return type;
}

const NTable::CSymbol *NTable::CVariableInfo::GetName() const {
    return name;
}
