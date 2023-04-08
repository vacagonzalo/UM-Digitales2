SUBDIRS := $(wildcard */.)

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

all: $(SUBDIRS)

$(SUBDIRS):
	@echo -e "${GREEN} building $@ ${NC}"
	$(MAKE) -C $@

.PHONY: all $(SUBDIRS)
