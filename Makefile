SRC = ./src
INCLUDE = ./include
BIN = ./bin
APPS = ./apps
OBJ = ./obj
LIB = ./lib
CC = gcc

FLAGS = -Wall -Wextra -Werror -g
LIBS = -lm -lds -L $(LIB)

all: libds myapps 

libds: \
	$(OBJ)/float_vector.o \
	$(OBJ)/linked_list.o \
	$(OBJ)/double_linked_list.o \
	$(OBJ)/circular_list.o \
	$(OBJ)/stacks.o \
	$(OBJ)/queue.o \
	$(OBJ)/hash_table.o \
	$(OBJ)/hash_table_sc.o

	@echo -e "\nLinking...\n"
	@ar -rcs $(LIB)/libds.a $(OBJ)/*.o
	
myapps: \
	$(BIN)/test_float_vector \
	$(BIN)/test_linked_list \
	$(BIN)/test_double_linked_list \
	$(BIN)/test_circular_list \
	$(BIN)/test_stacks \
	$(BIN)/test_queue \
	$(BIN)/test_hash_table \
	$(BIN)/test_hash_table_sc
	
	@echo -e "\nCompiling done! Testing typing './bin/test_name-of-data-structure'"

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	@echo "Compiling $(@F)..."
	@$(CC) $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c $(OBJ)/*.o
	@echo "Compiling app $(@F)..."
	@$(CC) $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@ 

re: clean all

clean:
	@echo -e "Cleaning...\n"
	@for file in $(BIN)/*; do \
		echo "Removing $$(basename $$file)"; \
	done
	@rm -f $(BIN)/* $(OBJ)/* $(LIB)/*
	@echo -e "\nFolders are cleaned!"

.PHONY: clean all
