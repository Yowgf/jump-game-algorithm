# ALG1-TP1 project Makefile
# Rules definition Makefile
# ==============================================================

# Links objects. Put first to avoid errors with .DEFAULT_GOAL assignment.
$(TARGET) : $(BUILD_MODS) $(OBJECT_FILES)
	$(info Linking code...)
	$(LINK_CODE)

# The --parents switch here allows to automatically create parent directories when needed.
$(OBJECT_MOD_DIRS) ::
	@-mkdir --parents $@

# Compiles objects.
$(BUILD)/%$(OBJECT_EXTENSION) :: $(APPLIANCE)/%$(APP_EXTENSION) $(HEADER)/%$(HEADER_EXTENSION)
	$(COMPIL_OBJECT_CODE)

# Deletes all the directories supposed to contain objects.
.PHONY : clean
clean ::
ifneq "$(origin OBJECT_DIRS)" "file"
		$(info Variable "OBJECT_DIRS" used for "clean" left undefined.)
		$(info Please check the file in $(GLOBAL_VARS))
else
		$(info Deleting all the directories and subfolders:)
		$(info $(OBJECT_DIRS))
		@echo
		@echo Are you sure? \(Y/N\)
		@read choice && \
		if [[ "$$choice" = "y" ]] || [[ "$$choice" = "Y" ]]; then \
		{ rm --verbose --preserve-root --recursive $(OBJECT_DIRS) && \
			echo Cleaning successful.; } || \
			$(call e_prev_cmd, Cleaning of some directory failed.) \
		else \
		echo No cleaning was performed.; \
		fi
endif

# Sink for unidentified patterns.
% ::
	@echo Archive or Pattern "$@" not found!