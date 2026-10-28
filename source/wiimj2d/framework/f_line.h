#pragma once

#include "c_line.h"
#include "f_base_id.h"
#include "f_profile.h"

class fBase_c;

/**
 * A base line node. Each node is owned by a fBase_c "base" and represents it in the fLiMgBa_c
 * "line".
 */
class fLiNdBaLink_c : public cLineNd_c {
    SIZE_ASSERT(0xC);

public:
    /**
     * Constructs a new line node.
     * @param parent The node's parent.
     */
    constexpr fLiNdBaLink_c(
        fBase_c* parent
    )
        : mParent(parent) {}

    fLiNdBaLink_c();

    inline fLiNdBaLink_c* getPrev() const {
        return static_cast<fLiNdBaLink_c*>(cLineNd_c::getPrev());
    }

    inline fLiNdBaLink_c* getNext() const {
        return static_cast<fLiNdBaLink_c*>(cLineNd_c::getNext());
    }

    /**
     * Removes this node from the parent's fBase_c::mUnusedList "mUnusedList".
     */
    void clearData();

    /**
     * The parent of this node.
     */
    /* 0x8 */ fBase_c* mParent;
};

/**
 * A base line, made of fLiNdBaLink_c nodes; "List Manager (for) Bases"
 */
class fLiMgBa_c : public cLineMg_c {
    SIZE_ASSERT(0x8);

public:
    /**
     * Counts the number of bases using the given profile name.
     *
     * @param profName The profile name.
     * @return How many bases were found.
     */
    int countNodeByProfName(fProfName profName) const;

    /**
     * Searches for a base with the given ID.
     *
     * @param id The ID to search for.
     * @return The node belonging to such base, or @p nullptr.
     */
    const fLiNdBaLink_c* searchNodeByID(fBaseID_e id) const;

    inline fLiNdBaLink_c* getFirst() const {
        return static_cast<fLiNdBaLink_c*>(cLineMg_c::getFirst());
    }

    inline fLiNdBaLink_c* getLast() const {
        return static_cast<fLiNdBaLink_c*>(cLineMg_c::getLast());
    }
};

/**
 * A base line node, with priority fields for reordering.
 */
class fLiNdBaPr_c : public fLiNdBaLink_c {
    SIZE_ASSERT(0x10);

public:
    /**
     * Constructs a new line node.
     * @param parent The node's parent.
     */
    constexpr fLiNdBaPr_c(
        fBase_c* parent
    )
        : fLiNdBaLink_c(parent)
        , mOrder(0)
        , mNewOrder(0) {}

    fLiNdBaPr_c* getPrev() const { return static_cast<fLiNdBaPr_c*>(fLiNdBaLink_c::getPrev()); }

    fLiNdBaPr_c* getNext() const { return static_cast<fLiNdBaPr_c*>(fLiNdBaLink_c::getNext()); }

    u16 getOrder() const { return mOrder; }

    u16 getNewOrder() const { return mNewOrder; }

    /**
     * The priority of this node. Lower values mean higher priority.
     */
    /* 0x0C */ u16 mOrder;

    /**
     * The priority the node should change to if it differs from #mOrder.
     */
    /* 0x0E */ u16 mNewOrder;
};

/*
 * @brief A base list made of fLiNdBaLink_c nodes, with a reference to a process function.
 */
class fLiMgBaFu_c : public fLiMgBa_c {
public:
    /**
     * Constructs a new list.
     *
     * @param procFunc The process function, or @p nullptr.
     */
    constexpr fLiMgBaFu_c(
        int (fBase_c::*procFunc)()
    )
        : mProcFunc(procFunc) {}

    /**
     * Calls the @ref mProcFunc "process function" on each base in the list.
     *
     * @return Always returns true.
     */
    bool lineListProc();

private:
    int (fBase_c::*mProcFunc)(); /// The process function for the list.
};

/**
 * A base list like fLiMgBa_c, but with fLiNdBaPr_c nodes for priority-based ordering.
 */
class fLiMgBaFuPr_c : public fLiMgBaFu_c {
public:
    /**
     * Constructs a new list.
     *
     * @param procFunc The process function, or @p nullptr.
     */
    constexpr fLiMgBaFuPr_c(
        int (fBase_c::*procFunc)()
    )
        : fLiMgBaFu_c(procFunc) {}

    /**
     * Adds a node to the list, according to its priority.
     *
     * @param node The node to insert.
     * @return If the operation was successful.
     */
    bool insertLineNodePriority(fLiNdBaPr_c* node);

    fLiNdBaPr_c* getFirst() const { return static_cast<fLiNdBaPr_c*>(fLiMgBa_c::getFirst()); }

    fLiNdBaPr_c* getLast() const { return static_cast<fLiNdBaPr_c*>(fLiMgBa_c::getLast()); }
};
