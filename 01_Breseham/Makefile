TARGET := $(shell $(CC) -dumpmachine)
WINDOWS := $(strip $(foreach W,msys w64 windows,$(findstring -$W-,-$(TARGET)-)))
BINEXT := $(if $(WINDOWS),.exe,)

ERROR_CFLAGS := -Wall -Wc++-compat -Wconversion -Wextra -Wpedantic -Wvla
CFLAGS := $(ERROR_CFLAGS) $(CFLAGS)

NAME := breseham
OUT_FILE := $(NAME)$(BINEXT)

.PHONY: build

build: build/$(OUT_FILE)

build/:
	mkdir $@

build/$(OUT_FILE): $(NAME).c | build/
	$(CC) $(CFLAGS) -o $@ $^
