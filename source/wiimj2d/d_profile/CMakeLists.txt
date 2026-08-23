target_include_directories(project PRIVATE .)

#
# WIIMJ2D.dol
# NSMBW          .text:  0x801018C0 - 0x801018E0
# Moved from d_bases
#
target_sources(project PRIVATE
# NSMBW          .text:  0x801018C0 - 0x801018E0
    d_profile_static.cpp
)

#
# d_profile.rel
#
target_sources(project PRIVATE
# NSMBW d_profile.rodata: 0x8076A748 - 0x8076B300
    d_profile_table.cpp
)
