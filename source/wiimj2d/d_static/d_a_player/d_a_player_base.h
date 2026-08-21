#pragma once

#include "d_profile/d_profile.h"
#include "d_static/d_a_player/d_a_player_key.h"
#include "d_static/d_actor/d_actor.h"
#include "d_static/d_cc.h"
#include "d_static/d_mj2d/d_mj2d_game.h"
#include "d_static/d_player_model/d_player_model_manager.h"
#include "d_static/d_quake.h"
#include "machine/m_mtx.h"
#include "sound/SndID.h"
#include "sound/SndObjectPlayer.h"
#include "state/s_State.h"
#include "state/s_StateMgrDefault.h"

struct sSpeedData;

class daPlBase_c : public dActor_c, public dProf::Info<daPlBase_c, dProf::PLAYER, dProf::YOSHI> {
    SIZE_ASSERT(0x14D4);

    /* 0x0060 VTABLE 0x803087C8 */

public:
    // Constants
    // ^^^^^^

    enum class DamageType_e {
        NORMAL             = 0,
        NORMAL2            = 1,
        KNOCKBACK_AND_HURT = 2,
        KNOCKBACK_LONG     = 3, // Player does not take damage
        KNOCKBACK_LONG2    = 4, // Player does not take damage
        KNOCKBACK_SHORT    = 5, // Player does not take damage
        KNOCKBACK_SHORT2   = 6, // Player does not take damage
        LAVA               = 7,
        FIRE               = 8, // Looks the same as NORMAL?
        ELEC_SHOCK         = 9,
        POISON_WATER       = 10,
        CRUSH              = 11,
        EAT_DIE            = 12,
        EAT_DIE2           = 13, // Like EAT_DIE but does not stop the music
        UNKNOWN            = 14,
        FREEZE             = 15,
        FREEZE2            = 16,
        BOUNCE             = 17, // Makes the player do a squishy animation
        POISON_FOG         = 18,

        // Added for death messages

        FALL_DOWN          = 20,
        SCROLL_OUT,
    };

    enum class DokanDir_e {
        U    = 0,
        D    = 1,
        L    = 2,
        R    = 3,
        ROLL = 4,
    };

    enum class StarSet_e {
        STAR_SET_0,
        STAR_SET_1,
        STAR_SET_2,
    };

    /**
     * Blending modes for animations.
     */
    enum class AnmBlend_e {
        /**
         * Do not blend between animations.
         */
        NONE    = 0,

        /**
         * Use the default blend duration specified in the animation HIO.
         */
        DEFAULT = 1,
    };

    enum ClearType_e {
        GOAL       = 0,
        BOSS       = 1,
        FINAL_BOSS = 2,
    };

    /* @unofficial */
    enum class GroundType_e {
        DEFAULT = 0,
        SNOW    = 1,
        SAND    = 2,
        ICE     = 3,
        DIRT    = 4,
        WATER   = 5,
        CLOUD   = 6,
        FUNSUI  = 7,
        MANTA   = 8,
        BEACH   = 9,
        CARPET  = 10,
        LEAF    = 11,
        WOOD    = 12,
    };

    /* @unofficial */
    enum SlipSubstate_e {
        SLIP_ACTION_NONE,
        SLIP_ACTION_STOOP,
        SLIP_ACTION_END,
    };

    /* @unofficial */
    enum HipSubstate_e {
        HIP_ACTION_READY,
        HIP_ACTION_ATTACK_START,
        HIP_ACTION_ATTACK_FALL,
        HIP_ACTION_GROUND,
        HIP_ACTION_STAND_NORMAL,
        HIP_ACTION_STAND_NORMAL_END,
        HIP_ACTION_TO_STOOP,
    };

    /* @unofficial */
    enum JumpDaiSubstate_e {
        /**
         * Moving down on the player or spring.
         */
        JUMP_DAI_MOVE_DOWN,
        /**
         * The jump button was pressed to do a higher jump.
         */
        JUMP_DAI_HIGH_JUMP,
    };

    /* @unofficial */
    enum FunsuiSubstate_e {
        FUNSUI_ACTION_NONE,
        FUNSUI_ACTION_START,
    };

    /* @unofficial */
    enum AnimePlaySubstate_e {
        ANIME_PLAY_ACTION_0,
        ANIME_PLAY_ACTION_1,
        ANIME_PLAY_ACTION_2,
    };

    /* @unofficial */
    enum DemoType_e {
        DEMO_0,
        DEMO_1,
        DEMO_2,
        DEMO_3,
        DEMO_PLAYER,
        DEMO_KINOPIO,
        DEMO_ENDING_DANCE,
    };

    /* @unofficial */
    enum DemoDokanMode_e {
        DEMO_DOKAN_NONE,
        DEMO_DOKAN_NORMAL,
        DEMO_DOKAN_RAIL,
        DEMO_DOKAN_WATER_TANK,
    };

    /**
     * Arguments for transitioning to the StateID_Crouch "crouch" state.
     * @unofficial
     */
    enum CrouchArg_e {
        /**
         * Crouching while already on the ground.
         */
        CROUCH_ARG_FROM_WALK,
        /**
         * Crouching after a slide or a ground pound.
         */
        CROUCH_ARG_FROM_OTHER,
        /**
         * Landing from a crouch jump.
         */
        CROUCH_ARG_FROM_SIT_JUMP,
    };

    /**
     * Arguments for transitioning to the StateID_HipAttack "ground pound" state.
     * @unofficial
     */
    enum class HipAttackArg_e {
        /**
         * A regular player is doing a ground pound.
         */
        HIP_ATTACK_ARG_PLAYER,
        /**
         * The rescue Toad is doing a ground pound out of the item block.
         * @unused
         */
        HIP_ATTACK_ARG_ITEM_KINOPIO,
    };

    /**
     * Arguments for transitioning to the StateID_Swim "swim" state.
     * @unofficial
     */
    enum class SwimArg_e {
        /**
         * Already in water at the start of the swim action.
         */
        INITIAL,
        /**
         * Just entered the water.
         */
        ENTERING,
        /**
         * Player was about to shoot a fireball, shoot it while in water.
         */
        FIREBALL,
        /**
         * Falling from a cliff into water.
         */
        CLIFF_HANG,
    };

    /**
     * Arguments for transitioning to the StateID_Kani "cliff" state.
     * @unofficial
     */
    enum class KaniArg_e {
        /**
         * Standing on the cliff and walking.
         */
        WALK,
        /**
         * Landing high enough on the cliff to stand on it, but hang down from it instead.
         */
        HANG,
        /**
         * Falling onto the cliff, immediately hang from it.
         */
        JUMP_HANG,
        /**
         * Standing on the cliff, disallow immediately hanging from it by holding down.
         */
        WALK_FORCE,
        /**
         * Climbing onto the cliff from a vine.
         */
        HANG_UP_VINE,
        /**
         * Catching the cliff from below, hang from it.
         */
        HANG_HAND,
    };

    /**
     * Arguments for transitioning to the StateID_AnimePlay "animation" state.
     */
    enum class AnimePlayArg_e {
        NORMAL,
        BOSS_SET_UP,
        BOSS_GLAD,
        BOSS_ATTENTION,
        BOSS_KEY_GET,
        BOSS_GLAD_2,
    };

