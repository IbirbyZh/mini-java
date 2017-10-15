#pragma once

#include "INode.hpp"


namespace NNodes {

    class CBasicType : public IType {
        friend class NVisitor::CPrettyPythonPrinter;

    public:
        enum TType {
            BT_INT,
            BT_BOOL,
            BT_INT_ARRAY
        };

        explicit CBasicType(TType basicType);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        TType type;
    };
}