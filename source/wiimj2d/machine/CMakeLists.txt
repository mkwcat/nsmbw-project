#
# WIIMJ2D.dol
# NSMBW          .text:  0x801632B0 - 0x80171500
#
target_sources(project PRIVATE
# NSMBW          .text:  0x801632B0 - 0x80164630
    m_2d.cpp
# NSMBW          .text:  0x80164630 - 0x80165210
    m_3d.cpp
# NSMBW          .text:  0x80165210 - 0x80165660
    m_3d_anmchr.cpp
# NSMBW          .text:  0x80165660 - 0x80165960
    m_3d_anmchrblend.cpp
# NSMBW          .text:  0x80165960 - 0x80166560
    m_3d_anmmatclr.cpp
# NSMBW          .text:  0x80166560 - 0x80167140
    m_3d_anmtexpat.cpp
# NSMBW          .text:  0x80167140 - 0x80167D80
    m_3d_anmtexsrt.cpp
# NSMBW          .text:  0x80167D80 - 0x80168000
    m_3d_anmvis.cpp
# NSMBW          .text:  0x80168000 - 0x80168240
    m_3d_banm.cpp
# NSMBW          .text:  0x80168240 - 0x80168C80
    m_3d_bmdl.cpp
# NSMBW          .text:  0x80168C80 - 0x80168E50
    m_3d_calcratio.cpp
# NSMBW          .text:  0x80168E50 - 0x80169360
    m_3d_fanm.cpp
# NSMBW          .text:  0x80169360 - 0x801696A0
    # <UNKNOWN>
# NSMBW          .text:  0x801696A0 - 0x8016A150
    m_3d_mdl.cpp
# NSMBW          .text:  0x8016A150 - 0x8016A430
    m_3d_scnleaf.cpp
# NSMBW          .text:  0x8016A430 - 0x8016A5A0
    m_3d_smdl.cpp

# nsmbw-project
    m_archive.cpp

# NSMBW          .text:  0x8016B090 - 0x8016C540
    m_dvd.cpp

# NSMBW          .text:  0x8016DBE0 - 0x8016DD40
# NSMBW          .sbss:  0x8042A720 - 0x8042A728
    m_fader.cpp

# NSMBW  .bss: 0x80377F48 - 0x80377F58
    m_heap.cpp

# NSMBW          .text:  0x8016F330 - 0x8016F880
    m_pad.cpp

# NSMBW          .text:  0x80170AC0 - 0x80170D90
# NSMBW          .bss:   0x803780C8 - 0x803780F8
    m_vec.cpp
)