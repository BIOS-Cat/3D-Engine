BIN=$(BUILDDIR)/sdl_main

LIB=$(BUILDDIR)/lib/sdl_platform.o

all: $(BIN)

$(BUILDDIR)/sdl_main: main.c $(LIB)
	$(CC) $(CFLAGS) -framework SDL2 -framework OpenGL -o $@ $< $(LIB)
