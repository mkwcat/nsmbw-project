#pragma once

#include "d_static/d_2d.h"
#include "d_static/d_lyt/d_lyttextbox.h"
#include "framework/f_base.h"
#include "machine/m_2d.h"
#include <nw4r/lyt/Layout.h>
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Picture.h>
#include <nw4r/lyt/TextBox.h>
#include <nw4r/lyt/Window.h>
#include <utility>

class LytBase_c : public d2d::Multi_c {
    SIZE_ASSERT(0x198);

public:
    /* 0x800C89A0 */
    LytBase_c();

    /* VT+0x08 0x800C89F0 */
    virtual ~LytBase_c() override;

    /* VT+0x14 0x800C8A60 */
    virtual bool build(const char* lytName, d2d::ResAccMult_c* resAcc = nullptr) override;

    /* 0x800C8D00 */
    bool ReadResource(const char* arcName, bool param2);

    /* 0x800C8E50 */
    void NPaneRegister(const char** paneNames, nw4r::lyt::Pane** nullPanes, int count);

    template <std::size_t N>
    [[gnu::always_inline]]
    constexpr inline void NPaneRegister(
        nw4r::lyt::Pane** nullPanes, const char* const (&paneNames)[N]
    ) {
        return NPaneRegister(const_cast<const char**>(paneNames), nullPanes, N);
    }

    /* 0x800C8EC0 */
    void WPaneRegister(const char** paneNames, nw4r::lyt::Window** windowPanes, int count);

    template <std::size_t N>
    [[gnu::always_inline]]
    constexpr inline void WPaneRegister(
        nw4r::lyt::Window** windowPanes, const char* const (&paneNames)[N]
    ) {
        return WPaneRegister(const_cast<const char**>(paneNames), windowPanes, N);
    }

    /* 0x800C8F30 */
    void PPaneRegister(const char** paneNames, nw4r::lyt::Picture** picturePanes, int count);

    template <std::size_t N>
    [[gnu::always_inline]]
    constexpr inline void PPaneRegister(
        nw4r::lyt::Picture** picturePanes, const char* const (&paneNames)[N]
    ) {
        return PPaneRegister(const_cast<const char**>(paneNames), picturePanes, N);
    }

    /* 0x800C8FA0 */
    void TPaneRegister(const char** paneNames, LytTextBox_c** textBoxPanes, int count);

    template <std::size_t N>
    [[gnu::always_inline]]
    constexpr inline void TPaneRegister(
        LytTextBox_c** textBoxPanes, const char* const (&paneNames)[N]
    ) {
        return TPaneRegister(const_cast<const char**>(paneNames), textBoxPanes, N);
    }

    /* 0x800C9010 */
    void TPaneNameRegister(const char** paneNames, const int* msgNoLow, int msgNoHigh, int count);

    template <std::size_t N>
    [[gnu::always_inline]]
    constexpr inline void TPaneNameRegister(
        int msgNoHigh, const char* const (&paneNames)[N], const int (&msgNoLow)[N]
    ) {
        return TPaneNameRegister(const_cast<const char**>(paneNames), msgNoLow, msgNoHigh, N);
    }

    struct TPaneNameInfo {
        const char* name;
        int         msgNoLow;
    };

private:
    template <std::size_t N, std::size_t... Indexes>
    [[gnu::always_inline]]
    constexpr inline void PassTPaneNameRegister(
        int msgNoHigh, const TPaneNameInfo (&panes)[N], const std::index_sequence<Indexes...>&
    ) {
        return TPaneNameRegister(
            const_cast<const char**>((const char* const[]) {panes[Indexes].name...}),
            (const int[]) {panes[Indexes].msgNoLow...}, msgNoHigh, N
        );
    }

public:
    template <std::size_t N>
    [[gnu::always_inline]]
    constexpr inline void TPaneNameRegister(
        int msgNoHigh, const TPaneNameInfo (&panes)[N]
    ) {
        return PassTPaneNameRegister<N>(msgNoHigh, panes, std::make_index_sequence<N>());
    }

    /* 0x800C90A0 */
    void AnimeResRegister(const char** animNames, int count);

    template <std::size_t N>
    [[gnu::always_inline]]
    constexpr inline void AnimeResRegister(
        const char* const (&animNames)[N]
    ) {
        return AnimeResRegister(const_cast<const char**>(animNames), N);
    }

    /* 0x800C91E0 */
    void GroupRegister(const char** groupNames, const int* animeRes, int count);

    struct GroupInfo {
        const char* name;
        int         animeRes;
    };

private:
    template <std::size_t N, std::size_t... Indexes>
    [[gnu::always_inline]]
    constexpr void PassGroupRegister(
        const GroupInfo (&groups)[N], const std::index_sequence<Indexes...>&
    ) {
        return GroupRegister(
            const_cast<const char**>((const char* const[]) {groups[Indexes].name...}),
            (const int[]) {groups[Indexes].animeRes...}, N
        );
    }

public:
    template <std::size_t N>
    [[gnu::always_inline]]
    constexpr void GroupRegister(
        const GroupInfo (&groups)[N]
    ) {
        return PassGroupRegister<N>(groups, std::make_index_sequence<N>());
    }

    /* 0x800C93E0 */
    void AnimeStartSetup(int group, bool param2 = false);

    /* 0x800C9470 */
    void LoopAnimeStartSetup(int group);

    /* 0x800C94C0 */
    void ReverseAnimeStartSetup(int group, bool param2 = false);

    /* 0x800C9580 */
    void AnimeEndSetup(int param1);

    /* 0x800C95F0 */
    void AllAnimeEndSetup();

    /* 0x800C9650 */
    void AnimePlay();

    /* 0x800C9700 const added */
    bool isAnime(int group = -1) const;

    /* 0x800C9730 const added */
    bool isAllAnime() const;

    /* 0x800C9A20 */
    fBase_c::PACK_RESULT_e doDelete();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x0AC */ d2d::ResAccMultLoader_c mResAccLoader;

    FILL(0x180, 0x184);

    /* 0x184 */ m2d::AnmGroup_c* mpAnmGroups;
    /* 0x188 */ bool*            mpAnmGroupEnabled;

    FILL(0x18C, 0x198);
};
