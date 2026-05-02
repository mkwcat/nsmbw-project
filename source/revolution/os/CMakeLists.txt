#
# WIIMJ2D.dol
# NSMBW          .text:  0x801A9E80 - 0x801B8B70
#
target_sources(project PRIVATE
# NSMBW          .text:  0x801AC560 - 0x801ACC10
    OSCache.c

# NSMBW          .text:  0x801AD620 - 0x801ADCE0
    OSError.c

# NSMBW          .text:  0x801AF2C0 - 0x801AFEF0
    OSFatal.c

# NSMBW          .text:  0x801B1280 - 0x801B1A50
    OSInterrupt.c
# NSMBW          .text:  0x801B1A50 - 0x801B24D0
    OSLink.c

# NSMBW          .text:  0x801B2F60 - 0x801B3380
    OSMutex.c

# NSMBW          .text:  0x801B3E20 - 0x801B48D0
    OSRtc.c

# NSMBW          .text:  0x801B4950 - 0x801B60C0
    OSThread.c
# NSMBW          .text:  0x801B60C0 - 0x801B64F0
    OSTime.c
)
