#
# WIIMJ2D.dol
# NSMBW          .text:  0x80106F00 - 0x80109020
#
target_sources(project PRIVATE
# NSMBW          .text:  0x80106F00 - 0x80106FF0
  # d_RomFontMgr.cpp
# NSMBW          .text:  0x80106FF0 - 0x801073C0
  # d_TextWriter.cpp
# NSMBW          .text:  0x801073C0 - 0x801073F0
  # d_TextWriterBase.cpp
# NSMBW          .text:  0x801073F0 - 0x801079A0
  # d_dvd_error.cpp
# NSMBW          .text:  0x801079A0 - 0x80107FD0
  # d_dvd_error_wide_msg.cpp
# NSMBW          .text:  0x80107FD0 - 0x80109020
    d_reset.cpp
)
