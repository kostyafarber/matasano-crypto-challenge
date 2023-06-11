CC = gcc
CFLAGS= -g -o 
OBJS := s1_1.o s1_2.o s1_3.o s1_5.o

all: ${OBJS} 

%.o: %.c helpers.c
	${CC} $^ ${CFLAGS} $@
