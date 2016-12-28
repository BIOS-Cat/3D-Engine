TEST_SRCS=$(wildcard *_test.c)
TESTS=$(BUILDDIR)/tests/$(TEST_SRCS:.c=)_suite

LDFLAGS+=-framework OpenGL

all: $(TESTS)

$(BUILDDIR)/tests/%_test_suite: %_test.c
ifeq ($(TRAVIS),1)
	$(CC) $(CFLAGS) -D"__travis__=1" -o $@ $< $(LDFLAGS)
else
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
endif
