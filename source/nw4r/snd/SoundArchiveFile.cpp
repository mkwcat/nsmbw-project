// snd_SoundArchiveFile.cpp
// NSMBW .text: 0x80275E80 - 0x80277190

#include "SoundArchiveFile.h"

#include <revolution/os.h>

namespace {
#include <mkwcat.rsid>
#include <wiimj2d.rsid>
} // namespace

namespace nw4r::snd::detail {

static constexpr u32 TOADETTE_BANK         = 1000;
static constexpr u32 TOADETTE_BANK_FILE_ID = 1000;

// Hack, i wanna do this better and not embedded in nw4r later, but this is more of a PoC patch

static bool IsToadetteSound(
    u32 id
) {
    return id >= 5010 && id <= 5079;
}

static u32 GetBaseToadetteSoundId(
    u32 id
) {
    if (IsToadetteSound(id)) {
        if (id == SE_VOC_KC_CS_COURSE_MISS) {
            return SE_VOC_KO_CS_COURSE_MISS;
        }
        if (id == SE_VOC_KC_CONTINUE) {
            // TODO: There's more to this one
            return SE_VOC_KO_CONTINUE;
        }
        if (id == SE_VOC_KC_YOSHI_JUMP) {
            // TODO: There's a wait on this one that shouldn't exist
            return SE_VOC_KO2_CANNON_SHOT_S;
        }
        if (id == SE_VOC_KC_DAMAGE_EATEN) {
            return SE_VOC_KO_DAMAGE_EATEN;
        }
        if (id == SE_VOC_KC_GET_STAR) {
            // TODO: Use com_3wave_r instead of ma_3wave_r
            return SE_VOC_MA_GET_STAR;
        }
        if (id == SE_VOC_KC_CLEAR_LAST_BOSS) {
            return SE_VOC_KO_CLEAR_LAST_BOSS;
        }
        if (id == SE_VOC_KC_CS_COMPLETE_DEMO) {
            return SE_VOC_KO_CS_COMPLETE_DEMO;
        }
        if (id == SE_VOC_KC_MISS_PRINCESS) {
            // TODO: Wait time is different
            return SE_VOC_KO_MISS_PRINCESS;
        }
        // TODO: SE_VOC_KC_GAME_OVER, SE_VOC_KC_TIMEUP_MULTI, SE_VOC_KC_CLEAR_MULTI

        return id - (SE_VOC_KC_PLAYER_JOIN - SE_VOC_KO2_PLAYER_JOIN);
    }
    return id;
}

EXTERN_REPL(
    0x80276020, //
    SoundType SoundArchiveFileReader::GetSoundTypeInternal(u32 id) const
);

[[nsmbw(0x80276020)]]
SoundType SoundArchiveFileReader::GetSoundType(
    u32 id
) const {
    return GetSoundTypeInternal(GetBaseToadetteSoundId(id));
}

EXTERN_REPL(
    0x80276110, //
    bool SoundArchiveFileReader::ReadSoundInfoInternal(u32 id, SoundArchive::SoundInfo* pSoundInfo)
        const
);

[[nsmbw(0x80276110)]]
bool SoundArchiveFileReader::ReadSoundInfo(
    u32 id, SoundArchive::SoundInfo* pSoundInfo
) const {
    return ReadSoundInfoInternal(GetBaseToadetteSoundId(id), pSoundInfo);
}

EXTERN_REPL(
    0x80276350, //
    bool SoundArchiveFileReader::ReadSeqSoundInfoInternal(u32 id, SoundArchive::SeqSoundInfo* pInfo)
        const
);

[[nsmbw(0x80276350)]]
bool SoundArchiveFileReader::ReadSeqSoundInfo(
    u32 id, SoundArchive::SeqSoundInfo* pInfo
) const {
    bool result = ReadSeqSoundInfoInternal(GetBaseToadetteSoundId(id), pInfo);
    if (!result || !IsToadetteSound(id)) {
        return result;
    }

    pInfo->bankId = TOADETTE_BANK;
    return result;
}

[[nsmbw(0x80276630)]]
bool SoundArchiveFileReader::ReadBankInfo(
    u32 id, SoundArchive::BankInfo* pInfo
) const {
    if (id == TOADETTE_BANK) {
        pInfo->fileId = TOADETTE_BANK_FILE_ID;
        return true;
    }

    const SoundArchiveFile::BankInfo* pSrc = impl_GetBankInfo(id);

    if (pSrc == nullptr) {
        return false;
    }

    pInfo->fileId = pSrc->fileId;
    return true;
}

[[nsmbw(0x80276B10)]]
const char* SoundArchiveFileReader::GetSoundLabelString(u32 id) const;

const char* SoundArchiveFileReader::GetString(
    u32 id
) const {
    if (id == 0xFFFFFFFF) {
        return nullptr;
    }

    if (mStringTable == nullptr) {
        return nullptr;
    }

    return static_cast<const char*>(GetPtrConst(mStringBase, mStringTable->offsetTable.items[id]));
}

const SoundArchiveFile::BankInfo* SoundArchiveFileReader::impl_GetBankInfo(
    u32 id
) const {
    const SoundArchiveFile::BankTable* pTable =
        Util::GetDataRefAddress0(mInfo->bankTableRef, mInfo);

    if (pTable == nullptr) {
        return nullptr;
    }

    if (id >= pTable->count) {
        return nullptr;
    }

    return Util::GetDataRefAddress0(pTable->items[id], mInfo);
}

const SoundArchiveFile::GroupInfo* SoundArchiveFileReader::impl_GetGroupInfo(
    u32 id
) const {
    const SoundArchiveFile::GroupTable* pTable =
        Util::GetDataRefAddress0(mInfo->groupTableRef, mInfo);

    if (pTable == nullptr) {
        return nullptr;
    }

    if (id >= pTable->count) {
        return nullptr;
    }

    return Util::GetDataRefAddress0(pTable->items[id], mInfo);
}

} // namespace nw4r::snd::detail
