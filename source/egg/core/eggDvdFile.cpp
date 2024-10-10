// eggDvdFile.cpp
// NSMBW: 0x802B7C00 - 0x802B8010

#include "eggDvdFile.h"

namespace EGG
{

EXTERN_DATA(
  0x8042B0E0, //
  bool DvdFile::sIsInitialized
);

EXTERN_DATA(
  0x80423B70, //
  nw4r::ut::List DvdFile::sDvdList
);

EXTERN_TEXT(
  0x802B7C00, //
  void DvdFile::initialize()
);

EXTERN_TEXT_CONSTRUCTOR(
  0x802B7C40, //
  DvdFile::DvdFile()
);

EXTERN_TEXT_CONSTRUCTOR(
  0x802B7C90, //
  DvdFile::~DvdFile()
);

EXTERN_TEXT(
  0x802B7D00, //
  void initiate()
);

EXTERN_TEXT(
  0x802B7D70, //
  bool DvdFile::open(s32 entryNum)
);

EXTERN_TEXT(
  0x802B7DF0, //
  bool DvdFile::open(const char* path)
);

EXTERN_TEXT(
  0x802B7E40, //
  bool DvdFile::open(const char* path, void* param_2)
);

EXTERN_TEXT(
  0x802B7E50, //
  void DvdFile::close()
);

EXTERN_TEXT(
  0x802B7EB0, //
  s32 DvdFile::readData(void* data, s32 len, s32 offset)
);

EXTERN_TEXT(
  0x802B7F80, //
  s32 DvdFile::writeData(const void* data, s32 len, s32 offset)
);

EXTERN_TEXT(
  0x802B7F90, //
  s32 sync()
);

EXTERN_TEXT(
  0x802B7FF0, //
  void doneProcess(s32 result, DVDFileInfo* fileInfo)
);

} // namespace EGG
