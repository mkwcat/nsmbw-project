#include <System.h>

#undef nsmbw
#define nsmbw(...) maybe_unused

#undef nsmbw_data
#define nsmbw_data(...) maybe_unused

#undef EXTERN_SYMBOL
#define EXTERN_SYMBOL(...)

#undef EXTERN_REPL
#define EXTERN_REPL(...)

#include <cstdio>
#include <cstring>
#include <egg/core/eggDvdFile.h>
#include <egg/core/eggDvdRipper.h>
#include <egg/core/eggHeap.h>
#include <egg/core/eggStreamDecomp.h>
#include <machine/m_dvd.h>
#include <mkwcat/AddressMapper.hpp>
#include <revolution/arc.h>
#include <revolution/dvd.h>
#include <revolution/os.h>
#include <utility>

// Since the same Loader.bin file will be used for every region, ported addresses need to be
// realized on the fly.

// Regions in the order P1, P2, E1, E2, J1, J2, K, W, C

#define PORT_CALL_BASE 0x800047E4

#define PORT_ADDR_LIST(_ADDR)                                                                      \
    (const u32[])                                                                                  \
    {                                                                                              \
        _ADDR, mkwcat::AddressMapperP2.MapAddress(_ADDR),                                          \
          mkwcat::AddressMapperE1.MapAddress(_ADDR), mkwcat::AddressMapperE2.MapAddress(_ADDR),    \
          mkwcat::AddressMapperJ1.MapAddress(_ADDR), mkwcat::AddressMapperJ2.MapAddress(_ADDR),    \
          mkwcat::AddressMapperK.MapAddress(_ADDR), mkwcat::AddressMapperW.MapAddress(_ADDR),      \
          mkwcat::AddressMapperC.MapAddress(_ADDR),                                                \
    }

#define _ADDRESS_LOADER3(_ADDR, _COUNTER, _PORT_CALL_BASE)                                         \
__gnu__::__naked__]]  void _LoaderFunction##_COUNTER() asm("_LoaderFunction" #_COUNTER);           \
    [[__gnu__::__naked__]] void _LoaderFunction##_COUNTER()                                        \
    {                                                                                              \
        __asm__("li 12, ((. + 8) - " #_PORT_CALL_BASE ")@l;"                                       \
                "b PortCall;"                                                                      \
                ".long %0;"                                                                        \
                ".long %1;"                                                                        \
                ".long %2;"                                                                        \
                ".long %3;"                                                                        \
                ".long %4;"                                                                        \
                ".long %5;"                                                                        \
                ".long %6;"                                                                        \
                ".long %7;"                                                                        \
                ".long %8;"                                                                        \
                :                                                                                  \
                : "i"(_ADDR), "i"(mkwcat::AddressMapperP2.MapAddress(_ADDR)),                      \
                  "i"(mkwcat::AddressMapperE1.MapAddress(_ADDR)),                                  \
                  "i"(mkwcat::AddressMapperE2.MapAddress(_ADDR)),                                  \
                  "i"(mkwcat::AddressMapperJ1.MapAddress(_ADDR)),                                  \
                  "i"(mkwcat::AddressMapperJ2.MapAddress(_ADDR)),                                  \
                  "i"(mkwcat::AddressMapperK.MapAddress(_ADDR)),                                   \
                  "i"(mkwcat::AddressMapperW.MapAddress(_ADDR)),                                   \
                  "i"(mkwcat::AddressMapperC.MapAddress(_ADDR)));                                  \
    }                                                                                              \