    /**
     * Arguments for transitioning to the StateID_DemoWait "demo wait" state.
     * @unofficial
     */
    enum class DemoWaitArg_e {
        NONE,
        CONTROL,
    };

    /* @unofficial */
    enum class DemoWaitSubstate_e {
        DELAY,
        TRANSITION,
    };

    /* @unofficial */
    enum class DokanType_e {
        NORMAL,
        CONNECTED,
        MINI,
    };

    /* @unofficial */
    enum class DemoDownArg_e {
        HIT,
        TIME_UP,
        POISON,
        POISON_FOG,
    };

    /* @unofficial */
    enum class DemoGoalSubstate_e {
        POLE,
        WAIT,
        KIME_POSE,
        RUN,
    };

    /* @unofficial */
    enum class DemoGoalState_Pole_e {
        /**
         * Swinging around the pole to the other side.
         */
        SWING,
        /**
         * Waiting for the player below to slide far enough down the pole to not be in the way of
         * this player.
         */
        WAIT_BELOW_PLAYER,
        /**
         * Sliding down the pole.
         */
        SLIDE,
        /**
         * Waiting at the bottom of the pole to jump off.
         */
        WAIT_JUMP,
        /**
         * Jumping off the pole.
         */
        JUMP,
        /**
         * Playing the landing animation after landing.
         */
        LAND,
        /**
         * Waiting #sc_DemoPoleWaitTurn frames to turn toward the screen.
         */
        WAIT_TURN,
        /**
         * Turning toward the screen.
         */
        TURN,
        /**
         * Waiting #sc_DemoPoleWaitEnd frames before transitioning to the course clear dance.
         */
        WAIT_END,
    };

    /* @unofficial */
    enum class KimePoseMode_e {
        NONE,
        WITH_HAT,
        PENGUIN,
        NO_HAT,
        PROPELLER,
    };

    /* @unofficial */
    enum class ControlDemoSubstate_e : s8 {
        WAIT,
        WALK,
        REGULAR_ANIM,
        CUTSCENE_ANIM,
        CONTROL_DEMO_4,
        KINOPIO_WALK,
        KINOPIO_SWIM,
        KINOPIO_SINK_SAND,
        ENDING_DANCE,
    };

    /* @unofficial */
    enum class PowerChangeType_e {
        NORMAL,
        ICE,
        ICE_LOW_SLIP,
    };

    /* @unofficial */
    enum class SquishState_e {
        OFF,
        INIT,
        SET_REDUCTION,
        ANIMATION,
    };

    /* @unofficial */
    enum BgPress_e {
        BG_PRESS_FOOT = 9,
        BG_PRESS_HEAD,
        BG_PRESS_R,
        BG_PRESS_L,
        BG_PRESS_COUNT,
    };

    /* @unofficial */
    enum BgCross1_e {
        /**
         * Colliding with the foot sensor.
         */
        BGC_FOOT                  = 0_bit,
        /**
         * Colliding with the head sensor.
         */
        BGC_HEAD                  = 1_bit,
        /**
         * Colliding with the wall sensor.
         */
        BGC_WALL                  = 2_bit,
        BGC_WALL_TOUCH_L          = 3_bit,
        BGC_WALL_TOUCH_R          = 4_bit,
        BGC_WALL_TOUCH_L_2        = 5_bit,
        BGC_WALL_TOUCH_R_2        = 6_bit,
        /**
         * Touching a background object on the left.
         */
        BGC_OBJBG_TOUCH_L         = 7_bit,
        /**
         * Touching a background object on the right.
         */
        BGC_OBJBG_TOUCH_R         = 8_bit,
        /**
         * The touching background object on the left is being carried by a player.
         */
        BGC_OBJBG_TOUCH_CARRIED_L = 9_bit,
        /**
         * The touching background object on the right is being carried by a player.
         */
        BGC_OBJBG_TOUCH_CARRIED_R = 10_bit,
        BGC_11                    = 11_bit,
        BGC_12                    = 12_bit,
        BGC_13                    = 13_bit,
        /**
         * At least slightly inside of water (hip height or higher).
         */
        BGC_WATER_SHALLOW         = 14_bit,
        /**
         * At least touching water.
         */
        BGC_WATER_TOUCH           = 15_bit,
        /**
         * Fully submerged in water.
         */
        BGC_WATER_SUBMERGED       = 16_bit,
        /**
         * On water by being mini or sliding with the penguin suit.
         */
        BGC_ON_WATER_MOVE         = 17_bit,
        /**
         * Inside a floating water bubble.
         */
        BGC_WATER_BUBBLE          = 18_bit,
        BGC_SIDE_LIMIT_L          = 19_bit,
        BGC_SIDE_LIMIT_R          = 20_bit,
        BGC_ON_SNOW               = 22_bit,
        BGC_ON_ICE                = 23_bit,
        BGC_ON_ICE_LOW_SLIP       = 24_bit,
        BGC_SLOPE_AND_HEAD        = 25_bit,
        BGC_ON_SAND               = 26_bit,
        BGC_ON_SINK_SAND          = 27_bit,
        BGC_IN_SINK_SAND          = 28_bit,
        BGC_INSIDE_SINK_SAND      = 29_bit,
        BGC_ON_BELT_L             = 30_bit,
        BGC_ON_BELT_R             = 31_bit,
    };

    /* @unofficial */
    enum BgCross2_e {
        BGC_SEMISOLID           = 0_bit,
        /**
         * [Figure out a better name for this].
         */
        BGC_LIFT                = 1_bit,
        BGC_HANG_ROPE           = 2_bit,
        BGC_AUTOSLIP            = 3_bit,
        BGC_36                  = 4_bit,
        BGC_GROUNDED_MOVE_UP    = 5_bit,
        /**
         * Cannot wall kick or ground pound while this is set.
         */
        BGC_37                  = 6_bit,
        BGC_SLOPE               = 7_bit,
        BGC_CLIFF               = 8_bit,
        BGC_CLIFF_ABOVE_1       = 9_bit,
        BGC_CLIFF_ABOVE_2       = 10_bit,
        BGC_CAN_CLIMB           = 11_bit,
        BGC_44                  = 12_bit,
        /**
         * Fully touching a vine / mesh net / rock wall.
         */
        BGC_VINE_TOUCH_FULL     = 13_bit,
        /**
         * Touching a vine / mesh net / rock wall on the top.
         */
        BGC_VINE_TOUCH_U        = 14_bit,
        /**
         * Touching a vine / mesh net / rock wall on the bottom.
         */
        BGC_VINE_TOUCH_D        = 15_bit,
        BGC_VINE_TOUCH_2        = 16_bit,
        /**
         * Touching a vine / mesh net / rock wall on any side.
         */
        BGC_VINE_TOUCH          = 17_bit,
        /**
         * Touching a vine / mesh net / rock wall on the left.
         */
        BGC_VINE_TOUCH_L        = 19_bit,
        /**
         * Touching a vine / mesh net / rock wall on the right.
         */
        BGC_VINE_TOUCH_R        = 20_bit,
        BGC_NON_BREAK_BLOCK_HIT = 21_bit,
        BGC_54                  = 22_bit,
        BGC_PRESS_HEAD_HIT      = 23_bit,
        BGC_BLOCK_HIT           = 24_bit,
        BGC_57                  = 25_bit,
        BGC_58                  = 26_bit,
        BGC_LINE_BLOCK_HIT      = 27_bit,
        BGC_60                  = 28_bit,
        BGC_61                  = 29_bit,
        BGC_62                  = 30_bit,
        BGC_63                  = 31_bit,
    };

