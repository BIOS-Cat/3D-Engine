SUBDIRS=ci_capabilities plus
export LDFLAGS=`pkg-config --cflags --libs check`

.PHONY: $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@
