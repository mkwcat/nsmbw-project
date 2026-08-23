target_include_directories(project PRIVATE .)

#
# WIIMJ2D.dol
# NSMBW          .text:  0x8015F270 - 0x8015FF80
#
target_sources(project PRIVATE
# NSMBW          .text:  0x8015F270 - 0x8015F280
    s_Crc.cpp
# NSMBW          .text:  0x8015F280 - 0x8015F740
    s_Lib.cpp
# NSMBW          .text:  0x8015F740 - 0x8015F810
    s_Phase.cpp
# NSMBW          .text:  0x8015F810 - 0x8015F900
    s_Printf.cpp
# NSMBW          .text:  0x8015F900 - 0x8015FAE0
    s_StateID.cpp
# NSMBW          .text:  0x8015FAE0 - 0x8015FDD0
    s_StateMethod.cpp
# NSMBW          .text:  0x8015FDD0 - 0x8015FF80
    s_StateMethodUsr_FI.cpp
)
