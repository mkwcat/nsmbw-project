// d_a_player_base.cpp
// NSMBW .text: 0x800460D0 - 0x8005B3A0

#include "d_a_player_base.h"

#include "d_bases/d_profile.h"
#include "d_player/d_a_player.h"
#include "d_player/d_a_yoshi.h"
#include "d_player/d_gamedisplay.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "framework/f_feature.h"
#include "framework/f_manager.h"
#include <cstdio>
#include <iterator>

[[address(0x8004DB40)]]
bool daPlBase_c::isDemoType(DemoType_e type);

[[address(0x8004DD00)]]
bool daPlBase_c::isDemo();

[[address(0x8004DDE0)]]
bool daPlBase_c::isDemoAll();

[[address(0x8004E040)]]
bool daPlBase_c::isPlayerGameStop();

[[address(0x8004E050)]]
void daPlBase_c::stopOther();

[[address(0x8004E100)]]
void daPlBase_c::playOther();

[[address(0x8004E290)]]
void daPlBase_c::changeDemoState(const sStateIDIf_c& state, int param);

[[address(0x80050D80)]]
bool daPlBase_c::isDispOutCheckOn();

[[address(0x800510F0)]]
void daPlBase_c::stopGoalOther()
{
    if (!isPlayerGameStop()) {
        return;
    }

    dActor_c::mExecStopReq |= 0xF;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        daPlBase_c* ctrlPlayer = daPyMng_c::getCtrlPlayer(i);
        if (ctrlPlayer == nullptr || !ctrlPlayer->isStatus(101)) {
            continue;
        }

        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player != nullptr) {
            player->m0x38E &= ~0x2;
        }

        daYoshi_c* yoshi = daPyMng_c::getYoshi(i);
        if (yoshi != nullptr) {
            yoshi->m0x38E &= ~0x2;
        }
    }
}

[[address(0x800511A0)]]
void daPlBase_c::playGoalOther()
{
    dActor_c::mExecStopReq &= ~0xF;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        daPlBase_c* ctrlPlayer = daPyMng_c::getCtrlPlayer(i);
        if (ctrlPlayer == nullptr || !isStatus(101)) {
            continue;
        }

        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player != nullptr) {
            player->m0x38E |= 0x2;
        }

        daYoshi_c* yoshi = daPyMng_c::getYoshi(i);
        if (yoshi != nullptr) {
            yoshi->m0x38E |= 0x2;
        }
    }
}

[[address(0x80051E70)]]
bool daPlBase_c::startControlDemo();

[[address(0x80051EF0)]]
void daPlBase_c::endControlDemo(int param);

[[address(0x80051F30)]]
void daPlBase_c::setControlDemoDir(u8 direction);

[[address(0x80052030)]]
bool daPlBase_c::isControlDemoWait();

[[address(0x80052080)]]
void daPlBase_c::setControlDemoWalk(const f32& pos, const f32& speed);

[[address(0x80052170)]]
void daPlBase_c::setControlDemoAnm(int anim);

[[address(0x80052470)]]
bool daPlBase_c::isBossDemoLand();

[[address(0x80056C70)]]
void daPlBase_c::onStatus(int flag);

[[address(0x80056CB0)]]
void daPlBase_c::offStatus(int flag);

[[address(0x80056CF0)]]
bool daPlBase_c::isStatus(int flag);

[[address(0x80056E30)]]
dPyMdlBase_c *daPlBase_c::getModel();

[[address(0x80057E70)]]
void daPlBase_c::playSound(SndID::Type, long);

[[address(0x800583A0)]]
void daPlBase_c::calcHeadAttentionAngle();

// Static array works here as we have a limited number of players
static fBaseID_e s_lastHitEnemy[PLAYER_COUNT] = {};

