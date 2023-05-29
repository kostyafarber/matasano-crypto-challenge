CC = gcc
CFLAGS= -g -o

hex_to_bytes: hex_to_bytes.c
	${CC} hex_to_bytes.c ${CFLAGS} $@

# all: s1_1.o s1_2.o s1_3.o

s1_3: s1_3.c 
	${CC} s1_3.c string_to_hex.c ${CFLAGS} s1_3.o

s1_2: s1_2.c 
	${CC} s1_2.c string_to_hex.c ${CFLAGS} s1_2.o

s1_1: s1_1.c 
	${CC} s1_1.c string_to_hex.c ${CFLAGS} s1_1.o

string_to_hex: string_to_hex.c string_to_hex.h
	${CC} string_to_hex.c ${CFLAGS} string_to_hex.o