    /**
     * The status IDs to be used with onStatus(), offStatus(), isStatus() and setStatus().
     * @unofficial
     */
    enum class Status_e {
        /**
         * The player was created.
         */
        CREATED                       = 0,
        /**
         * The player can execute this frame or not.
         */
        CAN_EXECUTE                   = 1,
        /**
         * Don't play any animations.
         */
        NO_ANIM                       = 2,
        /**
         * Disallow state changes.
         */
        DISABLE_STATE_CHANGE          = 3,
        /**
         * The player is in a bubble or has died.
         */
        OUT_OF_PLAY                   = 4,
        /**
         * All players have died and the screen is transitioning.
         */
        ALL_DOWN_FADE                 = 5,
        /**
         * Stunned by electric shock or ice.
         */
        STUNNED                       = 6,
        /**
         * [Ice related]
         */
        UNKNOWN_7                     = 7,
        /**
         * The player was stunned by an earthquake.
         */
        QUAKE                         = 8,
        /**
         * The player is jumping.
         */
        JUMP                          = 10,
        /**
         * If the player can start sliding as a penguin.
         */
        CAN_PENGUIN_SLIDE             = 11,
        /**
         * The player is jumping while in star mode.
         */
        STAR_JUMP                     = 12,
        /**
         * The player is doing a crab jump on a cliff.
         */
        KANI_JUMP                     = 13,
        /**
         * The player is jumping while in sinking sand.
         */
        SINK_SAND_JUMP                = 14,
        /**
         * The player is doing a sitting jump.
         */
        SIT_JUMP                      = 15,
        /**
         * The player is doing a jump to dismount Yoshi.
         */
        YOSHI_DISMOUNT_JUMP           = 16,
        /**
         * The player is flying out of a pipe cannon.
         */
        CANNON_JUMP                   = 17,
        /**
         * The player is doing a small hop after being affected by a small quake.
         */
        WAIT_JUMP                     = 18,
        /**
         * The player is sliding down a wall.
         */
        WALL_SLIDE                    = 19,
        /**
         * The player is doing a jump on a spring or another player.
         */
        BIG_JUMP                      = 20,
        /**
         * The player is doing a jump on a springboard.
         */
        SPRING_JUMP                   = 21,
        /**
         * The player is doing a jump on another player.
         */
        PLAYER_JUMP                   = 22,
        /**
         * [Dokan related]
         */
        UNKNOWN_23                    = 23,
        /**
         * The player is throwing something.
         */
        THROW                         = 24,
        /**
         * The player is doing a crab walk on a cliff.
         */
        KANI_WALK                     = 25,
        /**
         * The player is falling while ground pounding.
         */
        HIP_ATTACK_FALL               = 28,
        /**
         * The player has landed after ground pounding. Only active on one frame.
         */
        HIP_ATTACK_LAND               = 29,
        /**
         * The player is standing up after ground pounding. Only active on one frame.
         */
        HIP_ATTACK_STAND_UP           = 30,
        /**
         * The player is falling while doing a down spin.
         */
        SPIN_HIP_ATTACK_FALL          = 31,
        SPIN_HIP_ATTACK_LANDED        = 32,
        SPIN_HIP_ATTACK_LANDING       = 33,
        /**
         * The player is is attached to a enemy while ground pounding or doing a down spin. [Used
         * for the big goombas].
         */
        PRESS_ATTACH                  = 34,
        /**
         * The player was ground pounded by another player.
         */
        HIP_ATTACK_DAMAGE_PLAYER      = 35,
        /**
         * The player is flying with the propeller suit.
         */
        PROPEL                        = 38,
        /**
         * The player is flying upwards with the propeller suit.
         */
        PROPEL_UP                     = 39,
        /**
         * The player will fall slowly while spinning down with the propeller suit.
         */
        PROPEL_SLOW_FALL              = 41,
        /**
         * Don't rotate the player because of the propeller suit.
         */
        PROPEL_NO_ROLL                = 42,
        /**
         * The player is spinning, either from a spin jump, a propeller spin (upwards or downwards)
         * or screw spinning.
         */
        SPIN                          = 43,
        /**
         * If the player spins, stay in place. [Used for the twisting screws].
         */
        IS_SPIN_HOLD_REQ              = 44,
        /**
         * The player is twirling in midair.
         */
        TWIRL                         = 45,
        /**
         * The player was twirling in midair the previous frame.
         */
        WAS_TWIRL                     = 46,
        /**
         * The player is clinging to a vine / mesh net / rock wall.
         */
        VINE                          = 51,
        /**
         * The player is hanging from a ceiling rope.
         */
        HANG                          = 52,
        /**
         * The player is climbing a pole.
         */
        POLE                          = 53,
        /**
         * The player is hanging from a cliff.
         */
        KANI_HANG                     = 55,
        /**
         * The player is animating into the hanging pose on a cliff.
         */
        KANI_HANG_ANIMATION           = 56,
        /**
         * [Swim related]
         */
        UNKNOWN_57                    = 57,
        /**
         * The player is swimming.
         */
        SWIM                          = 58,
        /**
         * The player is swimming with the penguin suit.
         */
        PENGUIN_SWIM                  = 59,
        /**
         * The player is sliding with the penguin suit.
         */
        PENGUIN_SLIDE                 = 60,
        /**
         * The player is doing a penguin slide jump.
         */
        PENGUIN_SLIDE_JUMP            = 61,
        /**
         * The player is in an initial slide action. [Used in 6-6 to slide all the way down
         * automatically].
         */
        INITIAL_SLIDE                 = 62,
        /**
         * The player is bouncing back after hitting an enemy that cannot be killed by a penguin
         * slide.
         */
        PENGUIN_RECOIL                = 63,
        /**
         * [Water jump?]
         */
        UNKNOWN_64                    = 64,
        /**
         * The player is swimming against a horizontal water jet stream.
         */
        SWIM_AGAINST_JET_H            = 65,
        /**
         * The player is swimming against a vertical water jet stream.
         */
        SWIM_AGAINST_JET_V            = 66,
        /**
         * The player is riding Yoshi.
         */
        RIDE_YOSHI                    = 75,
        /**
         * The player recently failed to perform a big jump because of a ceiling.
         */
        JUMP_DAI_COOLDOWN             = 77,
        RIDE_NUT_2                    = 88,
        RIDE_NUT                      = 89,
        /**
         * The player has cleared an enemy ambush.
         */
        ENEMY_STAGE_CLEAR             = 96,
        /**
         * The player has touched the goal pole.
         */
        GOAL_POLE_TOUCHED             = 101,
        /**
         * The player is waiting for the player below to slide down the goal pole.
         */
        GOAL_POLE_WAIT_BELOW_PLAYER   = 102,
        /**
         * The player has reached the bottom of the goal pole after sliding down.
         */
        GOAL_POLE_FINISHED_SLIDE_DOWN = 104,
        /**
         * The player is ready to jump off the goal pole.
         */
        GOAL_POLE_READY_FOR_JUMP_OFF  = 105,
        /**
         * The player is turning toward the screen after jumping off the goal pole.
         */
        GOAL_POLE_TURN                = 106,
        /**
         * The player did not reach the goal pole in time and mustn't move anymore.
         */
        GOAL_POLE_NOT_GOAL_NO_MOVE    = 111,
        ENDING_DANCE_AUTO             = 117,
        /**
         * The player is transitioning after touching a next goto area.
         */
        DEMO_NEXT_GOTO_BLOCK          = 118,
        /**
         * Stop executing this player indefinitely.
         */
        STOP_EXECUTE                  = 125,
        /**
         * A big quake that stuns the player was triggered.
         */
        QUAKE_BIG                     = 139,
        /**
         * A small quake that makes the player do a hop was triggered.
         */
        QUAKE_SMALL                   = 140,
        /**
         * [Cannon shot related]
         */
        UNKNOWN_141                   = 141,
        /**
         * [Cannon shot related]
         */
        UNKNOWN_142                   = 142,
        /**
         * The player can land on Yoshi or another player.
         */
        CAN_LAND                      = 143,
        /**
         * [Jump moving up?]
         */
        UNKNOWN_165                   = 165,
        /**
         * The player is about to shoot a fireball.
         */
        FIREBALL_PREPARE_SHOOT        = 166,
        /**
         * Mini Goombas are attached to the player.
         */
        FOLLOW_MAME_KURIBO            = 172,
        /**
         * The player is in the penguin suit.
         */
        IS_PENGUIN                    = 173,
        /**
         * The player is in the ground pound action and is not yet about to stand back up.
         */
        HIP_ATTACK                    = 174,
        UNKNOWN_179                   = 179, // [Yoshi only?]
        ABOUT_TO_BE_DELETED           = 181,
        ITEM_KINOPIO_DISPLAY_OUT      = 182,
        /**
         * The player is outside of the screen bounds and should die as a result.
         */
        DISPLAY_OUT_DEAD              = 185,
        /**
         * The player is outside of the screen bounds and should not be able to be attacked.
         */
        DISPLAY_OUT_NO_DAMAGE         = 186,
        /**
         * The player is invisible.
         */
        INVISIBLE                     = 187,
        /**
         * Skip drawing the player this frame to create a blinking effect.
         */
        INVULNERABLILITY_BLINK        = 188,
        /**
         * The player can walk on water because of the mini mushroom.
         */
        CAN_WATER_WALK                = 193,
        /**
         * The player is on water by being mini or sliding with the penguin suit.
         */
        ON_WATER_MOVE                 = 194,
        /**
         * The player can slide on water because of the penguin suit.
         */
        CAN_WATER_SLIDE               = 195,
    };

