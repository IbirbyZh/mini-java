#include "MiniJavaFrame.hpp"
#include "InFrameAccess.hpp"

void NIRTree::CMiniJavaFrame::AddFormal(const NTable::CSymbol *name, ...) {
    formalToName.push_back(name);
    ++formalsCount;
    nameToAccess.insert(std::make_pair(name, std::make_shared<CInFrameAccess>(nameToAccess.size() * 4)));
}

void NIRTree::CMiniJavaFrame::AddLocal(const NTable::CSymbol *name, ...) {
    nameToAccess.insert(std::make_pair(name, std::make_shared<CInFrameAccess>(nameToAccess.size() * 4)));
}

int NIRTree::CMiniJavaFrame::FormalsCount() const {
    return formalsCount;
}

std::shared_ptr<const NIRTree::IAccess> NIRTree::CMiniJavaFrame::Formal(int index) const {
    if (index < formalsCount) {
        return nameToAccess.find(formalToName[index])->second;
    } else {
        return nullptr;
    }
}

std::shared_ptr<const NIRTree::IAccess> NIRTree::CMiniJavaFrame::FindLocalOrFormal(const NTable::CSymbol *name) const {
    auto &&accessIterator = nameToAccess.find(name);
    if (accessIterator != nameToAccess.end()) {
        return accessIterator->second;
    } else {
        return nullptr;
    }
}

std::shared_ptr<const NIRTree::CMiniJavaFrame>
NIRTree::CMiniJavaFrame::BuildFrame(std::shared_ptr<const NTable::CMethodInfo> methodInfo) {
    std::shared_ptr<NIRTree::CMiniJavaFrame> frame = std::make_shared<NIRTree::CMiniJavaFrame>();
    for (auto &&parameter: methodInfo->GetPositionParameters()) {
        frame->AddFormal(parameter);
    }
    for (auto &&variable: methodInfo->GetVariables()) {
        frame->AddLocal(variable.first);
    }
    return frame;
}
