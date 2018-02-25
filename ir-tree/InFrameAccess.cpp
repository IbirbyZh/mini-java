#include "InFrameAccess.hpp"

NIRTree::CInFrameAccess::CInFrameAccess(int shift) : frameShift(shift) {

}

int NIRTree::CInFrameAccess::GetPointer() const {
    return frameShift;
}
