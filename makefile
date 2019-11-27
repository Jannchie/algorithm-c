OUTDIR = ./dist
src = $(wildcard src/*.c src/sort/*.c  src/data-structure/*.c)  
obj = $(patsubst %.c, %.o, $(src))  
out := $(obj:src%=dist%)
target = c-algorithm
CC = clang

$(target): $(obj)  
	$(CC) -g $(out) -o $(OUTDIR)/$(target)
%.o: %.c  
	$(CC) -g -c $< -o $(patsubst src%, dist%, $@) 
.PHONY:
	clean
clean:
	rm -rf $(OUTDIR)/$(obj) $(OUTDIR)/$(target)
