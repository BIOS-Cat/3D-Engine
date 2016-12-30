SOURCES=$(wildcard *.c)

OBJS=$(BUILDDIR)/lib/$(SOURCES:.c=.o)

$(info $(OBJS))

all: $(OBJS)

$(BUILDDIR)/lib/%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<
