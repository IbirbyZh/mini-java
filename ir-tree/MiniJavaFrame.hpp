#pragma once

#include "IFrame.hpp"
#include "IAccess.hpp"
#include "Symbol.hpp"
#include "MethodInfo.hpp"
#include <memory>
#include <vector>
#include <unordered_map>

namespace NIRTree {
    class CMiniJavaFrame : public IFrame {
    public:
        void AddFormal(const NTable::CSymbol *name, ...) override;
        void AddLocal(const NTable::CSymbol *name, ...) override;
        int FormalsCount() const override;
        std::shared_ptr<const IAccess> Formal(int index) const override;
        std::shared_ptr<const IAccess> FindLocalOrFormal(const NTable::CSymbol *name) const override;
        static std::shared_ptr<const CMiniJavaFrame> BuildFrame(std::shared_ptr<const NTable::CMethodInfo> methodInfo);
    private:
        int formalsCount;
        std::vector<const NTable::CSymbol *> formalToName;
        std::unordered_map<const NTable::CSymbol *, std::shared_ptr<const IAccess>> nameToAccess;
    };
}