    static const float sc_DirSpeed[];
    static const float sc_JumpSpeed;
    static const float sc_JumpSpeedNuma1;
    static const float sc_JumpSpeedNuma2;
    static const float sc_WaterWalkSpeed;
    static const float sc_WaterSwimSpeed;
    static const float sc_WaterJumpSpeed;
    static const float sc_WaterMaxFallSpeed;
    static const float sc_MaxFallSpeed;
    static const float sc_MaxFallSpeed_Foot;
    static const float sc_MaxFallDownSpeed;
    static const float scTurnPowerUpRate;
    static const float scDokanInSpeedX;
    static const float scDokanInWidthX;
    static const float scDokanInMoveSpeed;
    static const float scDokanWaitAnmFixFrame;

public:
    // Nested Types
    // ^^^^^^

    class jmpInf_c;

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0D4 0x80046DF0 */
    virtual void executeMain();

    /* VT+0x0D8 0x800588F0 */
    virtual void executeLastPlayer();

    /* VT+0x0DC 0x800588E0 */
    virtual void executeLastAll();

    /* VT+0x0E0 0x80020BE0 */
    virtual bool isItemKinopio() { return false; }

    /* VT+0x0E4 0x80056BC0 @unofficial */
    virtual void setPowerup(PLAYER_MODE_e powerup, PLAYER_MODE_e);

    /* VT+0x0E8 0x80056D40 */
    virtual u8 getTallType(s8 param);

    /* VT+0x0EC 0x80048080 */
    virtual const sBcPointData* getHeadBgPointData();

    /* VT+0x0F0 0x80054EE0 */
    virtual const sBcPointData* getWallBgPointData();

    /* VT+0x0F4 0x80056BB0 */
    virtual const sBcPointData* getFootBgPointData();

    /* VT+0x0F8 0x80048090 */
    virtual float getStandHeadBgPointY();

    /* VT+0x0FC 0x800544E0 */
    virtual void checkBgCrossSub();

    /* VT+0x100 0x80054F80 */
    virtual void postBgCross();

    /* VT+0x104 0x800552C0 */
    virtual f32 getSandSinkRate();

    /* VT+0x108 0x80053F90 */
    virtual void setReductionScale();

    /* VT+0x10C 0x80053FE0 */
    virtual void initStampReduction();

    /* VT+0x110 0x80054070 */
    virtual void calcJumpDaiReductionScale(int param1, int param2);

    /* VT+0x114 0x800540D0 */
    virtual void setReductionBoyon();

    /* VT+0x118 0x800564F0 */
    virtual bool setPressBgDamage(int param1, int param2);

    /* VT+0x11C 0x80056360 */
    virtual bool setBalloonInDispOut(int param);

    /* VT+0x120 0x8004DCF0 */
    virtual bool isChange();

    /* VT+0x124 0x8004DF70 */
    virtual void changeNextScene(int param);

    /* VT+0x128 0x8004F260 */
    virtual bool isEnableDokanInStatus();

    /* VT+0x12C 0x80051080 */
    virtual bool setHideNotGoalPlayer();

    /* VT+0x130 0x80050E60 */
    virtual int setDemoGoal(mVec3_c& landPos, float goalCastleX, u8 goalType);

    /* VT+0x134 0x80050E70 */
    virtual bool setDemoCannonWarp(int param1, short param2, short param3);

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: VT+0x138 0x8004E450
     * executeState:    VT+0x13C 0x8004E4D0
     * finalizeState:   VT+0x140 0x8004E4C0
     */
    sState_ExternVirtual(0x80354A6C, daPlBase_c, DemoNone);

    /**
     * initializeState: VT+0x144 0x8004E700
     * executeState:    VT+0x148 0x8004E710
     * finalizeState:   VT+0x14C 0x8004E7A0
     */
    sState_ExternVirtual(0x80354AAC, daPlBase_c, DemoStartWait);

    /**
     * initializeState: VT+0x150 0x8004E7B0
     * executeState:    VT+0x154 0x8004E820
     * finalizeState:   VT+0x158 0x8004E810
     */
    sState_ExternVirtual(0x80354AEC, daPlBase_c, DemoWait);

    /**
     * initializeState: VT+0x15C 0x8004F100
     * executeState:    VT+0x160 0x8004F120
     * finalizeState:   VT+0x164 0x8004F110
     */
    sState_ExternVirtual(0x80354B2C, daPlBase_c, DemoInDokanU);

