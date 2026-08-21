#pragma once

#pragma once

class dCc_c;

class daEnJimenPakkunBase_c
{
public:
    /* 0x8002F870 */
    void Normal_VsPlHitCheck(dCc_c* main, dCc_c* other);

    /* 0x8002F970 */
    int hitCallback_YoshiHipAttk(dCc_c* main, dCc_c* other);
};