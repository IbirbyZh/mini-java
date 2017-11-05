#include "VariableInfo.hpp"

NTable::CVariableInfo::CVariableInfo(const std::shared_ptr<const NNodes::CTypedId> &typedId)
        : name(NTable::CStringInternist::GetInstance().Intern(typedId->GetName())),
          type(NTable::CStringInternist::GetInstance().Intern(typedId->GetType()->ToString())) {

}
