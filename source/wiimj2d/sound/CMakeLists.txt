target_include_directories(project PRIVATE .)

#
# WIIMJ2D.dol
# NSMBW          .text:  0x80194A10 - 0x8019F1F0
#
target_sources(project PRIVATE
# NSMBW          .text:  0x80194A10 - 0x80197440
    SndAudioMgr.cpp
# NSMBW:         .text:  0x80197440 - 0x80197790
    SndObjectBase.cpp
# NSMBW          .text:  0x80197790 - 0x80198CF0
    SndObjectEnemy.cpp
# NSMBW          .text:  0x80198CF0 - 0x80199A20
    SndObjectMap.cpp

# NSMBW          .text:  0x8019A0F0 - 0x8019B240
    SndObjectPlayer.cpp

# NSMBW          .text:  0x8019B500 - 0x8019DE90
    SndSceneMgr.cpp
)