void daPlBase_c::addDeathMessage(dActor_c* source, DamageType_e type, bool death)
{
    // TODO: Use BMG for messages
    if (fFeature::DEATH_MESSAGES == fFeature::DEATH_MESSAGES_MODE_e::DISABLED) {
        return;
    }
    if (fFeature::DEATH_MESSAGES == fFeature::DEATH_MESSAGES_MODE_e::DEATH_ONLY && !death) {
        return;
    }

    fBaseID_e lastHit = s_lastHitEnemy[mPlayerNo];
    s_lastHitEnemy[mPlayerNo] = source ? source->mUniqueID : fBaseID_e::NONE;

    bool repeat = source ? source->mUniqueID == lastHit : false;

    const char* selfName = dProf::getFormattedName(this);
    if (selfName == nullptr) {
        selfName = "Someone";
    }

    const char* enemyName = dProf::getFormattedName(source);
    dProfName enemy = source ? source->mProfName : dProf::LASTACTOR;

    fBase_c* lastEnemy = fManager_c::searchBaseByID(lastHit);
    const char* lastEnemyName = nullptr;
    if (lastEnemy != nullptr) {
        lastEnemyName = dProf::getFormattedName(static_cast<dBase_c*>(lastEnemy));
    }

    const char* messages[128] = {};
    int messageCount = 0;

    auto msg = [&](const char* const m) {
        if (messageCount < 128) {
            messages[messageCount++] = m;
        }
    };

    switch (type) {
    default:
        if (enemy == dProf::LASTACTOR) {
            enemy = dProf::BOOT; // LASTACTOR is not a constant expression
        }

        switch (enemy) {
        default:
            if (repeat) {
                msg("%s gave %s another chance");
                msg("%s didn't learn their lesson about %s");
                if (!death) {
                    break;
                }
            }

            if (death) {
                msg("%s was finished by %s");
                msg("%s was slain by %s");
                msg("%s reached an impassable %s");
                msg("%s couldn't handle %s");
                msg("%s lost a fight with %s");
                msg("%s lost it to %s");
                msg("%s was no match for %s");
                msg("%s seriously died to %s?");
                msg("%s met the wrath of %s");
                msg("%s didn't get the memo about %s");
            } else {
                msg("%s came into contact with %s");
                msg("%s occupied the same space as %s");
                msg("%s and %s touched hitboxes");
                msg("%s was hurt badly by %s");
                msg("%s forgot %s was harmful");
                msg("%s! Stay away from %s!");
                msg("%s wasn't warned about %s...");
                msg("%s was scratched by %s");
                msg("%s tried to hug %s");
                msg("%s touched %s the wrong way");
            }
            break;

        case dProf::BOOT:
            // Enemy name = "an unknown force"
            if (death) {
                msg("%s lost the game");
                msg("%s lost a fight with the game");
                msg("%s lost it to %s");
                msg("Someone killed %s!!!");
                msg("%s died");
            } else {
                msg("%s came into contact with %s");
                msg("%s was hurt badly");
            }

            break;

        case dProf::EN_BIGPILE_UNDER:
        case dProf::EN_BIGPILE_UPPER:
        case dProf::EN_BIGPILE_RIGHT:
        case dProf::EN_BIGPILE_LEFT:
        case dProf::EN_SUPER_BIGPILE_RIGHT:
        case dProf::EN_SUPER_BIGPILE_LEFT:
        case dProf::EN_GOKUBUTO_BIGPILE_UNDER:
        case dProf::EN_GOKUBUTO_BIGPILE_UPPER:
            // "was skewered by Skewer"
            if (death) {
                msg("%s was skewered by %s");
            } else {
                msg("%s was penetrated by %s");
                msg("%s was pummeled by %s");
                msg("%s was destroyed by %s");
            }
            break;

        case dProf::EN_KILLER:
        case dProf::EN_SEARCH_KILLER:
        case dProf::EN_MAGNUM_KILLER:
        case dProf::EN_SEARCH_MAGNUM_KILLER:
            if (death) {
                msg("%s was shot by %s");
            } else {
                msg("%s was struck by %s");
            }
            break;

        case dProf::EN_KING_KILLER:
            if (death) {
                msg("%s was blasted by %s");
            } else {
                msg("%s was pummeled by %s");
            }
            break;

        case dProf::EN_ICICLE:
        case dProf::EN_BIG_ICICLE:
            if (death) {
                msg("%s was skewered by %s");
            } else {
                msg("%s was impaled by %s");
            }
            break;

        case dProf::EN_DOSUN:
        case dProf::EN_BIGDOSUN:
            if (death) {
                msg("%s was smashed by %s");
                msg("%s was thwomped by %s");
            } else {
                msg("%s was pounded by %s");
                msg("%s was thumped by %s");
            }
            break;

        case dProf::EN_KANITAMA:
            if (death) {
                msg("%s was finished by a rock");
                msg("%s was slain by a rock");

                // Three times for greater weight
                msg("%s was killed with a rock");
                msg("%s was killed with a rock");
                msg("%s was killed with a rock");
            } else {
                msg("%s came into contact with a rock");
            }
            msg("%s lost a fight with a rock");
            break;
        }
        break;

    case DamageType_e::ELEC_SHOCK:
        if (enemyName == nullptr) {
            if (death) {
                msg("%s was electrocuted");
            } else {
                msg("%s was shocked");
            }
        } else {
            if (death) {
                msg("%s was electrocuted by %s");
            } else {
                msg("%s was shocked by %s");
            }
        }
        break;

    case DamageType_e::LAVA:
        msg("%s tried to swim in lava");
        msg("%s fell into lava");
        break;

    case DamageType_e::POISON_WATER:
        msg("%s drank the weird lanky water");
        msg("%s fell into the poisonous jungle juice");
        msg("%s fell into the radioactive water");
        break;

    case DamageType_e::CRUSH:
        if (enemyName == nullptr) {
            if (death) {
                msg("%s was squished to death");
            }
            msg("%s was crushed by a heavy object");
            msg("%s was squished too much");
        } else {
            msg("%s was squashed by %s");
        }
        break;

    case DamageType_e::EAT_DIE:
    case DamageType_e::EAT_DIE2:
        if (enemyName == nullptr) {
            msg("%s was devoured");
            msg("%s was devoured by a hungry creature");
            msg("%s was devoured by a monster");
        } else {
            msg("%s was devoured by %s");
        }
        break;

    case DamageType_e::FREEZE:
    case DamageType_e::FREEZE2:
        if (enemyName == nullptr) {
            if (death) {
                msg("%s froze to death");
            } else {
                msg("%s was frozen solid");
            }
        } else {
            if (death) {
                msg("%s froze to death by %s");
            } else {
                msg("%s was frozen solid by %s");
            }
        }
        break;

    case DamageType_e::POISON_FOG:
        msg("%s couldn't escape the fog");
        msg("%s got lost in the fog");
        break;

    case DamageType_e::FALL_DOWN:
        if (enemyName == nullptr) {
            if (lastEnemyName) {
                enemyName = lastEnemyName;
                msg("%s couldn't live in the same world as %s");
                msg("%s was knocked off a cliff by %s");
                msg("%s stumbled over %s and fell off");
            } else {
                msg("%s fell off");
                msg("%s fell through the floor");
                msg("%s fell off (on purpose)");
            }

            msg("%s fell out of the world");
            msg("%s forgot how to jump");
            msg("%s thought there was ground there");
            msg("%s didn't want to play anymore");
            msg("%s lost the game");
            msg("%s you're not supposed to go down there");
            msg("%s what's it like down there");
            msg("%s left the confines of the world");
        } else {
            msg("%s fell off and dragged %s with them");
            msg("%s sacrificed themselves to take out %s");
            msg("%s thought the world better without %s");
            msg("~%s was dragged into the void by %s");
            msg("~%s was betrayed by %s");
        }
        break;

    case DamageType_e::SCROLL_OUT:
        if (enemyName == nullptr) {
            msg("%s met the wrath of the edge of the screen");
            msg("%s mysteriously vanished");
            msg("%s died because the screen scrolled too much");
            msg("The screen just went too far for %s");
            msg("%s left the confines of the screen");
            msg("%s died");
            msg("%s was left behind");
            msg("%s died because people need to slow down");
            msg("%s died because people need to slow down");
            msg("%s died because PEOPLE NEED TO SLOW DOWN!!!!");
        } else {
            msg("%s and %s couldn't handle the screen's edge");
            msg("%s and %s met the edge of the screen");
            msg("%s showed %s to the edge of the screen");
            msg("%s and %s were left behind");
            msg("%s and %s mysteriously vanished");
            msg("%s and %s died");
            msg("%s and %s died because people need to slow down");
        }
        break;
    }

    const char* message = nullptr;
    if (messageCount > 0) {
        message = messages[dGameCom::rndInt(messageCount)];
    } else {
        if (death) {
            message = "%s died";
        } else {
            message = "%s was hurt";
        }
    }

    if (enemyName == nullptr) {
        enemyName = "an unknown force";
    }

    daPlBase_c* player = this;
    if (message[0] == '~') {
        // Swap order of names
        const char* temp = selfName;
        selfName = enemyName;
        enemyName = temp;
        if (source) {
            if (auto player2 = source->DynamicCast<daPlBase_c>()) {
                player = player2;
            }
        }
    }

    char formattedMessage[128];
    std::snprintf(formattedMessage, sizeof(formattedMessage), message, selfName, enemyName);

    wchar_t wideMessage[128];
    std::mbstowcs(wideMessage, formattedMessage, std::size(wideMessage));

    dGameDisplay_c::m_instance->newDeathMessage(
      wideMessage, daPyMng_c::mPlayerType[*player->getPlrNo()]
    );
}
