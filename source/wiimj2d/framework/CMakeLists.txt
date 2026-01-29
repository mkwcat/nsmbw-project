#
# WIIMJ2D.dol
# NSMBW          .text:  0x80161A60 - 0x801632B0
#
target_sources(project PRIVATE
# NSMBW          .text:  0x80161880 - 0x80161A60
    f_ba_helper.cpp
# NSMBW          .text:  0x80161A60 - 0x80162C80
    f_base.cpp
# NSMBW          .text:  0x80162C80 - 0x80162E30
    f_list.cpp
# NSMBW          .text:  0x80162E30 - 0x80163140
    f_manager.cpp
# NSMBW          .sbss:  0x8042A698 - 0x8042A6A0
    f_profile.cpp
# NSMBW          .text:  0x80163140 - 0x801632B0
    f_tree.cpp
)