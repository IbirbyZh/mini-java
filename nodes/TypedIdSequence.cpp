#include "TypedIdSequence.hpp"

NNodes::CTypedIdSequence::CTypedIdSequence
        (const std::shared_ptr<NNodes::CTypedIdSequence> typedIds,
         const std::shared_ptr<NNodes::INode> typedId) : firstTypedIds(typedIds),
                                                         lastTypedId(typedId) {}

void NNodes::CTypedIdSequence::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
