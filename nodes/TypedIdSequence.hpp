#pragma once

#include "INode.hpp"
#include "TypedId.hpp"
#include <memory>

namespace NNodes {

    class CTypedIdSequence : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

    public:
        CTypedIdSequence(std::shared_ptr<CTypedIdSequence> typedIds,
                        std::shared_ptr<INode> typedId);
        void Visit(NVisitor::IVisitor *visitor) const override;

    private:
        const std::shared_ptr<CTypedIdSequence> firstTypedIds;
        const std::shared_ptr<INode> lastTypedId;
    };
}