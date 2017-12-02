#pragma once

#include "IAccess.hpp"
#include "Symbol.hpp"
#include <memory>

namespace NIRTree {

    interface IFrame {
    public:
        virtual ~IFrame() = default;
        virtual void AddFormal(const NTable::CSymbol *name, ...) = 0;
        virtual void AddLocal(const NTable::CSymbol *name, ...) = 0;
        virtual int FormalsCount() const = 0;
        virtual std::shared_ptr<const IAccess> Formal(int index) const = 0;
        virtual std::shared_ptr<const IAccess> FindLocalOrFormal(const NTable::CSymbol *name) const = 0;
    };

}