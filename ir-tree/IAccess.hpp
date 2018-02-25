#pragma once
#define interface struct

namespace NIRTree {
    interface IAccess {
        virtual ~IAccess() = default;
        virtual int GetPointer() const = 0;
    };
}