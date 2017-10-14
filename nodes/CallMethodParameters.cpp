#include "CallMethodParameters.hpp"

NNodes::CCallMethodParameters::CCallMethodParameters(
        const std::shared_ptr<NNodes::INode> callParameter,
        const std::shared_ptr<NNodes::CCallMethodParameters> nextParameters)
        : firstParameter(callParameter), additionalParameters(nextParameters) {

}

void NNodes::CCallMethodParameters::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
