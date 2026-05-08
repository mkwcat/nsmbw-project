// f_manager.cpp
// NSMBW .text: 0x80162E30 - 0x80163140

#include "f_manager.h"

#include "f_base.h"
#include <mkwcat/NoInitialize.hpp>

[[nsmbw_data(0x80377D10)]]
fTrMgVisitor_c fManager_c::m_connectManage{nullptr};

[[nsmbw_data(0x80377D20)]]
fLiMgVisitor_c fManager_c::m_createManage{nullptr};

[[nsmbw_data(0x80377D34)]]
fLiMgVisitor_c fManager_c::m_executeManage{nullptr};

[[nsmbw_data(0x80377D48)]]
fLiMgVisitor_c fManager_c::m_drawManage{nullptr};

[[nsmbw_data(0x80377D5C)]]
fLiMgVisitor_c fManager_c::m_deleteManage{nullptr};

[[nsmbw(0x80162E40)]]
fBase_c* fManager_c::searchBaseByID(fBaseID_e id);

[[nsmbw(0x80162E90)]]
fBase_c* fManager_c::searchBaseByProfName(fProfName profName, const fBase_c* from);

fBase_c* fManager_c::getNextBase(
    const fBase_c* from
) {
    if (from == nullptr) {
        return static_cast<fTrNdBa_c*>(m_connectManage.getRootNode())->mpOwner;
    }

    if (fTrNdBa_c* next = from->mMng.mConnectNode.getTreeNext(); next) {
        return next->mpOwner;
    }
    return nullptr;
}
