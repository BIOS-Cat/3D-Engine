SUBDIRS=plus math

TEST_SUITE_SRC=test_suite.c
TEST_SUITE_OBJ=$(BUILDDIR)/test/$(TEST_SUITE_SRC:.c=.o)

TEST_SRCS=$(foreach DIR, $(SUBDIRS), $(wildcard $(DIR)/*_test.c))
TEST_OBJS=$(addprefix $(BUILDDIR)/test/, $(TEST_SRCS:.c=.o))
TEST_SUITE=$(BUILDDIR)/test/test_suite
TEST_BUILDSUBDIRS=$(addprefix $(BUILDDIR)/test/, $(SUBDIRS))

PRODUCTION_OBJS=$(wildcard $(BUILDDIR)/lib/*.o)

LDFLAGS+= -framework SDL2 -framework OpenGL `pkg-config --cflags --libs check`

all: $(TEST_BUILDSUBDIRS) $(TEST_SUITE)

$(TEST_SUITE): $(TEST_SUITE_OBJ) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(PRODUCTION_OBJS) $(LDFLAGS)

$(TEST_SUITE_OBJ): $(TEST_SUITE_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/test/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TEST_BUILDSUBDIRS):
	mkdir $@
