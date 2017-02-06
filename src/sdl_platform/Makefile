SOURCES=$(wildcard *.c)

OBJS=$(BUILDDIR)/lib/$(SOURCES:.c=.o)

all: $(OBJS)

$(BUILDDIR)/lib/%.o:%.c
	$(CC) $(CFLAGS) -c `pkg-config --libs --cflags sdl2` -framework OpenGL -o $@ $< $(LIB)
