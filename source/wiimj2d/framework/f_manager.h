#pragma once

#include "f_base_id.h"
#include "f_list.h"
#include "f_profile.h"
#include "f_tree.h"

class fBase_c;

class fManager_c {
    SIZE_ASSERT(0x40);

public:
    // Static Methods
    // ^^^^^^

    /* 0x80162E40 */
    static fBase_c* searchBaseByID(fBaseID_e id);

    /* 0x80162E90 */
    static fBase_c* searchBaseByProfName(fProfName profName, const fBase_c* from = nullptr);

    // Static Methods
    // ++++++

    static fBase_c* getNextBase(const fBase_c* from = nullptr);

private:
    // Instance Variables
    // ^^^^^^

    /**
     * The node in the @ref m_connectManage "connect tree".
     */
    /* 0x00 */ fTrNdBa_c mConnectNode;

    /**
     * @brief The node in the @ref m_createManage "create", @ref m_executeManage "execute" or @ref
     * m_deleteManage "delete" list.*
     */
    /* 0x14 */ fLiNdPrio_c mMainNode;

    /**
     * The node in the @ref m_drawManage "draw list".
     */
    /* 0x24 */ fLiNdPrio_c mDrawNode;

    /**
     * The node in the @ref m_searchManage "search lists".
     */
    /* 0x34 */ fLiNdBa_c mSearchNode;

private:
    // Static Variables
    // ^^^^^^

    /**
     * A tree that connects all loaded bases.
     */
    /* 0x80377D10 */ static fTrMgVisitor_c m_connectManage;
    /**
     * A list of all the bases scheduled for creation.
     */
    /* 0x80377D20 */ static fLiMgVisitor_c m_createManage;
    /**
     * A list of all the bases scheduled for execution.
     */
    /* 0x80377D34 */ static fLiMgVisitor_c m_executeManage;
    /**
     * A list of all the bases scheduled for drawing.
     */
    /* 0x80377D48 */ static fLiMgVisitor_c m_drawManage;
    /**
     * A list of all the bases scheduled for deletion.
     */
    /* 0x80377D5C */ static fLiMgVisitor_c m_deleteManage;
};
