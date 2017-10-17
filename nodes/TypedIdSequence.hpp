#pragma once

#include "INode.hpp"
#include "TypedId.hpp"
#include <memory>
#include <vector>


namespace NNodes {

    class CTypedIdSequence {
    public:
        CTypedIdSequence(
                const std::shared_ptr<CTypedIdSequence> typedIds,
                const std::shared_ptr<CTypedId> typedId
        );

        void ToVector(std::vector<std::shared_ptr<const CTypedId>> &typedIds) const;

    private:
        const std::shared_ptr<CTypedIdSequence> firstTypedIds;
        const std::shared_ptr<CTypedId> lastTypedId;
    };
}