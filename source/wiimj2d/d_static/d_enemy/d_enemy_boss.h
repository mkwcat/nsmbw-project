#pragma once

#include "d_allocator.h"
#include "d_audio.h"
#include "d_enemy.h"

/**
 * Interface for managing a boss's hit points, damage values, and damage state.
 */
class dBossLifeInf_c {
public:
    // Structors
    // ^^^^^^

    /* VT+0x08 */ virtual ~dBossLifeInf_c() {}

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * Checks whether the boss has not yet been damaged.
     */
    /* VT+0x0C */ virtual bool isNonDamage() const ABSTRACT;

    /**
     * Checks whether the boss has been damaged once.
     */
    /* VT+0x10 */ virtual bool isOneDamage() const ABSTRACT;

    /**
     * Checks whether the boss has been damaged twice.
     */
    /* VT+0x14 */ virtual bool isTwoDamage() const ABSTRACT;

    /**
     * Checks whether the current HP is at a damage section boundary.
     * @returns true if the implementation considers the current HP to be at a damage-section
     * boundary; otherwise false.
     * @details The default implementation always returns false. Implementations that divide boss HP
     * into sections can override this method to expose those boundaries.
     */
    /* VT+0x18 */ virtual bool isDmgSection() const { return false; }

    /**
     * Gets the damage dealt by fireball attacks.
     */
    /* VT+0x1C */ virtual int getDamage_Fire() const ABSTRACT;

    /**
     * Gets the damage dealt by stomp (Fumi) attacks.
     */
    /* VT+0x20 */ virtual int getDamage_Fumi() const ABSTRACT;

    /**
     * Gets the damage dealt by ground pound (Hip) attacks.
     */
    /* VT+0x24 */ virtual int getDamage_HipAtk() const ABSTRACT;

    /**
     * Gets the damage dealt by Star invincibility attacks.
     */
    /* VT+0x28 */ virtual int getDamage_Star() const ABSTRACT;

    /**
     * Gets the damage dealt by Penguin slide attacks.
     */
    /* VT+0x2C */ virtual int getDamage_PenguinSlide() const ABSTRACT;

    /**
     * Gets the damage dealt by block hit attacks.
     */
    /* VT+0x30 */ virtual int getDamage_BlockHit() const ABSTRACT;

    /**
     * Gets the damage dealt by shell attacks.
     */
    /* VT+0x34 */ virtual int getDamage_Shell() const ABSTRACT;

    /**
     * Gets the damage dealt by multiplayer ground pound (Quake) attacks.
     */
    /* VT+0x38 */ virtual int getDamage_Quake() const ABSTRACT;

    /**
     * Post-damage callback invoked when a boss survives an attack.
     * @param dmg The amount of damage applied.
     */
    /* VT+0x3C */ virtual void damageRev(
        int dmg
    ) {}

public:
    // Instance Variables
    // ^^^^^^

    /* 0x4 */ int mLife;
};

class dBossLife_Common_c : public dBossLifeInf_c {
public:
    // Structors
    // ^^^^^^

    /* VT+0x08 0x8009A2E0 */
    virtual ~dBossLife_Common_c();
};

class dEnBoss_c : public dEn_c {
    SIZE_ASSERT(0x600); // Assumed
    VTABLE(0x60, fBase_c, 0x80312288);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x524 */ dHeapAllocator_c mAllocator;
    /* 0x548 */ int mTenmetsuTime; // Timer for the flashing effect when the boss takes damage.
    /* 0x54C */ dAudio::SndObjctEmy_c mSndObject;
    /* 0x5F0 */ u16                   m0x5F0;
    /* 0x5F4 */ u32                   mQuakeDamage;
    /* 0x5F8 */ dBossLifeInf_c*       mpBossLife;

    FILL(0x5FC, 0x600);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80099F20
     * executeState:    VT+0x284 0x80099F40
     * finalizeState:   VT+0x288 0x80099F30
     */
    sState_ExternVirtual(0x803579B4, dEnBoss_c, DemoWait);

    /*
     * initializeState: VT+0x16C 0x80099F50
     * executeState:    VT+0x170 0x80099F70
     * finalizeState:   VT+0x174 0x80099F60
     */
    sState_ExternVirtual(0x803579F4, dEnBoss_c, DieFumi);

    /*
     * initializeState: VT+0x28C 0x80099F80
     * executeState:    VT+0x290 0x80099FA0
     * finalizeState:   VT+0x294 0x80099F90
     */
    sState_ExternVirtual(0x80357A34, dEnBoss_c, DieFire);

    /*
     * initializeState: VT+0x298 0x80099FB0
     * executeState:    VT+0x29C 0x80099FD0
     * finalizeState:   VT+0x2A0 0x80099FC0
     */
    sState_ExternVirtual(0x80357A74, dEnBoss_c, DieSlide);

    /*
     * initializeState: VT+0x2A4 0x80099FE0
     * executeState:    VT+0x2A8 0x8009A000
     * finalizeState:   VT+0x2AC 0x80099FF0
     */
    sState_ExternVirtual(0x80357AB4, dEnBoss_c, DieShell);

    /*
     * initializeState: VT+0x2B0 0x8009A010
     * executeState:    VT+0x2B4 0x8009A030
     * finalizeState:   VT+0x2B8 0x8009A020
     */
    sState_ExternVirtual(0x80357AF4, dEnBoss_c, DieStar);

    /*
     * initializeState: VT+0x2BC 0x8009A040
     * executeState:    VT+0x2C0 0x8009A060
     * finalizeState:   VT+0x2C4 0x8009A050
     */
    sState_ExternVirtual(0x80357B34, dEnBoss_c, DieQuake);

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0x2C8 0x8001D0F0 (weak) */ virtual void setBattleReady() {}

