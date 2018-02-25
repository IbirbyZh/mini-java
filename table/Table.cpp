#include "Table.hpp"
#include <set>

NTable::CTable::CTable(const NNodes::CProgram *const program) {
    CStringInternist &stringInternist = NTable::CStringInternist::GetInstance();
    for (auto &_class :program->GetClasses()) {
        classesInfo.insert(
                std::make_pair(stringInternist.Intern(_class->GetName()), std::make_shared<CClassInfo>(_class))
        );
    }
}

void NTable::CTable::AddScope(const NTable::CSymbol *className, const NTable::CSymbol *methodName) {
    auto &&classInfo = classesInfo.find(className)->second;
    auto &&methodInfo = classInfo->GetMethods().find(methodName)->second;
    scopes.emplace_back(classInfo, methodInfo, classesInfo);
}


void NTable::CTable::PopScope() {
    scopes.pop_back();
}

const NTable::CSymbol *NTable::CTable::GetCurrentClass() const {
    return scopes.back().GetCurrentClass();
}

const std::shared_ptr<const NTable::CVariableInfo> &NTable::CTable::FindNameInScope(const NTable::CSymbol *name) const {
    return scopes.back().FindName(name);
}

const std::shared_ptr<const NTable::CVariableInfo> &NTable::CTable::FindNameInScope(const std::string &name) const {
    return FindNameInScope(NTable::CStringInternist::GetInstance().Intern(name));
}

const std::shared_ptr<const NTable::CMethodInfo> &
NTable::CTable::GetMethodInfo(const NTable::CSymbol *className, const NTable::CSymbol *methodName) const {
    auto &&classInfoIterator = classesInfo.find(className);
    if (classInfoIterator == classesInfo.end()) {
        return nullptr;
    }
    auto &&methodInfoIterator = classInfoIterator->second->GetMethods().find(methodName);
    if (methodInfoIterator == classInfoIterator->second->GetMethods().end()) {
        return nullptr;
    }
    return methodInfoIterator->second;

}

const std::shared_ptr<const NTable::CMethodInfo> &
NTable::CTable::GetMethodInfo(const std::string &className, const std::string &methodName) const {
    return GetMethodInfo(NTable::CStringInternist::GetInstance().Intern(className),
                         NTable::CStringInternist::GetInstance().Intern(methodName));
}

const std::shared_ptr<const NTable::CClassInfo> &NTable::CTable::GetClassInfo(const NTable::CSymbol *className) const {
    auto &&classInfoIterator = classesInfo.find(className);
    if (classInfoIterator == classesInfo.end()) {
        return nullptr;
    }
    return classInfoIterator->second;
}

const std::shared_ptr<const NTable::CClassInfo> &NTable::CTable::GetClassInfo(const std::string &className) const {
    return GetClassInfo(NTable::CStringInternist::GetInstance().Intern(className));
}

bool NTable::CTable::IsValidParentClasses(const NTable::CSymbol *className) const {
    auto &&classInfoIterator = classesInfo.find(className);
    if (classInfoIterator == classesInfo.end()) {
        return false;
    }
    std::set<const NTable::CSymbol *> parentClasses;
    parentClasses.insert(classInfoIterator->first);
    const NTable::CSymbol *parentClass = classInfoIterator->second->GetExtendsName();
    while (parentClass != nullptr && parentClasses.find(parentClass) == parentClasses.end()) {
        parentClasses.insert(parentClass);
        classInfoIterator = classesInfo.find(parentClass);
        if (classInfoIterator == classesInfo.end()) {
            return false;
        }
        parentClass = classInfoIterator->second->GetExtendsName();
    }
    return parentClass == nullptr;
}

bool NTable::CTable::IsValidParentClasses(const std::string &className) const {
    return IsValidParentClasses(NTable::CStringInternist::GetInstance().Intern(className));
}

const std::unordered_map<const NTable::CSymbol *, const std::shared_ptr<const NTable::CClassInfo>> &
NTable::CTable::GetClassesInfo() const {
    return classesInfo;
}
