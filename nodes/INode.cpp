#include "INode.hpp"

void NNodes::IStatement::Visit(NVisitor::IVisitor *visitor) const {
    throw;
}

void NNodes::IStatement::ToVector(std::vector<std::shared_ptr<const IStatement>> &actions) const {
    actions.push_back(shared_from_this());
}