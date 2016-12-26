TEST_SRCS=$(wildcard *_test.c)
TESTS=$(BUILDDIR)/tests/$(TEST_SRCS:.c=)_suite

LIB=$(BUILDDIR)/lib/plus.o

all: $(TESTS)

$(BUILDDIR)/tests/%_test_suite: %_test.c
	$(CC) $(CFLAGS) -o $@ $< $(LIB) $(LDFLAGS)
