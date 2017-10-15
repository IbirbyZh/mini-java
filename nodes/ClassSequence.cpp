#include "ClassSequence.hpp"

NNodes::CClassSequence::CClassSequence
        (const std::shared_ptr<NNodes::CClassSequence> classes,
         const std::shared_ptr<NNodes::CClass> class_) : firstClasses(classes),
                                                        lastClass(class_) {}

void NNodes::CClassSequence::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
