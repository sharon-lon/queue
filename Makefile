


CFLAGS	:= -Wall 

SRC = src/queue.c

OBJS := $(patsubst %.c,%.o,$(SRC))

all:build/libqueue.a

install:all
	cp -f build/libqueue.a   $(PREFIX)/lib/libqueue.a
	cp -f src/queue.h   $(PREFIX)/include/list.h
	
uninstall:
	rm -f $(PREFIX)/lib/libqueue.a
	rm -f $(PREFIX)/include/list.h

build/libqueue.a:$(OBJS)
	@mkdir -p build
	$(AR) rcs $@ $^



%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@	
	
clean:
	rm -fr bin build *.o src/*.o  test/*.o   test/test
	@make clean -C test 


test:build/libqueue.a
	@make -C test
	@./test/test


.PHONY: test clean install uninstall

	