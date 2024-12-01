# Game Title, up to 12 Characters, Null Padded
GAME_TITLE = "ADVENTOFCODE"
# Game Code, 4 Characters
GAME_CODE = "2024"
# Maker Code, 2 Characters
MAKER_CODE = "WM"

obj := ./src/lib/asm/crt0.o ./src/main.o
elf := output.elf
bin := output.gba

CC := arm-none-eabi-gcc
AS := arm-none-eabi-as
OBJCOPY := arm-none-eabi-objcopy
PYTHON := python3
BUILDDIR := build

opt := -O3 -fomit-frame-pointer -marm -mcpu=arm7tdmi

CFLAGS := $(opt) -std=gnu99 -pedantic -Wall

.PHONY: clean, run

$(bin): $(obj)
	$(CC) -o ./$(BUILDDIR)/$(elf) $(obj) -Tlnkscript -nostartfiles -lm
	$(OBJCOPY) -O binary ./$(BUILDDIR)/$(elf) ./$(BUILDDIR)/$(bin)
	$(PYTHON) ./checksum/checksum_gen.py ./$(BUILDDIR)/$(bin) $(GAME_TITLE) $(GAME_CODE) $(MAKER_CODE)

-include $(obj:.o=.d)

%.d: %.c
	@rm -f $@; $(CC) -MM $(CFLAGS) $< > $@

clean:
	rm -f $(obj) $(obj:.o=.d)
	rm -f ./build/*

run:
	mgba -4 ./$(BUILDDIR)/$(bin)