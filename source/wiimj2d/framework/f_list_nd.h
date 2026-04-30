#pragma once

#include "component/c_list.h"

class fBase_c;

/**
 * A base list node. Each node is owned by a fBase_c "base" and represents it in the fLiMgBa_c
 * "list".
 * @unofficial
 */
class fLiNdBa_c : public cListNd_c
{
    SIZE_ASSERT(0xC);

public:
    /**
     * Constructs a new list node.
     * @param owner The node's owner.
     */
    fLiNdBa_c(fBase_c* owner)
      : mpOwner(owner)
    {
    }

    fLiNdBa_c();

    inline fLiNdBa_c* getPrev() const
    {
        return static_cast<fLiNdBa_c*>(cListNd_c::getPrev());
    }

    inline fLiNdBa_c* getNext() const
    {
        return static_cast<fLiNdBa_c*>(cListNd_c::getNext());
    }

    /**
     * Removes this node from the owner's  fBase_c::mUnusedList "mUnusedList".
     * @unofficial
     */
    void removeSelf();

    /**
     * The owner of this node.
     */
    /* 0x8 */ fBase_c* mpOwner;
};
