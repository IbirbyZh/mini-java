#include "LabelHandler.h"

const std::shared_ptr<const NIRTree::CLabel> NIRTree::CLabelHandler::GetLabel(const std::string &src) {
    auto cached = stringToLabel.find(src);
    if (cached != stringToLabel.end()) {
        return cached->second;
    }
    stringToLabel.insert({src, std::make_shared<CLabel>(src)});
    return stringToLabel.find(src)->second;
}
