#include "CallMethodParameters.hpp"

NNodes::CCallMethodParameters::CCallMethodParameters(
        const std::shared_ptr<NNodes::INode> callParameter,
        const std::shared_ptr<NNodes::CCallMethodParameters> nextParameters)
        : firstParameter(callParameter), additionalParameters(nextParameters) {

}

void NNodes::CCallMethodParameters::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

void NNodes::CCallMethodParameters::ToVector(std::vector<std::shared_ptr<NNodes::INode>> &parameters) const {
    parameters.push_back(firstParameter);
    if (additionalParameters) {
        additionalParameters->ToVector(parameters);
    }

}
