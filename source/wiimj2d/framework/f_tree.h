#pragma once

#include "component/c_tree.h"
#include "f_profile.h"

class fTrNdBa_c;

/**
 * A base tree, made of fTrNdBa_c nodes; "Tree Manager (for) Bases".
 */
class fTrMgBa_c : public cTreeMg_c {
public:
    /**
     * Searches for a base with a given profile name, optionally under a given parent.
     *
     * @param profName The profile name.
     * @param parent The parent node to start searching from, or @p nullptr to use the tree's root
     * node.
     * @return The node of the first base matching this criteria, or @p nullptr if none was found.
     */
    const fTrNdBa_c* searchNodeByProfName(fProfName profName, const fTrNdBa_c* parent) const;

    /**
     * Searches for a base with a given group type, optionally under a given parent.
     *
     * @param groupType The group type. Value is a fBase_c::GROUP_TYPE_e.
     * @param parent The parent node to start searching from, or @p nullptr to use the tree's root
     * node.
     * @return The node of the first base matching this criteria, or @p nullptr if none was found.
     */
    const fTrNdBa_c* searchNodeByGroupType(u8 groupType, const fTrNdBa_c* parent) const;
};

class fBase_c;

/**
 * A base tree node. Each node is owned by a @ref fBase_c "base" and represents it in the @ref
 * fTrMgBa_c "tree". {The class name stands for "Tree Node (with) Base".}
 */
class fTrNdBa_c : public cTreeNd_c {
    SIZE_ASSERT(0x14);

public:
    /**
     * Constructs a new tree node.
     * @param owner The node's owner.
     */
    constexpr fTrNdBa_c(
        fBase_c* owner
    )
        : mpOwner(owner) {}

    fTrNdBa_c* getTreeNext() const { return static_cast<fTrNdBa_c*>(cTreeNd_c::getTreeNext()); }

    fTrNdBa_c* getTreeNextNotChild() const {
        return static_cast<fTrNdBa_c*>(cTreeNd_c::getTreeNextNotChild());
    }

    fTrNdBa_c* getParent() const { return static_cast<fTrNdBa_c*>(cTreeNd_c::getParent()); }

    fTrNdBa_c* getChild() const { return static_cast<fTrNdBa_c*>(cTreeNd_c::getChild()); }

    fTrNdBa_c* getBrPrev() const { return static_cast<fTrNdBa_c*>(cTreeNd_c::getBrPrev()); }

    fTrNdBa_c* getBrNext() const { return static_cast<fTrNdBa_c*>(cTreeNd_c::getBrNext()); }

    /* 0x10 */ fBase_c* mpOwner; // The owner of this node.
};

/**
 * A base tree made of fTrNdBa_c nodes, with a reference to a process function.
 * @unofficial
 */
struct fTrMgVisitor_c : public fTrMgBa_c {
    /**
     * Constructs a new tree.
     * @param procFunc The process function, or @p nullptr.
     */
    constexpr fTrMgVisitor_c(
        int (fBase_c::*procFunc)()
    )
        : mProc(procFunc) {}

    /**
     * Calls @ref mProc "the process function" on each base in the tree.
     * @return Always returns true.
     */
    bool walkPack();

private:
    /**
     * The process function for the tree.
     */
    int (fBase_c::*mProc)();
};