[[__gnu__::__alias__("_LoaderFunction" #_COUNTER)

#define _ADDRESS_LOADER2(_ADDR, _COUNTER, _PORT_CALL_BASE)                                         \
    _ADDRESS_LOADER3(_ADDR, _COUNTER, _PORT_CALL_BASE)
#define _ADDRESS_LOADER(_ADDR, _COUNTER, _PORT_CALL_BASE)                                          \
    _ADDRESS_LOADER2(_ADDR, _COUNTER, _PORT_CALL_BASE)
#define address_loader(_ADDR) _ADDRESS_LOADER(_ADDR, __COUNTER__, PORT_CALL_BASE)

EXTERN_C_START

constinit u32 g_port_offset = 0;

void PortCall() ASM_METHOD(
  // clang-format off
  lis     r11, g_port_offset@ha;
  lwz     r11, g_port_offset@l(r11);
  lwzx    r12, r11, r12;
  mtctr   r12;
  bctr;
  // clang-format on
);

EXTERN_C_END

[[address_loader(0x8019F7A0)]]
bool ARCInitHandle(void* arcStart, ARCHandle* handle);

[[address_loader(0x8019F840)]]
bool ARCOpen(ARCHandle* handle, const char* fileName, ARCFileInfo* af);

[[address_loader(0x8019FAF0)]]
bool ARCFastOpen(ARCHandle* handle, s32 entrynum, ARCFileInfo* af);

[[address_loader(0x8019FB40)]]
s32 ARCConvertPathToEntrynum(ARCHandle* handle, const char* pathPtr);

[[address_loader(0x8019FF90)]]
void* ARCGetStartAddrInMem(ARCFileInfo* af);

[[address_loader(0x8019FFB0)]]
u32 ARCGetStartOffset(ARCFileInfo* af);

[[address_loader(0x8019FFC0)]]
u32 ARCGetLength(ARCFileInfo* af);

[[address_loader(0x8019FFD0)]]
bool ARCClose(ARCFileInfo* af);

[[address_loader(0x801AF710)]]
void OSFatal(GXColor textColor, GXColor bgColor, const char* text);

[[address_loader(0x801B2060)]]
bool OSLink(OSModuleInfo* info, void* bss);

[[address_loader(0x801B2070)]]
bool OSLinkFixed(OSModuleInfo* info, void* bss);

[[address_loader(0x801CA7C0)]]
s32 DVDConvertPathToEntrynum(const char* fileName);

// Actually a constructor but we can't define it due to a compiler bug.
[[address_loader(0x802B7C40)]]
EGG::DvdFile* MakeDvdFile(void* data);

[[address_loader(0x802B8AB0)]]
bool EGG::StreamDecompSZS::init(void* dst, u32 maxCompressedSize);

[[address_loader(0x802B8AE0)]]
bool EGG::StreamDecompSZS::decomp(const void* src, u32 size);

[[address_loader(0x802B8B10)]]
u32 EGG::StreamDecompSZS::getUncompressedSize(const void* src);

[[address_loader(0x802B8B20)]]
u32 EGG::StreamDecompSZS::getHeaderSize();

// Takes a thisptr but it's not checked
[[address_loader(0x8016C4F0)]]
EGG::StreamDecompSZS* mDvd_TUncompressInfo_c_SZS_Construct();

[[address_loader(0x802B8290)]]
u8* EGG::DvdRipper::loadToMainRAMDecomp(
  DvdFile* file, StreamDecomp* streamDecomp, u8* dst, Heap* heap, EAllocDirection allocDirection,
  s32 offset, u32 size, u32 maxChunkSize, u32* amountRead, u32* fileSize
);

[[address_loader(0x801B5270)]]
BOOL OSCreateThread(
  OSThread* thread, OSThreadFunc func, void* funcArg, void* stackBegin, u32 stackSize, s32 prio,
  u16 flags
);

[[address_loader(0x801B59A0)]]
s32 OSResumeThread(OSThread* thread);

[[address_loader(0x801B1280)]]
bool OSDisableInterrupts();

[[address_loader(0x802E19D8)]]
int snprintf(char* __restrict s, size_t n, const char* __restrict format, ...);

namespace
{

constexpr u32 STACK_SIZE = 0x8000;
constexpr u32 MODULE_BLOCK_SIZE = 0x80000;
constexpr u32 REGION_INDEX = sizeof("rels/project_") - 1;
constinit bool l_started = false;
constinit char l_module_path[] = "rels/project_?1.rel.szs";
constinit const char l_archive_path[] = "mkwcat.arc";
constinit void* l_stack = nullptr;
constinit OSThread l_thread = {};
constinit ARCHandle l_arc_handle = {};
constinit s32 l_arc_entry_num = -1;
constinit void* l_loader_block = nullptr;

[[gnu::noinline]]
void Error(const char* expr, int line)
{
    char print_msg[0x400];
    std::snprintf(
      print_msg, sizeof(print_msg),
      "mkwcat-nsmbw loader error!\n"
      "code: %s(%d)\n",
      expr, line
    );

    OSFatal(GXColor{255, 255, 255, 255}, GXColor{0, 0, 0, 255}, print_msg);
    std::unreachable();
}

#define LOADER_ASSERT(_EXPR) (((_EXPR) ? (void) 0 : Error(#_EXPR, __LINE__)))

bool GetPortByCode()
{
    u8 c;
    switch (*reinterpret_cast<u8*>(0x8000423A)) {
    default:
        return false;

    case 0xFF:
        // PAL (P)
        l_module_path[REGION_INDEX] = 'P';
        g_port_offset = PORT_CALL_BASE + 0x0;
        c = *reinterpret_cast<u8*>(0x800CF287);
        break;
    case 0xFC:
        // USA (E)
        l_module_path[REGION_INDEX] = 'E';
        g_port_offset = PORT_CALL_BASE + 0x8;
        c = *reinterpret_cast<u8*>(0x800CF197);
        break;
    case 0xF9:
        // JPN (J)
        l_module_path[REGION_INDEX] = 'J';
        g_port_offset = PORT_CALL_BASE + 0x10;
        c = *reinterpret_cast<u8*>(0x800CF117);
        break;

    case 0xC8:
        // KOR (K)
        l_module_path[REGION_INDEX] = 'K';
        g_port_offset = PORT_CALL_BASE + 0x18;
        return true;
    case 0xAC:
        // TWN (W)
        l_module_path[REGION_INDEX] = 'W';
        g_port_offset = PORT_CALL_BASE + 0x1C;
        return true;
    case 0x55:
        // CHN (C)
        l_module_path[REGION_INDEX] = 'C';
        g_port_offset = PORT_CALL_BASE + 0x20;
        return true;
    }

    const bool rev2 = c == 0x38;
    if (rev2) {
        g_port_offset += 0x4;
        l_module_path[REGION_INDEX + 1] = '2';
    }
    return rev2 || c == 0x30;
}

int GetPortIndex()
{
    return (g_port_offset - PORT_CALL_BASE) >> 2;
}

EGG::Heap* GetHeap()
{
    return *reinterpret_cast<EGG::Heap**>(PORT_ADDR_LIST(0x8042A664)[GetPortIndex()]);
}

void* LoaderThread(void* param)
{
    EGG::Heap* const heap = GetHeap();

    alignas(alignof(EGG::DvdFile)) u8 dvd_file_memory[sizeof(EGG::DvdFile)];
    EGG::DvdFile* const dvd_file = MakeDvdFile(reinterpret_cast<EGG::DvdFile*>(dvd_file_memory));

    l_arc_entry_num = DVDConvertPathToEntrynum(l_archive_path);
    const bool arc_exists = l_arc_entry_num != -1;
    LOADER_ASSERT(arc_exists);

    // Open the project archive
    const bool dvd_open_ok = dvd_file->open(l_arc_entry_num);
    LOADER_ASSERT(dvd_open_ok);

    // Read the 32 byte ARC header to get the size of the full header
    ARCHeader arc_small_header alignas(32);
    const bool arc_header_read_ok =
      dvd_file->readData(&arc_small_header, sizeof(ARCHeader), 0) == sizeof(ARCHeader);
    LOADER_ASSERT(arc_header_read_ok);

    const s32 arc_header_size = (arc_small_header.fileStart + 31) & ~31;
    void* const arc_header = heap->alloc(arc_header_size, 32);
    LOADER_ASSERT(arc_header);

    // Read the full header
    const bool arc_full_header_read_ok =
      dvd_file->readData(arc_header, arc_header_size, 0) == arc_header_size;
    LOADER_ASSERT(arc_full_header_read_ok);

    ARCHandle* const arc_handle = &l_arc_handle;
    const bool arc_init_handle_ok = ARCInitHandle(arc_header, arc_handle);
    LOADER_ASSERT(arc_init_handle_ok);

    ARCFileInfo arc_file_info;
    const bool arc_open_ok = ARCOpen(arc_handle, l_module_path, &arc_file_info);
    LOADER_ASSERT(arc_open_ok);

    // Should be fine? This is not threadsafe but nothing else should be reading files at this
    // point, at least not compressed ones. Note: destructor does nothing so we don't even call it
    // here.
    EGG::StreamDecompSZS* const szs_stream = mDvd_TUncompressInfo_c_SZS_Construct();

    u32 amount_read, file_size;
    const bool module_load_ok = EGG::DvdRipper::loadToMainRAMDecomp(
      dvd_file, szs_stream, static_cast<u8*>(l_loader_block), heap, EGG::DvdRipper::ALLOC_DIR_TOP,
      ARCGetStartOffset(&arc_file_info), ARCGetLength(&arc_file_info), 0x10000, &amount_read,
      &file_size
    );
    LOADER_ASSERT(module_load_ok);

    dvd_file->~DvdFile();

    OSModuleHeader* const header = static_cast<OSModuleHeader*>(l_loader_block);

    const u32 fix_size = (header->fixSize + 31) & ~31;
    const u32 total_size = fix_size + header->bssSize;
    const bool module_size_ok = total_size <= MODULE_BLOCK_SIZE;
    LOADER_ASSERT(module_size_ok);

    void* const bss_block = static_cast<u8*>(l_loader_block) + fix_size;

    const bool link_module_ok = OSLinkFixed(&header->info, bss_block);
    LOADER_ASSERT(link_module_ok);

    const u32 resized_size = heap->resizeForMBlock(l_loader_block, total_size);
    const bool module_resize_ok = resized_size >= total_size;
    LOADER_ASSERT(module_resize_ok);

    return nullptr;
}

} // namespace

// Loader entry point. Defined in section "start" so the linker will always place this first.
extern "C" [[gnu::section("start")]] bool LoaderMain()
{
    if (l_started) {
        if (l_thread.state != OSThreadState::OS_THREAD_STATE_EXITED) {
            return false;
        }
        GetHeap()->free(l_stack);

        OSModuleHeader* const header = static_cast<OSModuleHeader*>(l_loader_block);
        (*(void (*)(...)) header->prolog)(l_arc_entry_num, &l_arc_handle);
        return true;
    }

    // GetPortByCode must be called first.
    if (!GetPortByCode()) {
        // No valid region could be found! We have no OSFatal to display an error message, so just
        // skip loading our custom module.
        return true;
    }

    l_started = true;

    EGG::Heap* const heap = GetHeap();
    LOADER_ASSERT(heap);

    l_loader_block = heap->alloc(MODULE_BLOCK_SIZE, 32);
    LOADER_ASSERT(l_loader_block);

    l_stack = heap->alloc(STACK_SIZE, 32);
    const bool create_thread_ok = OSCreateThread(
      &l_thread, LoaderThread, nullptr, static_cast<u8*>(l_stack) + STACK_SIZE, STACK_SIZE, 17,
      OSThreadFlags::OS_THREAD_DETACHED
    );
    LOADER_ASSERT(create_thread_ok);

    OSResumeThread(&l_thread);

    return false;
}
