#pragma once

#include "INode.hpp"


namespace NNodes {

    class CBasicType : public IType {
        friend class NVisitor::CGraphvizPrinter;

    public:
        enum TType {
            BT_INT,
            BT_BOOL,
            BT_INT_ARRAY
        };

        explicit CBasicType(TType basicType);
        void Visit(NVisitor::IVisitor *visitor) const override;
        const std::string &ToString() const override;

    private:
        TType type;
        static const std::string INT;
        static const std::string BOOL;
        static const std::string INT_ARRAY;
    };
}