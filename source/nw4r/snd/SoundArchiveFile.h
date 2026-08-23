#pragma once

#include "SoundArchive.h"
#include "Util.h"
#include <algorithm>

#pragma clang diagnostic ignored "-Wflexible-array-extensions"

namespace nw4r::snd::detail {

namespace SoundArchiveFile {

//
// Symbol (SYMB) block
//

struct StringTreeNode {
    SIZE_ASSERT(0x14);
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 bit;
    /* 0x04 */ u32 leftIdx;
    /* 0x08 */ u32 rightIdx;
    /* 0x0C */ u32 strIdx;
    /* 0x10 */ u32 id;
};

struct StringTree {
    SIZE_ASSERT(0x8);
    /* 0x0 */ u32                         rootIdx;
    /* 0x4 */ Util::Table<StringTreeNode> nodeTable;
};

struct StringTable {
    SIZE_ASSERT(0x4);
    /* 0x0 */ Util::Table<u32> offsetTable;
};

struct StringChunk {
    SIZE_ASSERT(0x14);
    /* 0x00 */ u32 tableOffset;
    /* 0x04 */ u32 soundTreeOffset;
    /* 0x08 */ u32 playerTreeOffset;
    /* 0x0C */ u32 groupTreeOffset;
    /* 0x10 */ u32 bankTreeOffset;
};

struct StringBlock {
    SIZE_ASSERT(std::max(sizeof(StringTable), sizeof(StringChunk)));

    /* 0x00 */ union {
        StringTable stringTable;
        StringChunk stringChunk;
    };
};

//
// Info (INFO) block
//

struct BankInfo {
    SIZE_ASSERT(0x8);
    /* 0x0 */ u32 stringId;
    /* 0x4 */ u32 fileId;
};

using BankTable = Util::Table<Util::DataRef<BankInfo>>;

struct GroupItemInfo {
    SIZE_ASSERT(0x14);
    /* 0x00 */ u32 fileId;
    /* 0x04 */ u32 offset;
    /* 0x08 */ u32 size;
    /* 0x0C */ u32 waveDataOffset;
    /* 0x10 */ u32 waveDataSize;
};

using GroupItemTable = Util::Table<Util::DataRef<GroupItemInfo>>;

struct GroupInfo {
    SIZE_ASSERT(0x28);
    /* 0x00 */ u32                           stringId;
    /* 0x04 */ s32                           entryNum;
    /* 0x08 */ Util::DataRef<char>           extFilePathRef;
    /* 0x10 */ u32                           offset;
    /* 0x14 */ u32                           size;
    /* 0x18 */ u32                           waveDataOffset;
    /* 0x1C */ u32                           waveDataSize;
    /* 0x20 */ Util::DataRef<GroupItemTable> itemTableRef;
};

using GroupTable = Util::Table<Util::DataRef<GroupInfo>>;

struct Info {
    SIZE_ASSERT(0x30);
    /* 0x00 */ Util::DataRef<void>       soundTableRef;
    /* 0x08 */ Util::DataRef<BankTable>  bankTableRef;
    /* 0x10 */ Util::DataRef<void>       playerTableRef;
    /* 0x18 */ Util::DataRef<void>       fileTableRef;
    /* 0x20 */ Util::DataRef<GroupTable> groupTableRef;
    /* 0x28 */ Util::DataRef<void>       soundArchivePlayerInfoRef;
};

} // namespace SoundArchiveFile

class SoundArchiveFileReader final {
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80276020 */
    SoundType GetSoundType(u32 id) const;

    /* 0x80276110 */
    bool ReadSoundInfo(u32 id, SoundArchive::SoundInfo* pSoundInfo) const;

    /* 0x80276350 */
    bool ReadSeqSoundInfo(u32 id, SoundArchive::SeqSoundInfo* pInfo) const;

    /* 0x80276630 */
    bool ReadBankInfo(u32 id, SoundArchive::BankInfo* pInfo) const;

    /* 0x802767A0 */
    bool ReadGroupInfo(u32 id, SoundArchive::GroupInfo* pInfo) const;

    /* 0x80276B10 */
    const char* GetSoundLabelString(u32 id) const;

    const char* GetString(u32 id) const;

private:
    // Private Instance Methods
    // ^^^^^^

    /* 0x80276020 */
    SoundType GetSoundTypeInternal(u32 id) const;

    /* 0x80276110 */
    bool ReadSoundInfoInternal(u32 id, SoundArchive::SoundInfo* pSoundInfo) const;

    /* 0x80276350 */
    bool ReadSeqSoundInfoInternal(u32 id, SoundArchive::SeqSoundInfo* pInfo) const;

    const SoundArchiveFile::BankInfo* impl_GetBankInfo(u32 id) const;
    const SoundArchiveFile::GroupInfo* impl_GetGroupInfo(u32 id) const;

    const void* GetPtrConst(
        const void* pBase, u32 offset
    ) const {
        if (offset == 0) {
            return nullptr;
        }

        return static_cast<const void*>(reinterpret_cast<const u8*>(pBase) + offset);
    }

private:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x28);

    /* 0x28 */ const SoundArchiveFile::Info*        mInfo;
    /* 0x2C */ const void*                          mStringBase;
    /* 0x30 */ const SoundArchiveFile::StringTable* mStringTable;
    /* 0x34 */ const SoundArchiveFile::StringTree*  mStringTreeSound;
    /* 0x38 */ const SoundArchiveFile::StringTree*  mStringTreePlayer;
    /* 0x3C */ const SoundArchiveFile::StringTree*  mStringTreeGroup;
    /* 0x40 */ const SoundArchiveFile::StringTree*  mStringTreeBank;
};

} // namespace nw4r::snd::detail
