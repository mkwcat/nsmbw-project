
#
# WIIMJ2D.dol
# NSMBW          TODO
# PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src
#
target_sources(project PRIVATE
# NSMBW          .text:  0x802DD76C - 0x802DDC80
    alloc.c

# NSMBW          .data:  0x80350D58 - 0x80350E98
    ansi_files.c

# NSMBW          .text:  0x802DE824 - 0x802DE904
    buffer_io.c

# NSMBW          .text:  0x802DEC0C - 0x802DEDFC
    file_io.c

# NSMBW          .text:  0x802DF06C - 0x802DF264
    mbstring.c
# NSMBW          .text:  0x802DF264 - 0x802DF3D4
    mem.c

# NSMBW          .text:  0x802DF798 - 0x802DF7A8
    misc_io.c
# NSMBW          .text:  0x802DF7A8 - 0x802E1BA0
    printf.c
# NSMBW          .text:  0x802E1BA0 - 0x802E1C28
    scanf.c
# NSMBW          .text:  0x802E1C28 - 0x802E4FC8
    string.c
# NSMBW          .text:  0x802E1FE4 - 0x802E24BC
    strtoul.c

# NSMBW          .text:  0x802E47E8 - 0x802E4860
    wchar_io.c
)
