SOURCES=$(wildcard *.c)

OBJS=$(BUILDDIR)/lib/$(SOURCES:.c=.o)

all: $(OBJS)

$(BUILDDIR)/lib/%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<
