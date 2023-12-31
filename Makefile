# GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  Engine_config = debug
endif
ifeq ($(config),release)
  Engine_config = release
endif

PROJECTS := Engine

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

Engine:
ifneq (,$(Engine_config))
	@echo "==== Building Engine ($(Engine_config)) ===="
	@${MAKE} --no-print-directory -C Engine -f Makefile config=$(Engine_config)
endif

clean:
	@${MAKE} --no-print-directory -C Engine -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Engine"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"