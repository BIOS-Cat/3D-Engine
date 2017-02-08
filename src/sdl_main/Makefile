BIN=$(BUILDDIR)/sdl_main

LIB=$(BUILDDIR)/lib/sdl_platform.o

all: $(BIN)

$(BUILDDIR)/sdl_main: main.c $(LIB)
	$(CC) $(CFLAGS) `pkg-config --libs --cflags sdl2` -framework OpenGL -o $@ $< $(LIB)
