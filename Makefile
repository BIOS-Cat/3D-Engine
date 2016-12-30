export BUILDDIR=$(CURDIR)/build
BUILDSUBDIRS=$(BUILDDIR) $(BUILDDIR)/test $(BUILDDIR)/lib
SUBDIRS=src test

export CFLAGS+=-I$(CURDIR)/include -std=c99

TEST_SUITE=$(BUILDDIR)/test/test_suite

.PHONY: clean check $(SUBDIRS)

all: $(BUILDSUBDIRS) $(SUBDIRS)

$(BUILDSUBDIRS):
	mkdir $@

$(SUBDIRS):
	$(MAKE) -C $@

check:
	$(TEST_SUITE)

clean:
	rm -rf $(BUILDDIR)
