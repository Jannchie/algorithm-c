OUTDIR = dist
SRC_PATH = src
SRC_DIRS = $(shell find $(SRC_PATH) -maxdepth 3 -type d)
DIST_DIRS = $(patsubst src%, dist%, $(SRC_DIRS))
SRCS_CPP += $(foreach DIR, $(SRC_DIRS), $(wildcard $(DIR)/*.cpp))  
SRCS_CC += $(foreach DIR, $(SRC_DIRS), $(wildcard $(DIR)/*.cc))  
SRCS_C += $(foreach DIR, $(SRC_DIRS), $(wildcard $(DIR)/*.c))  

OBJS_CPP = $(patsubst %.cpp, %.o, $(SRCS_CPP))  
OBJS_CC = $(patsubst %.cc, %.o, $(SRCS_CC))  
OBJS_C = $(patsubst %.c, %.o, $(SRCS_C))  

OUT_C := $(OBJS_C:src%=dist%)
OUT_CPP := $(OBJS_CPP:src%=dist%)

TARGET_C = c-algorithm
TARGET_CPP = cpp-algorithm
CC_C = clang
CC_CPP = clang++


all: $(TARGET_C) $(TARGET_CPP)

$(TARGET_C): $(OBJS_C)
	$(CC_C) -g $(OUT_C) -O3 -o $(OUTDIR)/$(TARGET_C)
%.o: %.c makedir
	$(CC_C) -g -c $< -O3 -o $(patsubst src%, dist%, $@) 

$(TARGET_CPP): $(OBJS_CPP)  
	$(CC_CPP) -g $(OUT_CPP) -O3 -o $(OUTDIR)/$(TARGET_CPP)
%.o: %.cpp makedir
	$(CC_CPP) -g -c $< -O3 -o $(patsubst src%, dist%, $@) 

.PHONY:
	clean makedir
makedir: 
	$(foreach DIR, $(DIST_DIRS), $(shell mkdir "$(DIR)"))
clean:
	rm -rf $(OUTDIR)/$(obj) $(OUTDIR)/$(target)