    /**
     * initializeState: VT+0x168 0x8004F130
     * executeState:    VT+0x16C 0x8004F150
     * finalizeState:   VT+0x170 0x8004F140
     */
    sState_ExternVirtual(0x80354B6C, daPlBase_c, DemoInDokanD);

    /**
     * initializeState: VT+0x174 0x8004F190
     * executeState:    VT+0x178 0x8004F1B0
     * finalizeState:   VT+0x17C 0x8004F1A0
     */
    sState_ExternVirtual(0x80354BAC, daPlBase_c, DemoInDokanR);

    /**
     * initializeState: VT+0x180 0x8004F160
     * executeState:    VT+0x184 0x8004F180
     * finalizeState:   VT+0x188 0x8004F170
     */
    sState_ExternVirtual(0x80354BEC, daPlBase_c, DemoInDokanL);

    /**
     * initializeState: VT+0x18C 0x8004FE70
     * executeState:    VT+0x190 0x8004FE90
     * finalizeState:   VT+0x194 0x8004FE80
     */
    sState_ExternVirtual(0x80354C2C, daPlBase_c, DemoOutDokanU);

    /**
     * initializeState: VT+0x198 0x8004FEA0
     * executeState:    VT+0x19C 0x8004FEC0
     * finalizeState:   VT+0x1A0 0x8004FEB0
     */
    sState_ExternVirtual(0x80354C6C, daPlBase_c, DemoOutDokanD);

    /**
     * initializeState: VT+0x1A4 0x8004FF00
     * executeState:    VT+0x1A8 0x8004FF20
     * finalizeState:   VT+0x1AC 0x8004FF10
     */
    sState_ExternVirtual(0x80354CAC, daPlBase_c, DemoOutDokanR);

    /**
     * initializeState: VT+0x1B0 0x8004FED0
     * executeState:    VT+0x1B4 0x8004FEF0
     * finalizeState:   VT+0x1B8 0x8004FEE0
     */
    sState_ExternVirtual(0x80354CEC, daPlBase_c, DemoOutDokanL);

    /**
     * initializeState: VT+0x1BC 0x8004FF30
     * executeState:    VT+0x1C0 0x8004FFA0
     * finalizeState:   VT+0x1C4 0x8004FF90
     */
    sState_ExternVirtual(0x80354D2C, daPlBase_c, DemoOutDokanRoll);

    /**
     * initializeState: VT+0x1C8 0x800502A0
     * executeState:    VT+0x1CC 0x80050380
     * finalizeState:   VT+0x1D0 0x80050370
     */
    sState_ExternVirtual(0x80354D6C, daPlBase_c, DemoInWaterTank);

    /**
     * initializeState: VT+0x1D4 0x800504B0
     * executeState:    VT+0x1D8 0x80050540
     * finalizeState:   VT+0x1DC 0x80050530
     */
    sState_ExternVirtual(0x80354DAC, daPlBase_c, DemoOutWaterTank);

    /**
     * initializeState: VT+0x1E0 0x80050870
     * executeState:    VT+0x1E4 0x80050AF0
     * finalizeState:   VT+0x1E8 0x800509F0
     */
    sState_ExternVirtual(0x80354DEC, daPlBase_c, DemoRailDokan);

    /**
     * initializeState: VT+0x1EC 0x80050E30
     * executeState:    VT+0x1F0 0x80050E50
     * finalizeState:   VT+0x1F4 0x80050E40
     */
    sState_ExternVirtual(0x80354E2C, daPlBase_c, DemoDown);

    /**
     * initializeState: VT+0x1F8 0x80052FE0
     * executeState:    VT+0x1FC 0x80053090
     * finalizeState:   VT+0x200 0x80053040
     */
    sState_ExternVirtual(0x80354E6C, daPlBase_c, DemoNextGotoBlock);

    /**
     * initializeState: VT+0x204 0x80051400
     * executeState:    VT+0x208 0x80051AB0
     * finalizeState:   VT+0x20C 0x80051410
     */
    sState_ExternVirtual(0x80354EAC, daPlBase_c, DemoGoal);

    /**
     * initializeState: VT+0x210 0x80052730
     * executeState:    VT+0x214 0x80052900
     * finalizeState:   VT+0x218 0x80052880
     */
    sState_ExternVirtual(0x80354EEC, daPlBase_c, DemoControl);

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x21C 0x8004D820 */
    virtual void initialDokanUnder();

    /* VT+0x220 0x8004D830 */
    virtual void initialDokanUper();

    /* VT+0x224 0x8004D840 */
    virtual void initialDokanRight();

    /* VT+0x228 0x8004D850 */
    virtual void initialDokanLeft();

    /* VT+0x22C 0x8004D860 */
    virtual void initialDokanUnderM();

    /* VT+0x230 0x8004D870 */
    virtual void initialDokanUperM();

    /* VT+0x234 0x8004D880 */
    virtual void initialDokanRightM();

    /* VT+0x238 0x8004D890 */
    virtual void initialDokanLeftM();

    /* VT+0x23C 0x8004D8A0 */
    virtual void initialDokanDepth();

    /* VT+0x240 0x8004D8B0 */
    virtual void initialDoor();

    /* VT+0x244 0x8004D8F0 */
    virtual void initialFall();

    /* VT+0x248 0x8004D8E0 */
    virtual void initialVine();

    /* VT+0x24C 0x8004D8C0 */
    virtual void initialJumpRight();

    /* VT+0x250 0x8004D8D0 */
    virtual void initialJumpLeft();

    /* VT+0x254 0x8004D960 */
    virtual void initialHipAttack();

    /* VT+0x258 0x8004D9C0 */
    virtual void initialSlip();

    /* VT+0x25C 0x8004DA20 */
    virtual void initialSwim();

    /* VT+0x260 0x8004DA70 */
    virtual void initialBlockJump();

    /* VT+0x264 0x8004DA80 */
    virtual void initialBlockJumpBelow();

    /* VT+0x268 0x8004DA30 */
    virtual void initialTorideBoss();

    /* VT+0x26C 0x8004DA90 */
    virtual void initialNormal();

    /* VT+0x270 0x8004DB00 */
    virtual void setCreateAction(int param);

    /* VT+0x274 0x8004E280 */
    virtual bool setTimeOverDemo();

    /* VT+0x278 0x80055E00 */
    virtual void setFallDownDemo();

    /* VT+0x27C 0x8004F300 */
    virtual bool setDokanIn(DokanDir_e dir);

    /* VT+0x280 0x8004F670 */
    virtual void initDemoOutDokan();

    /* VT+0x284 0x80051CF0 @unofficial */
    virtual bool updateDemoKimePose(s32 clearType);

    /* VT+0x288 0x80051240 */
    virtual void initDemoGoalBase();

    /* VT+0x28C 0x80051A90 */
    virtual void executeDemoGoal_Run();

    /* VT+0x290 0x80052870 */
    virtual void initializeDemoControl();

    /* VT+0x294 0x80047390 */
    virtual void changeState(const sStateIDIf_c& state, void* param);

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: VT+0x298 0x800475B0
     * executeState:    VT+0x29C 0x800475D0
     * finalizeState:   VT+0x2A0 0x800475C0
     */
    sState_ExternVirtual(0x8035451C, daPlBase_c, None);