    /* VT+0x2CC */ virtual void createModel() {}

    /* VT+0x2D0 */ virtual void createBossLife();
    /* VT+0x2D4 */ virtual int createInit();

    /* VT+0x2D8 */ virtual void tenmetsuReady() {}

    /**
     * Prepares the flashing effect after the boss takes damage.
     */
    /* VT+0x2DC */ virtual void tenmetsuProc() {}

    /**
     * Handles the flashing effect after the boss takes damage.
     */
    /* VT+0x2E0 */ virtual void tenmetsuFin() {}

    /**
     * Ends the flashing effect after the boss takes damage.
     */
    /* VT+0x2E4 */ virtual int getTenmetsuTime_Fire() { return 40; }

    /* VT+0x2E8 */ virtual int getTenmetsuTime_Shell() { return 40; }

    /* VT+0x2EC */ virtual int getTenmetsuTime_Press() { return 40; }

    /* VT+0x2F0 */ virtual void deadAllKill();

    /* VT+0x2F4 */ virtual void setFumiDamage(
        dActor_c*
    ) {}

    /* VT+0x2F8 */ virtual void setFumiDead(
        dActor_c*
    ) {}

    /* VT+0x2FC */ virtual void setFireDamage(
        dActor_c*
    ) {}

    /* VT+0x300 */ virtual void setFireDead(
        dActor_c*
    ) {}

    /* VT+0x304 */ virtual void setHipatkDamage(
        dActor_c* actor
    ) {
        setFumiDamage(actor);
    }

    /* VT+0x308 */ virtual void setHipatkDead(
        dActor_c* actor
    ) {
        setFumiDead(actor);
    }

    /* VT+0x30C */ virtual void setSlideDamage(
        dActor_c*
    ) {}

    /* VT+0x310 */ virtual void setSlideDead(
        dActor_c*
    ) {}

    /* VT+0x314 */ virtual void setStarDamage(
        dActor_c*
    ) {}

    /* VT+0x318 */ virtual void setStarDead(
        dActor_c*
    ) {}

    /* VT+0x31C */ virtual void setQuakeDamage() {}

    /* VT+0x320 */ virtual void setQuakeDead() {}

    /* VT+0x324 */ virtual void setShellDamage(
        dActor_c*
    ) {}

    /* VT+0x328 */ virtual void setShellDead(
        dActor_c*
    ) {}

    /* VT+0x32C */ virtual void damageProc() {}

    /* VT+0x330 */ virtual void deadProc() {}

    /* VT+0x334 */ virtual bool isFumiInvalid() const { return false; }

    /* VT+0x338 */ virtual bool isFumiDmgInvalid() const { return false; }

    /* VT+0x33C */ virtual bool isFireInvalid() const { return false; }

    /* VT+0x340 */ virtual bool isSlideInvalid() const { return true; }

    /* VT+0x344 */ virtual bool isShellInvalid() const { return false; }

    /* VT+0x348 */ virtual bool isStarInvalid() const { return false; }

    /* VT+0x34C */ virtual void fumideadEffect() {}

    /* VT+0x350 */ virtual void fumidmgEffect() {}

    /* VT+0x354 */ virtual void hitFireEffect() {}

    /* VT+0x358 */ virtual void hitShellEffect() {}

    /* VT+0x35C */ virtual void fumidmgSE() { playSE(SndID::SE_BOSS_CMN_STOMPED); }

    /* VT+0x360 */ virtual void fumideadSE() { playSE(SndID::SE_BOSS_CMN_STOMPED_LAST1); }

    /* VT+0x364 */ virtual void stardmgSE() { playSE(SndID::SE_BOSS_CMN_DAMAGE_STAR_DEF); }

    /* VT+0x368 */ virtual void stardeadSE() { playSE(SndID::SE_BOSS_CMN_DAMAGE_STAR_LAST); }

    /* VT+0x36C */ virtual void shelldmgSE() { playSE(SndID::SE_BOSS_CMN_DAMAGE_DEF); }

    /* VT+0x370 */ virtual void shelldeadSE() { playSE(SndID::SE_BOSS_CMN_DAMAGE_LAST); }

    /* VT+0x374 */ virtual void firedmgSE() {
        mpBossLife->isDmgSection() ? playSE(SndID::SE_BOSS_CMN_DAMAGE_FIRE_DEF)
                                   : playSE(SndID::SE_BOSS_CMN_DAMAGE_FIRE);
    }

    /* VT+0x378 */ virtual void firedeadSE() { playSE(SndID::SE_BOSS_CMN_DAMAGE_FIRE_LAST); }

    /* VT+0x37C */ virtual void quakedmgSE() { playSE(SndID::SE_BOSS_CMN_DAMAGE_STAR_DEF); }

    /* VT+0x380 */ virtual void quakedeadSE() { playSE(SndID::SE_BOSS_CMN_DAMAGE_STAR_LAST); }

    /* VT+0x384 */ virtual void fumiDeadVo() {}

    /* VT+0x388 */ virtual void damageSVo() {}

    /* VT+0x38C */ virtual void damageLVo() {}

public:
    // Inline Instance Methods
    // ^^^^^^

    void playSE(
        SndID::Type sndID
    ) {
        mSndObject.startSound(sndID, m0x5F0, 0);
    }

    int getLife() const { return mpBossLife->mLife; }

    bool isDead() const { return mpBossLife->mLife <= 0; }
};
