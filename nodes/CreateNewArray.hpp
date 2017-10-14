#pragma once

#include "INode.hpp"

namespace NNodes {

    class CCreateNewArray : INode {
    public:
        explicit CCreateNewArray(int arraySize);
        void Visit(NVisitor::IVisitor *visitor) const override;
    private:
        const int size;
    };
}