    /**
     * initializeState: VT+0x2A4 0x80047790
     * executeState:    VT+0x2A8 0x800477B0
     * finalizeState:   VT+0x2AC 0x800477A0
     */
    sState_ExternVirtual(0x8035455C, daPlBase_c, Walk);

    /**
     * initializeState: VT+0x2B0 0x800479A0
     * executeState:    VT+0x2B4 0x80047AC0
     * finalizeState:   VT+0x2B8 0x80047A00
     */
    sState_ExternVirtual(0x8035459C, daPlBase_c, Jump);

    /**
     * initializeState: VT+0x2BC 0x80047BE0
     * executeState:    VT+0x2C0 0x80047C00
     * finalizeState:   VT+0x2C4 0x80047BF0
     */
    sState_ExternVirtual(0x803545DC, daPlBase_c, SitJump);

    /**
     * initializeState: VT+0x2C8 0x80047C40
     * executeState:    VT+0x2CC 0x80047D60
     * finalizeState:   VT+0x2D0 0x80047D10
     */
    sState_ExternVirtual(0x8035461C, daPlBase_c, Fall);

    /**
     * initializeState: VT+0x2D4 0x80047D80
     * executeState:    VT+0x2D8 0x80047DA0
     * finalizeState:   VT+0x2DC 0x80047D90
     */
    sState_ExternVirtual(0x8035465C, daPlBase_c, Land);

    /**
     * initializeState: VT+0x2E0 0x800480A0
     * executeState:    VT+0x2E4 0x800480C0
     * finalizeState:   VT+0x2E8 0x800480B0
     */
    sState_ExternVirtual(0x8035469C, daPlBase_c, Crouch);

    /**
     * initializeState: VT+0x2EC 0x800480D0
     * executeState:    VT+0x2F0 0x800481C0
     * finalizeState:   VT+0x2F4 0x80048170
     */
    sState_ExternVirtual(0x803546DC, daPlBase_c, Slip);

    /**
     * initializeState: VT+0x2F8 0x80048C00
     * executeState:    VT+0x2FC 0x80048C20
     * finalizeState:   VT+0x300 0x80048C10
     */
    sState_ExternVirtual(0x8035471C, daPlBase_c, Turn);

    /**
     * initializeState: VT+0x304 0x800497E0
     * executeState:    VT+0x308 0x80049940
     * finalizeState:   VT+0x30C 0x80049880
     */
    sState_ExternVirtual(0x8035475C, daPlBase_c, HipAttack);

    /**
     * initializeState: VT+0x310 0x80049A10
     * executeState:    VT+0x314 0x80049A30
     * finalizeState:   VT+0x318 0x80049A20
     */
    sState_ExternVirtual(0x8035479C, daPlBase_c, Swim);

    /**
     * initializeState: VT+0x31C 0x80049AB0
     * executeState:    VT+0x320 0x80049BB0
     * finalizeState:   VT+0x324 0x80049B60
     */
    sState_ExternVirtual(0x803547DC, daPlBase_c, JumpDai);

    /**
     * initializeState: VT+0x328 0x80049E10
     * executeState:    VT+0x32C 0x80049FA0
     * finalizeState:   VT+0x330 0x80049F50
     */
    sState_ExternVirtual(0x8035481C, daPlBase_c, PlayerJumpDai);

    /**
     * initializeState: VT+0x334 0x8004A400
     * executeState:    VT+0x338 0x8004A510
     * finalizeState:   VT+0x33C 0x8004A4D0
     */
    sState_ExternVirtual(0x8035485C, daPlBase_c, Funsui);

    /**
     * initializeState: VT+0x340 0x8004A670
     * executeState:    VT+0x344 0x8004A690
     * finalizeState:   VT+0x348 0x8004A680
     */
    sState_ExternVirtual(0x8035489C, daPlBase_c, Kani);

    /**
     * initializeState: VT+0x34C 0x8004A830
     * executeState:    VT+0x350 0x8004AA50
     * finalizeState:   VT+0x354 0x8004A8C0
     */
    sState_ExternVirtual(0x803548DC, daPlBase_c, Cloud);

    /**
     * initializeState: VT+0x358 0x8004AA60
     * executeState:    VT+0x35C 0x8004AAC0
     * finalizeState:   VT+0x360 0x8004AA80
     */
    sState_ExternVirtual(0x8035491C, daPlBase_c, AnimePlay);

    /**
     * initializeState: VT+0x364 0x8004AFE0
     * executeState:    VT+0x368 0x8004B0D0
     * finalizeState:   VT+0x36C 0x8004B090
     */
    sState_ExternVirtual(0x8035495C, daPlBase_c, WaitJump);

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x370 0x800588C0 */
    virtual bool isWaitFrameCountMax();

    /* VT+0x374 0x8004AB80 */
    virtual bool checkWalkNextAction();

    /* VT+0x378 0x800475E0 */
    virtual void setWaitActionAnm(AnmBlend_e);

    /* VT+0x37C 0x800475F0 */
    virtual void setWalkActionAnm(AnmBlend_e);

    /* VT+0x380 0x80047600 */
    virtual void walkActionInit_Wait(AnmBlend_e);

    /* VT+0x384 0x80047610 */
    virtual void walkAction_Wait();

    /* VT+0x388 0x80047620 */
    virtual void walkActionInit_Move(AnmBlend_e);

    /* VT+0x38C 0x80047630 */
    virtual void walkAction_Move();

    /* VT+0x390 0x80047DB0 */
    virtual bool checkCrouch();

    /* VT+0x394 0x80047DC0 */
    virtual bool setCancelCrouch();

    /* VT+0x398 0x8004B220 */
    virtual void setSlipAction();

    /* VT+0x39C 0x80048630 */
    virtual void slipActionMove(int);

    /* VT+0x3A0 0x80047C10 */
    virtual void setFallAction();

    /* VT+0x3A4 0x80048F30 */
    virtual void setHipAttack_AttackStart();

    /* VT+0x3A8 0x8004A3E0 */
    virtual void releaseFunsuiAction();

    /* VT+0x3AC 0x8004A7A0 */
    virtual f32 getCloudOffsetY();

    /* VT+0x3B0 0x800588B0 */
    virtual bool setRideJrCrown(const dActor_c*);

    /* VT+0x3B4 0x800588A0 */
    virtual bool isRideJrCrownOwn(const dActor_c*);

    /* VT+0x3B8 0x80058890 */
    virtual void setRideJrCrownMtx(const mMtx_c* mtx);

    /* VT+0x3BC 0x80058880 */
    virtual void setRideJrCrownAnm(int anm);

    /* VT+0x3C0 0x80049D60 */
    virtual const mVec3_c* getHeadTopPosP();

    /* VT+0x3C4 0x80049040 */
    virtual const float* getGravityData();

    /* VT+0x3C8 0x80048B90 */
    virtual bool isCarry() const;

    /* VT+0x3CC 0x80053DE0 */
    virtual bool isLiftUp();

    /* VT+0x3D0 0x80056C20 */
    virtual bool isLiftUpExceptMame();

    /* VT+0x3D4 0x80022170 */
    virtual bool isStar() const;

    /* VT+0x3D8 0x80058190 */
    virtual void setStar(StarSet_e, int);

