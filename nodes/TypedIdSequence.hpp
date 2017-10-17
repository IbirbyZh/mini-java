#pragma once

#include "INode.hpp"
#include "TypedId.hpp"
#include <memory>
#include <vector>


namespace NNodes {

    class CTypedIdSequence : public INode {
        friend class NVisitor::CPrettyPythonPrinter;

        friend class NVisitor::CGraphvizPrinter;

    public:
        CTypedIdSequence(std::shared_ptr<CTypedIdSequence> typedIds,
                         std::shared_ptr<CTypedId> typedId);
        void Visit(NVisitor::IVisitor *visitor) const override;
        void ToVector(std::vector<std::shared_ptr<CTypedId>>& typedIds) const;

    private:
        const std::shared_ptr<CTypedIdSequence> firstTypedIds;
        const std::shared_ptr<CTypedId> lastTypedId;
    };
}