target_include_directories(project PRIVATE .)

#
# WIIMJ2D.dol
# NSMBW          .text:  0x800FFF80 - 0x801000F0
#
target_sources(project PRIVATE
# NSMBW          .text:  0x800FFF80 - 0x801000F0
    d_stage_field.cpp
)
