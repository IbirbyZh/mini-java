#include "Program.hpp"

NNodes::CProgram::CProgram(const std::shared_ptr<NNodes::CMain> mainClass,
                           const std::shared_ptr<NNodes::CClassSequence> additionalClasses)
        : main(mainClass), classes(additionalClasses) {

}

void NNodes::CProgram::Visit(NVisitor::IVisitor *visitor) const {
    visitor->Visit(this);
}
