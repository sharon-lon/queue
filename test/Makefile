TARGET:=test

SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.o,%.c,$(SRC))

CFLAGS := -I.  -I../src -Wall
LIBS := -L. -L../build  -lqueue 


all:$(TARGET)

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS)  -o $@ $^ $(LIBS)

.PHONY:clean

clean:
	-rm -f *.o $(TARGET)
