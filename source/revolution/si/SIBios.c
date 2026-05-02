// SIBios.c
// NSMBW .text: 0x801BA940 - 0x801BB980

#include <revolution/os/OSError.h>
#include <revolution/os/OSInterrupt.h>
#include <revolution/si.h>

EXTERN_C_START

[[nsmbw_data(0xCD006400)]]
/* static */ volatile u32 __SIRegs[0x100];

[[nsmbw_data(0x803402D0)]]
/* static */ SIControl Si{};

[[nsmbw_data(0x803402E8)]]
/* static */ u32 Type[4];

[[nsmbw_data(0x8038FAD0)]]
/* static */ SIPacket Packet[4]{};

[[nsmbw_data(0x8038FC50)]]
/* static */ u32 InputBuffer[4][2];

[[nsmbw_data(0x8038FC70)]]
/* static */ BOOL InputBufferValid[4];

[[nsmbw_data(0x8038FC80)]]
/* static */ volatile u32 InputBufferVcount[4];

[[nsmbw_data(0x8038FCB0)]]
/* static */ SITypeCallback TypeCallback[4][4];

[[nsmbw_data(0x8042AA8C)]]
u32 __PADFixBits;

BOOL SIBusy(
    void
) {
    return (Si.chan != -1) ? TRUE : FALSE;
}

BOOL SIIsChanBusy(
    s32 chan
) {
    return Packet[chan].chan != -1 || Si.chan == chan;
}

u32 SIGetStatus(
    s32 chan
) {
    BOOL enabled;
    u32 sr;
    int chanShift;

    enabled   = OSDisableInterrupts();
    sr        = __SIRegs[SI_STATUS_IDX];
    chanShift = (3 - chan) * 8;
    sr >>= chanShift;

    if ((sr & 8) != 0) {
        if ((Type[chan] & SI_ERROR_BUSY) == 0) {
            Type[chan] = 8;
        }
    }

    OSRestoreInterrupts(enabled);
    return sr;
}

[[nsmbw(0x801BB7C0)]]
u32 SIGetType(s32 chan);

void SISetCommand(
    s32 chan, u32 command
) {
    ASSERTMSG((chan >= 0) && (chan < 4), "SISetCommand(): invalid channel.");
    __SIRegs[chan * 3] = command;
}

void SITransferCommands(
    void
) {
    __SIRegs[SI_STATUS_IDX] = SI_COMCSR_TCINT_MASK;
}

[[nsmbw(0x801BB390)]]
BOOL SITransfer(
    s32 chan, void* output, u32 outputBytes, void* input, u32 inputBytes, SICallback callback,
    OSTime delay
);

u32 SIEnablePolling(
    u32 poll
) {
    BOOL enabled;
    u32 en;

    ASSERTMSG((poll & 0x0FFFFFFF) == 0, "SIEnablePolling(): invalid chan bit(s).");
    if (poll == 0) {
        return Si.poll;
    }

    enabled = OSDisableInterrupts();
    poll    = poll >> 24;
    en      = poll & 0xF0;
    ASSERT(en);
    poll &= ((en >> 4) | 0x03FFFFF0);
    poll &= 0xFC0000FF;

    Si.poll &= ~(en >> 4);
    Si.poll |= poll;
    poll = Si.poll;
    SITransferCommands();
    __SIRegs[0x30 / 4] = poll;
    OSRestoreInterrupts(enabled);
    return poll;
}

u32 SIDisablePolling(
    u32 poll
) {
    BOOL enabled;

    ASSERTMSG((poll & 0x0FFFFFFF) == 0, "SIDisablePolling(): invalid chan bit(s).");
    if (poll == 0) {
        return Si.poll;
    }

    enabled = OSDisableInterrupts();
    poll    = poll >> 24;
    poll &= 0xF0;
    ASSERT(poll);
    poll               = Si.poll & ~poll;
    __SIRegs[0x30 / 4] = poll;
    Si.poll            = poll;
    OSRestoreInterrupts(enabled);
    return poll;
}

static BOOL SIGetResponseRaw(
    s32 chan
) {
    u32 sr;

    sr = SIGetStatus(chan);
    if (sr & 0x20) {
        InputBuffer[chan][0]   = __SIRegs[1 + chan * 3];
        InputBuffer[chan][1]   = __SIRegs[2 + chan * 3];
        InputBufferValid[chan] = TRUE;
        return TRUE;
    }

    return FALSE;
}

BOOL SIGetResponse(
    s32 chan, void* data
) {
    BOOL rc;
    BOOL enabled;

    ASSERTMSG(((chan >= 0) && (chan < 4)), "SIGetResponse(): invalid channel.");
    enabled = OSDisableInterrupts();
    SIGetResponseRaw(chan);
    rc                     = InputBufferValid[chan];
    InputBufferValid[chan] = FALSE;

    if (rc) {
        reinterpret_cast<u32*>(data)[0] = InputBuffer[chan][0];
        reinterpret_cast<u32*>(data)[1] = InputBuffer[chan][1];
    }

    OSRestoreInterrupts(enabled);
    return rc;
}

u32 SIGetTypeAsync(
    s32 chan, SITypeCallback callback
) {
    BOOL enabled;
    u32 type;

    enabled = OSDisableInterrupts();
    type    = SIGetType(chan);

    if ((Type[chan] & SI_ERROR_BUSY) != 0) {
        int i;
        for (i = 0; i < SI_MAX_TYPE; i++) {
            if (TypeCallback[chan][i] == callback) {
                break;
            }

            if (TypeCallback[chan][i] == 0) {
                TypeCallback[chan][i] = callback;
                break;
            }
        }

        ASSERT(i < SI_MAX_TYPE);
    } else {
        (*callback)(chan, type);
    }

    OSRestoreInterrupts(enabled);
    return type;
}

EXTERN_C_END
