
#
# WIIMJ2D.dol
# NSMBW          .text:  0x80160C10 - 0x80161A60
#
target_sources(project PRIVATE
# nsmbw-project
    c_json.cpp
# NSMBW          .text:  0x80160C10 - 0x80161050
    c_lib.cpp
# NSMBW          .text:  0x80161050 - 0x801611A0
    c_list.cpp
# NSMBW          .text:  0x801611A0 - 0x801615A0
    c_math.cpp
# NSMBW          .text:  0x801615A0 - 0x80161670
    c_random.cpp
# NSMBW          .text:  0x80161670 - 0x80161880
    c_tree.cpp
# NSMBW          .text:  0x80161880 - 0x80161A60
    c_unary_tree.cpp
)