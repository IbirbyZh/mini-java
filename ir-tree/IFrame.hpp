#pragma once

#include "IAccess.hpp"
#include "Symbol.hpp"

namespace NIRTree {

    interface IFrame {
    public:
        virtual void AddFormal(const NTable::CSymbol *name, ...) = 0;
        virtual void AddLocal(const NTable::CSymbol *name, ...) = 0;
        virtual int FormalsCount() const = 0;
        virtual const IAccess *Formal(int index) const = 0;
        virtual const IAccess *FindLocalOrFormal(const NTable::CSymbol *name) const = 0;
    };

}