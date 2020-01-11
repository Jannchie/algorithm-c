# OUTDIR = dist
# SRC_PATH = src
# SRC_DIRS = $(shell find $(SRC_PATH) -maxdepth 3 -type d)
# DIST_DIRS = $(patsubst src%, dist%, $(SRC_DIRS))
# SRCS_C += $(foreach DIR, $(SRC_DIRS), $(wildcard $(DIR)/*.c))  

# OBJS_C = $(SRCS_C:c=o)

# OUT_C := $(OBJS_C:src%=dist%)

# TARGET_C = c-algorithm
# CC_C = clang


# all: $(TARGET_C)

# $(TARGET_C): $(OBJS_C)
# 	$(info $(OBJS_C))
# 	$(info $(TARGET_C))
# 	$(CC_C) -g $(OUT_C) -O3 -o $(OUTDIR)/$(TARGET_C)
# %.o: %.c 
# 	$(CC_C) -g -c $< -O3 -o $(patsubst src%, dist%, $@)




OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = inc
SRC_PATH = src
DIST_DIRS = $(OBJ_DIR) $(BIN_DIR)
SRC_DIRS = $(shell find $(SRC_PATH) -maxdepth 3 -type d)
SRC_C += $(foreach DIR, $(SRC_DIRS),$(wildcard $(DIR)/*.c))  
OBJ_C += $(SRC_C:%.c=%.o)
CC_C = clang
TARGET_C = $(SRC_C:%.c=%.)

all: makedir $(TARGET_C)
%.:  %.o
	$(CC_C) -g $(OBJ_DIR)/$(notdir $<) -O3 -o $(BIN_DIR)/$(notdir $(basename $@)) -L $(INC_DIR)
%.o: %.c
	$(CC_C) -g -c $< -O3 -o $(OBJ_DIR)/$(notdir $@) -I $(INC_DIR)
.PHONY: clean makedir
makedir: clean 
	$(foreach DIR, $(DIST_DIRS),$(shell mkdir "$(DIR)"))
clean:
	rm -rf $(DIST_DIRS)