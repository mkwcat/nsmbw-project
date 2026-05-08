target_sources(project PRIVATE
    d_a_bg_carry.cpp
    d_a_en_sample_enemy.cpp
    d_a_sample_actor.cpp
    d_base_dump.cpp
    d_nextgoto_list.cpp
)

set_property(SOURCE d_base_dump.cpp
    TARGET_DIRECTORY project
    PROPERTY COMPILE_OPTIONS "-fconstexpr-steps=4000000")
