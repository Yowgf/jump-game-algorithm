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
		$(info Variavel para limpeza "OBJECT_DIRS" nao foi definida.)
		$(info Por favor verifique arquivo em $(GLOBAL_VARS))
else
		$(info Limpando todos os diretorios:)
		$(info $(OBJECT_DIRS))
		@echo
		@echo Tem certeza que quer prosseguir? \(Y/N\)
		@read choice && \
		if [[ "$$choice" = "y" ]] || [[ "$$choice" = "Y" ]]; then \
		{ rm --verbose --preserve-root --recursive $(OBJECT_DIRS) && \
			echo Limpeza bem-sucedida.; } || \
			$(call e_prev_cmd, Limpeza de algum diretorio falhou.) \
		else \
		echo Limpeza nao executada.; \
		fi
endif

# Sink for unidentified patterns.
% ::
	@echo Archive or Pattern "$@" not found!