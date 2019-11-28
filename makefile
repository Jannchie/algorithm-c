OUTDIR = ./dist
src = $(wildcard src/*.c src/sort/*.c  src/data-structure/*.c)  
obj = $(patsubst %.c, %.o, $(src))  
out := $(obj:src%=dist%)
target = c-algorithm
CC_CPP = clang++
CC_C = clang

$(target): $(obj)  
	$(CC_CPP) -g $(out) -o $(OUTDIR)/$(target)
%.o: %.c  
	$(CC_C) -g -c $< -o $(patsubst src%, dist%, $@) 
%.o: %.cpp 
	$(CC_CPP) -g -c $< -o $(patsubst src%, dist%, $@) 
.PHONY:
	clean
clean:
	rm -rf $(OUTDIR)/$(obj) $(OUTDIR)/$(target)
