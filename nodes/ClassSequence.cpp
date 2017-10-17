#include "ClassSequence.hpp"

NNodes::CClassSequence::CClassSequence
        (const std::shared_ptr<NNodes::CClassSequence> classes,
         const std::shared_ptr<NNodes::CClass> class_) : firstClasses(classes),
                                                         lastClass(class_) {}

void NNodes::CClassSequence::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}


void NNodes::CClassSequence::ToVector(std::vector<std::shared_ptr<NNodes::CClass>> classes) const {
    if (firstClasses) {
        firstClasses->ToVector(classes);
    }
    classes.push_back(lastClass);
}