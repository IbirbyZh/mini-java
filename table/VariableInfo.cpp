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

NTable::CVariableInfo::CVariableInfo(const NTable::CSymbol *nameSymbol, const NTable::CSymbol *typeSymbol)
        : name(nameSymbol),
          type(typeSymbol) {

}
