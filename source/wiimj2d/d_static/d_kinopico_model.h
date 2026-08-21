#pragma once

#include "d_player_model.h"

class dKinopicoMdl_c final : public dPlayerMdl_c
{
public:
    dKinopicoMdl_c(u8 index);

    ~dKinopicoMdl_c() override;

protected:
    m3d::anmTexPat_c* getBodyTexAnm();

    void createAnim(m3d::anmTexPat_c& anm, const char* name, u8 modelIdx);

public:
    // void setTexAnmType(TexAnmType_e) override;

    void setColorType(u8 modelIndex) override;

    bool prepareBodyAnm(ChrAnmType_e type, nw4r::g3d::ResAnmChr* anm, bool noUpdate) override;

    float VT_0xB4() override;

    void createPlayerModel() override;

public:
    // Instance Variables
    // ^^^^^^

    m3d::anmTexPat_c mPropelBodySwitchAnim;
    m3d::anmTexPat_c mPenguinBodySwitchAnim;
};
