
## @author: Kemeng Chen
## @email: kemengchen@email.arizona.edu


SHELL        =  /bin/bash
.SUFFIXES:
.SUFFIXES:      .c .h .o

CC           =  gcc
INCLUDE_DIR  =  includes/
SRC_DIR      =  src/
OBJ_DIR      =  obj/
BIN_DIR      =  bin/

_BIN         =  exe.out
BIN          =  $(addprefix $(BIN_DIR), $(_BIN))

SRCS         =  $(wildcard $(SRC_DIR)*.c)
_OBJS        =  $(patsubst $(SRC_DIR)%.c, %.o, $(SRCS))
OBJS         =  $(addprefix $(OBJ_DIR), $(_OBJS))


INCLUDES     =  $(wildcard $(INCLUDE_DIR)*.h)

CFLAGS       =  -Wall -ggdb -I $(INCLUDE_DIR) 
OFLAGS       =  -pthread 

$(BIN): $(BIN_DIR) $(OBJS) 
	$(CC) $(OFLAGS) $(OBJS) -o $(BIN)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC)  $(CFLAGS) -c $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BIN) 

print-% :
	@echo $* = $($*)