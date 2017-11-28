#include "Program.hpp"
#include <iostream>

NNodes::CProgram::CProgram(const std::shared_ptr<NNodes::CMain> mainClass,
                           const std::shared_ptr<NNodes::CClassSequence> additionalClasses)
        : main(mainClass), classes() {
    if (additionalClasses) {
        additionalClasses->ToVector(classes);
    }
}

void NNodes::CProgram::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}

const std::vector<std::shared_ptr<const NNodes::CClass>> &NNodes::CProgram::GetClasses() const {
    return classes;
}

const std::shared_ptr<NNodes::CMain> &NNodes::CProgram::GetMain() const {
    return main;
}
