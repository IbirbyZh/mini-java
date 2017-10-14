#pragma once

#include "INode.hpp"


namespace NNodes {

    class CBasicType : IType {
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