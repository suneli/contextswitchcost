SRC = measureSingle.c measureSwitch.c
OBJ = $(addsuffix .o, $(basename $(SRC)))
TARGET = $(basename $(OBJ))
CC = gcc
CCFLAGS = -Wall
DFLAGS = -DUSE_CLOCK_GETTIME
#DFLAGS = -DUSE_ORIGINAL_TIME_UTIL

all: $(TARGET)

measureSingle: measureSingle.o util.o timeutil.o
	${CC} ${CCFLAGS} ${DFLAGS} -o $@ $^

measureSwitch: measureSwitch.o util.o timeutil.o
	${CC} ${CCFLAGS} ${DFLAGS} -o $@ $^

.c.o:
	${CC} ${CCFLAGS} ${DFLAGS} -c $<

clean:
	rm -f *.o $(TARGET) 
	
