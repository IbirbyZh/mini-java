#include "TypedIdSequence.hpp"

NNodes::CTypedIdSequence::CTypedIdSequence
        (const std::shared_ptr<NNodes::CTypedIdSequence> typedIds,
         const std::shared_ptr<NNodes::CTypedId> typedId) : firstTypedIds(typedIds),
                                                            lastTypedId(typedId) {}

void NNodes::CTypedIdSequence::ToVector(std::vector<std::shared_ptr<const CTypedId>> &typedIds) const {
    if (firstTypedIds) {
        firstTypedIds->ToVector(typedIds);
    }
    if (lastTypedId) {
        typedIds.push_back(lastTypedId);
    }
}