    /* VT+0x3DC 0x80051360 */
    virtual void endStar();

    /* VT+0x3E0 0x80058870 */
    virtual void setVirusStar(daPlBase_c*);

    /* VT+0x3E4 0x800581D0 */
    virtual void clearStarCount();

    /* VT+0x3E8 0x8002D970 */
    virtual int getStarCount() const;

    /* VT+0x3EC 0x800581E0 */
    virtual s8 calcStarCount(int max);

    /* VT+0x3F0 0x80057B30 */
    virtual bool isNoDamage();

    /* VT+0x3F4 0x80057B40 */
    virtual bool setDamage(dActor_c* source, DamageType_e type);

    /* VT+0x3F8 0x80057B50 */
    virtual bool setForcedDamage(dActor_c* source, DamageType_e type);

    /* VT+0x3FC 0x80057B70 */
    virtual bool setJump(float jumpSpeed, float speedF, bool allowSteer, int keyMode, int jumpMode);

    /* VT+0x400 0x80057B80 */
    virtual bool
    _setJump(float jumpSpeed, float speedF, bool allowSteer, int keyMode, int jumpMode);

    /* VT+0x404 0x80057B90 */
    virtual void setWaitJump(f32);

    /* VT+0x408 0x80048C30 */
    virtual bool setHipAttackOnEnemy(mVec3_c* hitPos);

    /* VT+0x40C 0x80051350 */
    virtual void clearJumpActionInfo(int);

    /* VT+0x410 0x80057C30 */
    virtual bool setSwimSpeed(f32, f32);

    /* VT+0x414 0x8004C990 */
    virtual void setLandSE();

    /* VT+0x418 0x80058860 */
    virtual void set1UpKinokoEffect();

    /* VT+0x41C 0x80058850 */
    virtual void setFlagGetEffect();

    /* VT+0x420 0x80058C70 */
    virtual void setHipAttackEffect();

    /* VT+0x424 0x800576A0 */
    virtual void setZPosition();

    /* VT+0x428 0x80057760 */
    virtual void setZPosition(f32);

    /* VT+0x42C 0x800577D0 */
    virtual void setZPositionDirect(f32);

    /* VT+0x430 0x80057810 */
    virtual void offZPosSetNone();

    /* VT+0x434 0x80058050 @unofficial */
    virtual void playVoice(SndObjctPly::PLAYER_VOICE_e voice, int param2);

    /* VT+0x438 0x800580B0 */
    virtual void VT_0x438();

    /* VT+0x43C 0x80058280 */
    virtual void startQuakeShock(dQuake_c::TYPE_SHOCK_e);

    /* VT+0x440 0x800582A0 */
    virtual void startPatternRumble(const char*);

    /* VT+0x444 0x80047480 */
    virtual s16 getMukiAngle(u8);

    /* VT+0x448 0x80047490 */
    virtual bool turnAngle();

    /* VT+0x44C 0x8004C470 */
    virtual void maxFallSpeedSet();

    /* VT+0x450 0x80057B60 */
    virtual bool setDamage2(dActor_c* source, DamageType_e type);

public:
    // Instance Methods
    // ^^^^^^

    void executeState();

    /* 0x8004DB40 */
    bool isDemoType(DemoType_e type);

    /* 0x8004DD00 */
    bool isDemo();

    /* 0x8004DDE0 */
    bool isDemoAll();

    /* 0x8004E040 */
    bool isPlayerGameStop();

    /* 0x8004E050 */
    void stopOther();

    /* 0x8004E100 */
    void playOther();

    /* 0x8004E290 */
    void changeDemoState(const sStateIDIf_c& state, int param);

    /* 0x8004E920 */
    void getWaterDokanCenterOffset(float);

    /* 0x8004E980 */
    void initDemoInDokan();

    /* 0x8004EA20 */
    void endDemoInDokan();

    /* 0x8004EA80 */
    void executeDemoInDokan(u8 param);

    /* 0x8004EDE0 */
    void initDemoInDokanUD(u8 param);

    /* 0x8004EFD0 */
    void initDemoInDokanLR(u8 param);

    /* 0x80050D80 */
    bool isDispOutCheckOn();

    /* 0x80050A00 */
    void setExitRailDokan();

    /* 0x800510F0 */
    void stopGoalOther();

    /* 0x800511A0 */
    void playGoalOther();

    /* 0x80051E70 */
    bool startControlDemo();

    /* 0x80051EF0 */
    void endControlDemo(int param);

    /* 0x80051F30 */
    void setControlDemoDir(u8 direction);

    /* 0x80052030 */
    [[nodiscard]]
    bool isControlDemoWait();

    /* 0x80052080 */
    void setControlDemoWalk(const f32& pos, const f32& speed);

    /* 0x80052170 */
    void setControlDemoAnm(int anim);

    void UNDEF_80052290(s32 param);

    /* 0x80052300 */
    void setControlDemoKinopioWalk();

    /* 0x80052470 */
    bool isBossDemoLand();

    /* 0x80052500 @unofficial */
    bool isHitGroundKinopioWalk(int dir, float f, int i2);

    /* 0x80052650 */
    bool isHitWallKinopioWalk(int);

    /* 0x800526C0 */
    bool checkKinopioWaitBG(int);

    /* 0x80056370 */
    void UNDEF_80056370(dActor_c*, int);

    /* 0x80056980 */
    void setStatus5D(float f); ///< @unofficial

    /* 0x80056C70 */
    void onStatus(int flag);

    /* 0x80056CB0 */
    void offStatus(int flag);

    /* 0x80056CF0 */
    [[nodiscard]]
    bool isStatus(int flag);

    inline void onStatus(
        Status_e flag
    ) {
        onStatus(static_cast<int>(flag));
    }

    inline void offStatus(
        Status_e flag
    ) {
        offStatus(static_cast<int>(flag));
    }

    [[nodiscard]]
    inline bool isStatus(
        Status_e flag
    ) {
        return isStatus(static_cast<int>(flag));
    }

    /* 0x80056E30 */
    dPyMdlBase_c* getModel();

    /* 0x80057E70 */
    void playSound(SndID::Type, long);

    /* 0x800583A0 */
    void calcHeadAttentionAngle();

    /* 0x80056BD0 */
    bool isMameAction();

    /* 0x80057650 */
    const sSpeedData* getSpeedData();

    void addDeathMessage(dActor_c* source, DamageType_e type, bool death);

public:
    // Inline Instance Methods
    // ^^^^^^

    // [Needed to place getOldStateID in the correct location]
    const sStateIDIf_c& getOldState() { return *m_StateMgr.getOldStateID(); }

    bool isState(
        const sStateIDIf_c& id
    ) {
        return m_StateMgr.getStateID()->isEqual(id);
    }

    bool isDemoState(
        const sStateIDIf_c& id
    ) {
        return m_DemoStateMgr.getStateID()->isEqual(id);
    }

    void changeState(
        const sStateIDIf_c& stateID, int arg
    ) {
        changeState(stateID, reinterpret_cast<void*>(arg));
    }

    u32 isNowBgCross(
        BgCross1_e m
    ) {
        return mNowBgCross1 & m;
    }

    u32 isNowBgCross(
        BgCross2_e m
    ) {
        return mNowBgCross2 & m;
    }

