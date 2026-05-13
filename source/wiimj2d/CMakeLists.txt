add_subdirectory(d_system)
add_subdirectory(d_error)
add_subdirectory(d_stage)
add_subdirectory(d_profile)
add_subdirectory(d_bases)
add_subdirectory(d_player)
add_subdirectory(d_enemies)
add_subdirectory(d_en_boss)
add_subdirectory(state)

# Add for current directory

# WIIMJ2D.dol
# NSMBW          .text:  0x8015FF80 - 0x80160C10
target_sources(project PRIVATE
# NSMBW          .text:  0x8015FF80 - 0x8015FF90
    Counter.cpp
# NSMBW          .text:  0x8015FF90 - 0x80160C10
    DynamicLink.cpp
)

add_subdirectory(component)
add_subdirectory(framework)
add_subdirectory(machine)
add_subdirectory(sound)

# Added directories

add_subdirectory(d_project)
