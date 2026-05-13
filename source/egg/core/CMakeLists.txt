#
# WIIMJ2D.dol
# NSMBW          TODO
#
target_sources(project PRIVATE
# NSMBW          .text:  0x802B7C00 - 0x802B8010
    eggDvdFile.cpp
# NSMBW          .text:  0x802B8010 - 0x802B8560
    eggDvdRipper.cpp
# NSMBW          .text:  0x802B8560 - 0x802B8BB0
    eggStreamDecomp.cpp

# NSMBW          .text:  0x802B8C80 - 0x802B93E0
    eggHeap.cpp
# NSMBW          .text:  0x802B93E0 - 0x802B98C0
    eggExpHeap.cpp

# NSMBW          .text:  0x802BA410 - 0x802BA4F0
    eggDisposer.cpp

# NSMBW          .text:  0x802BC9D0 - 0x802BE710
    eggController.cpp
)
