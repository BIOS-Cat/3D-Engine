export BUILDDIR=$(CURDIR)/build
BUILDSUBDIRS=$(BUILDDIR) $(BUILDDIR)/tests $(BUILDDIR)/lib
SUBDIRS=src test

export CC+=-I$(CURDIR)/include

TESTS=$(wildcard $(BUILDDIR)/tests/*_test_suite)

.PHONY: clean test $(SUBDIRS)

all: $(BUILDSUBDIRS) $(SUBDIRS)

$(BUILDSUBDIRS):
	mkdir $@

$(SUBDIRS):
	$(MAKE) -C $@

run_test:
	$(foreach TEST, $(TESTS), $(TEST);)

clean:
	rm -rf $(BUILDDIR)
