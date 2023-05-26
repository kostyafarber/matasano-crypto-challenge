
s1_2: s1_2.c 
	gcc s1_2.c string_to_hex.c -g -o s1_2.o

s1_1: s1_1.c 
	gcc s1_1.c string_to_hex.c -g -o s1_1.o

string_to_hex: string_to_hex.c string_to_hex.h
	gcc string_to_hex.c -g -o string_to_hex.o