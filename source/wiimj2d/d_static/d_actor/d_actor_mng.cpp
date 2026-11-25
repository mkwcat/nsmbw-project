// d_actor_mng.cpp
// NSMBW .text: 0x80066380 - 0x80066FB0

#include "d_actor_mng.h"

#include "d_actor.h"
#include "d_base_actor.h"
#include "d_profile.h"
#include "f_manager.h"
#include <utility>

[[nsmbw_data(0x8042A020)]]
dActorMng_c* dActorMng_c::m_instance;

[[nsmbw(0x80066540)]]
bool dActorMng_c::envAllWaterCheck();

[[nsmbw(0x80066EC0)]]
void dActorMng_c::finalUpdate() {
    for (fBase_c* base = nullptr;
         (base = fManager_c::searchBaseByProfName(dProf::ICE_ACTOR, base)) != nullptr;) {
        auto* actor = static_cast<dBaseActor_c*>(base);
        if (!actor->mDeleteRequested) {
            actor->finalUpdate();
        }
    }

    for (fBase_c* base = nullptr; (base = fManager_c::searchBaseByGroupType(
                                       std::to_underlying(fBase_c::GROUP_TYPE_e::ACTOR), base
                                   )) != nullptr;) {
        auto* actor = static_cast<dBaseActor_c*>(base);

        // Add call to finalUpdateCarry
        if (!actor->mDeleteRequested && dActorEx_c::get(base) != nullptr) {
            static_cast<dActor_c*>(base)->finalUpdateCarry();
        }

        if (actor->mProfName != dProf::ICE_ACTOR && !actor->mDeleteRequested) {
            actor->finalUpdate();
        }
    }
}

[[nsmbw(0x80066F70)]]
void dActorMng_c::execute();
