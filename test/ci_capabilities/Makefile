TEST_SRCS=$(wildcard *_test.c)
TESTS=$(BUILDDIR)/tests/$(TEST_SRCS:.c=)_suite

LDFLAGS+=-framework OpenGL

all: $(TESTS)

$(BUILDDIR)/tests/%_test_suite: %_test.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
