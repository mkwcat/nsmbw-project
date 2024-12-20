# Add .d to Make's recognized suffixes.
SUFFIXES += .d

# Project directory
BUILD := ./build
ARCHIVE := NSMBWProjectData
ASSETS := $(BUILD)/$(ARCHIVE).arc.d
ASSETS_SRC := ./assets
TARGET := project_P1
LOADER := Loader
OUTPUT := ./output/riivolution/mkwcat-special-nsmbw-project
TOOLS := $(BUILD)/tools


# Compiler definitions
# CLANG := $(TOOLS)/clang
# CLANG := D:\wii\repo\llvm-project\build\bin\clang
HOST_CC := gcc
HOST_CXX := g++
CLANG := /Users/mkwcat/Documents/repo/llvm-project/build/bin/clang
CC := $(CLANG)
LD := $(DEVKITPPC)/bin/powerpc-eabi-ld
OBJCOPY := $(DEVKITPPC)/bin/powerpc-eabi-objcopy
ELF2REL := $(TOOLS)/elf2rel
LZX := $(TOOLS)/lzx
GENSMAP := ./tools/generate_symbol_map.py
WUJ5 := ./tools/wuj5/wuj5.py

SOURCES :=
-include ./source/sources.mk
-include ./assets/assets.mk


OFILES := $(SOURCES:.cpp=_cpp.o)
OFILES := $(OFILES:.c=_c.o)
OFILES := $(addprefix $(BUILD)/, $(OFILES))
DEPS := $(OFILES:.o=.d)

OUTDIRS := $(sort $(dir $(OFILES)))

LOADER_CPPFILES := ./loader/Loader.cpp
LOADER_OFILES := $(LOADER_CPPFILES:.cpp=_cpp.o)
LOADER_OFILES := $(addprefix $(BUILD)/, $(LOADER_OFILES))
LOADER_DEPS	:= $(LOADER_OFILES:.o=.d)

# Compiler options
CXXOPTS := -std=c++23 -MMD --target=powerpc-eabi-kuribo -Os -nodefaultlibs -include System.h

# Warnings
# -Wno-out-of-line-declaration is required to suppress errors when defining out-of-line aliases
CXXOPTS += -Wno-out-of-line-declaration -Wno-gcc-compat -Wno-invalid-offsetof -Wno-nested-anon-types -Wno-gnu-anonymous-struct

# Flags
CXXOPTS += -fno-PIC -fno-rtti -fno-short-enums -fshort-wchar -ffreestanding -ffunction-sections -fdata-sections \
           -fno-exceptions -fno-threadsafe-statics -fno-use-cxa-atexit -fkeep-static-consts

# Includes
CXXOPTS += -I./source -I./source/msl/msl_c -I./source/msl/msl_cpp -I./source/wiimj2d

# Preprocessor definitions
CXXOPTS += -DLOADER_REL_LZ

# Linker options
LDOPTS := -T./source/module.ld --gc-sections -r -n


.PHONY: all
all: $(OUTPUT)/$(ARCHIVE).arc $(OUTPUT)/$(LOADER).img

.PHONY: clean
clean:
	@echo Cleaning...
	@rm -rf $(BUILD)


-include $(DEPS)


$(BUILD)/%_c.o: %.c
	@echo $<
	@mkdir -p $(dir $@)
	@$(CC) -x c++ -c ./$< $(CXXOPTS) -o ./$@

$(BUILD)/%_cpp.o: %.cpp
	@echo $<
	@mkdir -p $(dir $@)
	@$(CC) -x c++ -c ./$< $(CXXOPTS) -o ./$@

$(BUILD)/$(TARGET).elf: $(OFILES)
	@echo Link: $(notdir $@)
	@$(LD) $(LDOPTS) $(OFILES) -o $@

$(BUILD)/$(TARGET).rel: $(BUILD)/$(TARGET).elf $(TOOLS)/elf2rel
	@echo Output: $(notdir $@)
	@$(ELF2REL) $< $@

$(ASSETS)/rels/$(TARGET).rel.LZ: $(BUILD)/$(TARGET).rel $(TOOLS)/lzx
	@echo Compress: $(notdir $@)
	@mkdir -p $(dir $@)
	@$(LZX) -ewb $< $@

$(ASSETS)/%: $(ASSETS_SRC)/%
	@echo $<
	@mkdir -p $(dir $@)
	@cp $< $@

$(ASSETS)/%.brlyt: $(ASSETS_SRC)/%.brlyt.json5
	@echo $<
	@mkdir -p $(dir $@)
	@python $(WUJ5) encode $< --outputs=$@

$(OUTPUT)/$(ARCHIVE).arc: $(DVD_FILES)
	@echo Build: $(notdir $@)
	@mkdir -p $(dir $@)
	@python $(WUJ5) encode $(ASSETS) --root= --outputs=$@

$(ASSETS)/wiimj2d.SMAP: $(BUILD)/$(TARGET).elf
	@echo Make: $(notdir $@)
	@python $(GENSMAP) $< $@

$(BUILD)/$(LOADER).elf: $(LOADER_OFILES)
	@echo Link: $(notdir $@)
	@$(LD) -T./loader/Loader.ld --gc-sections -n $(LOADER_OFILES) -o $@ 

$(OUTPUT)/$(LOADER).img: $(BUILD)/$(LOADER).elf
	@echo Output: $(notdir $@)
	@mkdir -p $(dir $@)
	@$(OBJCOPY) $< $@ -O binary

# Tool recipes

$(ELF2REL): ./tools/elf2rel/elf2rel.cpp
	@echo Build: $(notdir $@)
	@mkdir -p $(dir $@)
	@$(HOST_CXX) -std=c++17 -O2 -I $(dir $<) $< -o $@ 

$(LZX): ./tools/lzx/lzx.c
	@echo Build: $(notdir $@)
	@mkdir -p $(dir $@)
	@$(HOST_CC) -O3 -Wno-deprecated-declarations -Wno-pointer-sign $< -o $@
