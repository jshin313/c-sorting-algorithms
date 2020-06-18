# Based off of: https://stackoverflow.com/a/30602701

OBJ_DIR = obj
BIN_DIR = .
INCLUDE_DIR = algos

EXE = $(BIN_DIR)/testcases
INCLUDESRC = $(wildcard $(INCLUDE_DIR)/*.c) 
OBJ = $(INCLUDESRC:$(INCLUDE_DIR)/%.c=$(OBJ_DIR)/%.o) testcases.o

CC = gcc
CFLAGS   = -Wall -I$(INCLUDE_DIR) -ggdb
#LDFLAGS  = -Llib
#LDLIBS   = -lm

.PHONY: all clean

all: $(EXE)
debug: clean
debug: CFLAGS += -DDEBUG
debug: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ 
	mv *.o $(OBJ_DIR) #IDK how to do it the right way

$(OBJ_DIR)/%.o: $(INCLUDE_DIR)/%.c | $(OBJ_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(OBJ_DIR) $(EXE) *.o #$(BIN_DIR) 
-include $(OBJ:.o=.d)
