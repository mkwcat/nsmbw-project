#pragma once

#include "component/c_list.h"
#include "f_base_id.h"
#include "f_profile.h"

class fBase_c;

/**
 * A base list node. Each node is owned by a fBase_c "base" and represents it in the fLiMgBa_c
 * "list".
 * @unofficial
 */
class fLiNdBa_c : public cListNd_c {
    SIZE_ASSERT(0xC);

public:
    /**
     * Constructs a new list node.
     * @param owner The node's owner.
     */
    fLiNdBa_c(
        fBase_c* owner
    )
        : mpOwner(owner) {}

    fLiNdBa_c();

    inline fLiNdBa_c* getPrev() const { return static_cast<fLiNdBa_c*>(cListNd_c::getPrev()); }

    inline fLiNdBa_c* getNext() const { return static_cast<fLiNdBa_c*>(cListNd_c::getNext()); }

    /**
     * Removes this node from the owner's fBase_c::mUnusedList "mUnusedList".
     * @unofficial
     */
    void removeSelf();

    /**
     * The owner of this node.
     */
    /* 0x8 */ fBase_c* mpOwner;
};

/**
 * A base list, made of fLiNdBa_c nodes; "List Manager (for) Bases"
 */
class fLiMgBa_c : public cListMg_c {
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
    const fLiNdBa_c* searchNodeByID(fBaseID_e id) const;

    inline fLiNdBa_c* getFirst() const { return static_cast<fLiNdBa_c*>(cListMg_c::getFirst()); }

    inline fLiNdBa_c* getLast() const { return static_cast<fLiNdBa_c*>(cListMg_c::getLast()); }
};

/**
 * A base list node, with priority fields for reordering.
 * @unofficial
 */
class fLiNdPrio_c : public fLiNdBa_c {
    SIZE_ASSERT(0x10);

public:
    /**
     * Constructs a new list node.
     * @param owner The node's owner.
     */
    fLiNdPrio_c(
        fBase_c* owner
    )
        : fLiNdBa_c(owner)
        , mOrder(0)
        , mNewOrder(0) {}

    fLiNdPrio_c* getPrev() const { return static_cast<fLiNdPrio_c*>(fLiNdBa_c::getPrev()); }

    fLiNdPrio_c* getNext() const { return static_cast<fLiNdPrio_c*>(fLiNdBa_c::getNext()); }

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

/**
 * A base list made of fLiNdPrio_c nodes, with a reference to a process function.
 * @unofficial
 */
class fLiMgVisitor_c : public fLiMgBa_c {
    SIZE_ASSERT(0x8 + sizeof(mProc)); // 0x14

public:
    /**
     * Constructs a new list.
     * @param procFunc The process function, or @p nullptr.
     */
    constexpr fLiMgVisitor_c(
        int (fBase_c::*procFunc)()
    )
        : mProc(procFunc) {}

    /**
     * Adds a node to the list, according to its priority.
     *
     * @param node The node to insert.
     * @return If the operation was successful.
     */
    bool addNode(fLiNdPrio_c* node);

    /**
     * Calls the @ref mProc "process function" on each base in the list.
     * @return Always returns true.
     */
    bool walkPack();

    fLiNdPrio_c* getFirst() const { return static_cast<fLiNdPrio_c*>(fLiMgBa_c::getFirst()); }

    fLiNdPrio_c* getLast() const { return static_cast<fLiNdPrio_c*>(fLiMgBa_c::getLast()); }

private:
    /* 0x8 */ int (fBase_c::*mProc)(); // The process function for the list.
};