    void onNowBgCross(
        BgCross1_e m
    ) {
        mNowBgCross1 |= m;
    }

    void onNowBgCross(
        BgCross2_e m
    ) {
        mNowBgCross2 |= m;
    }

    void offNowBgCross(
        BgCross1_e m
    ) {
        mNowBgCross1 &= ~m;
    }

    void offNowBgCross(
        BgCross2_e m
    ) {
        mNowBgCross2 &= ~m;
    }

    void clearNowBgCross() { mNowBgCross1 = mNowBgCross2 = 0; }

    u32 isOldBgCross(
        BgCross1_e m
    ) {
        return mOldBgCross1 & m;
    }

    u32 isOldBgCross(
        BgCross2_e m
    ) {
        return mOldBgCross2 & m;
    }

    void onOldBgCross(
        BgCross1_e m
    ) {
        mOldBgCross1 |= m;
    }

    void onOldBgCross(
        BgCross2_e m
    ) {
        mOldBgCross2 |= m;
    }

    void offOldBgCross(
        BgCross1_e m
    ) {
        mOldBgCross1 &= ~m;
    }

    void offOldBgCross(
        BgCross2_e m
    ) {
        mOldBgCross2 &= ~m;
    }

    void clearOldBgCross() { mOldBgCross1 = mOldBgCross2 = 0; }

    bool isOnSinkSand() { return isNowBgCross(BGC_ON_SINK_SAND) | isNowBgCross(BGC_IN_SINK_SAND); }

    bool wasOnSinkSand() { return isOldBgCross(BGC_ON_SINK_SAND) | isOldBgCross(BGC_IN_SINK_SAND); }

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0392, 0x03F4);

    /* 0x03F4 */ ControlDemoSubstate_e mDemoState;
    /* 0x03F8 */ int                   mGotoDest;
    /* 0x03FC */ mVec3_c               mGotoPos;

    FILL(0x0408, 0x043C);

    /* 0x043C */ int m0x43C;

    FILL(0x0440, 0x0450);

    /* 0x0450 */ mVec3_c mControlDemoTargetPos;
    /* 0x045C */ float   mControlDemoSpeedF;
    /* 0x0460 */ int     mItemKinopioDirection;
    /* 0x0464 */ int     mItemKinopioTurnTimer;

    /* 0x0468 */ int     mBossDemoLandTimer;
    /* 0x046C */ int     mEndingDanceKeyTimers[5];
    /* 0x0480 */ int     mEndingDanceInactivityTimer;

    FILL(0x0484, 0x0DE8);

    /* 0x0DE8 */ dPyMdlMng_c* mpModelMng;

    FILL(0x0DEC, 0x0EA4);

    /* 0x0EA4 */ dAcPyKey_c mKey;

    /* 0x1008 */ fBaseID_e  mRideActorID;
    /* 0x100C */ fBaseID_e  mActionActorID; // Actor that is eating the player, or the door actor.
    /* 0x1010 */ fBaseID_e  mHipAttackPlayerID;

    /* 0x1014 */ u32        mStatusFlags[7];
    /* 0x1030 */ float      mModelHeight;
    /* 0x1034 */ u8         mPrevDirection;
    /* 0x1035 */ u8         mAmiLayer;
    /* 0x1036 */ u8         mPlayerLayer;

    /* 0x1038 */ mVec3_c    mLastPosDelta;
    /* 0x1044 */ mVec3_c    mLiftRelatedPos;
    /* 0x1050 */ float      mPrevSpeedF;
    /* 0x1054 */ float      mPrevSpeedY;

    /**
     * Stores the highest Y position reached, resets when landing on the ground again.
     */
    /* 0x1058 */ float mTopHeight;

    /**
     * The highest Y position since being on the ground last. Not reset when landing on the ground.
     */
    /* 0x105C */ float             mAirTopHeight;

    /* 0x1060 */ const sSpeedData* mSpeedDataNormal;
    /* 0x1064 */ const sSpeedData* mSpeedDataStar;
    /* 0x1068 */ const float*      mGravityData;

    /* 0x106C */ int               m_noGravityTime;
    /* 0x1070 */ int               m_starTime;
    /* 0x1074 */ int               m_noDamageTime;
    /* 0x1078 */ int               m_modeChangeNoDamageTime;
    /* 0x107C */ int               m_timer0x1078;

    /* 0x1080 */ s8                m_treadCount;
    /* 0x1081 */ s8                m_starCount;
    /* 0x1082 */ s8                m_plComboCount;

    /* 0x1084 */ u32               m0x1084;
    /* 0x1088 */ u32               mFollowMameKuribo;

    /* 0x108C */ fBaseID_e         mIceActorID;

    /* 0x1090 */ PLAYER_MODE_e     mPlayerMode;

    /* 0x1094 */ sBcPointData      mHeadBcData;
    /* 0x10A4 */ sBcPointData      mFootBcData;
    /* 0x10B4 */ sBcPointData      mWallBcData;
    /* 0x10C4 */ mVec3_c           mBgPushForce;
    /* 0x10D0 */ float             mExtraPushForceX;

    /* 0x10D4 */ u32               mNowBgCross1;
    /* 0x10D8 */ u32               mNowBgCross2;
    /* 0x10DC */ u32               mOldBgCross1;
    /* 0x10E0 */ u32               mOldBgCross2;
    /* 0x10E4 */ u32               mBgFootHistory[10];

    FILL(0x110C, 0x1164);

    /* 0x1164 */ dCc_c mCc1;
    /* 0x1208 */ dCc_c mAttCc1;
    /* 0x12AC */ dCc_c mAttCc2;
    /* 0x1350 */ dCc_c mAttCc3;

    FILL(0x13F4, 0x1418);

    /**
     * The state manager for demo (cutscene) states.
     */
    /* 0x1418 */ sStateMgrDefault_c<daPlBase_c> m_DemoStateMgr;
    /**
     * To be used as an argument to the new demo state.
     */
    /* 0x1454 */ int m_DemoStateArg;
    /**
     * Demo states can use this as a sub-state variable (cast to some enum).
     */
    /* 0x1458 */ int m_DemoSubstate;
    /**
     * Demo states can use this generic timer for various purposes.
     * It is automatically decrememented in executeState() every frame.
     */
    /* 0x145C */ int m_DemoSubstateTimer;
    /**
     * Whether the player is currently in a demo (cutscene) state.
     */
    /* 0x1460 */ bool m_isDemoMode;

    /**
     * The state manager to use for regular layer states.
     */
    /* 0x1464 */ sStateMgrDefault_c<daPlBase_c> m_StateMgr;
    /**
     * To be used as an argument to the new state.
     */
    /* 0x14A0 */ void* m_StateArg;
    /**
     * States can use this as a sub-state variable (cast to some enum).
     */
    /* 0x14A4 */ int m_Substate;
    /**
     * States can use this generic timer for various purposes.
     * It is automatically decrememented in executeState() every frame.
     */
    /* 0x14A8 */ int m_SubstateTimer;
    /**
     * States can use this field for various purposes - as a timer, boolean flag, etc.
     */
    /* 0x14AC */ int m_SubstateValue;

    FILL(0x14B0, 0x14D4);
};
