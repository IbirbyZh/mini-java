#include "IAccess.hpp"

namespace NIRTree {
    class CInFrameAccess : public IAccess {
    public:
        explicit CInFrameAccess(int shift);
        int GetPointer() const override;
    private:
        int frameShift;
    };
}