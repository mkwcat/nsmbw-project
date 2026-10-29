#pragma once

#include "nw4r/lyt/common.h"
#include "nw4r/lyt/pane.h"
#include "nw4r/ut/LinkList.h"

namespace nw4r::lyt {

namespace detail {
struct PaneLink {
    /* 0x00 */ ut::LinkListNode mLink;
    /* 0x08 */ Pane*            mTarget;
};
} // namespace detail

using PaneList = ut::LinkList<detail::PaneLink, 0>;

class Group {
    SIZE_ASSERT(0x2C);

public:
    Group(const res::Group* pResGroup, Pane* pRootPane);

    virtual ~Group();
    void AppendPane(Pane* pPane);
    void Init();

    PaneList* GetPaneList() { return &mPaneListLink; }

    bool IsUserAllocated() const { return mbUserAllocated; }

    const char* GetName() const { return mName; }

private:
    /* 0x04 */ ut::LinkListNode mLink;
    /* 0x0C */ PaneList         mPaneListLink;
    /* 0x18 */ char             mName[res::NW4R_RES_NAME_SIZE + 1];
    /* 0x29 */ bool             mbUserAllocated;
    /* 0x2A */ u8               mPadding[2];
};

struct GroupContainer {
    ~GroupContainer();
    void AppendGroup(Group* pGroup);
    Group* FindGroupByName(const char* findName);

    /* 0x4 */ ut::LinkList<Group, 4> mGroupList;
};

} // namespace nw4r::lyt
