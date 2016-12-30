export BUILDDIR=$(CURDIR)/build
BUILDSUBDIRS=$(BUILDDIR) $(BUILDDIR)/tests $(BUILDDIR)/lib
SUBDIRS=src test

export CFLAGS+=-I$(CURDIR)/include

TESTS=$(wildcard $(BUILDDIR)/tests/*_test_suite)

.PHONY: clean check $(SUBDIRS)

all: $(BUILDSUBDIRS) $(SUBDIRS)

$(BUILDSUBDIRS):
	mkdir $@

$(SUBDIRS):
	$(MAKE) -C $@

check:
	$(foreach TEST, $(TESTS), $(TEST);)

clean:
	rm -rf $(BUILDDIR)
