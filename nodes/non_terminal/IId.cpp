//
// Created by Евгений Шишкин on 14.10.17.
//

#include "IId.hpp"

namespace NNonTerminal {
    CId::CId(char *name, TIdType type) : id(name), idType(type) {}

    void CId::Visit(NVisitor::IVisitor *const visitor) const {
        visitor->Visit(this);
    }

    const std::string &CId::GetId() const {
        return id;
    }

    TIdType CId::GetIdType() const {
        return idType;
    }
}