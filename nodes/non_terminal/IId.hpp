#pragma once

#include "IVisitor.hpp"
#include <string>

namespace NVisitor{
    class IVisitor;
}

namespace NNonTerminal {
    enum TIdType {
        T_MethodName,
        T_ClassName,
        T_VariableName,
    };

    class IId {
    public:
        virtual ~IId() {}

        virtual void Visit(NVisitor::IVisitor *const visitor) const = 0;
    };


    class CId : IId {
    public:
        CId(char *name, TIdType type);

        void Visit(NVisitor::IVisitor *const visitor) const override;

        const std::string &GetId() const;
        TIdType GetIdType() const;

    private:
        std::string id;
        TIdType idType;
    };
}

