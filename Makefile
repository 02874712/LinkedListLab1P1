# list/Makefile
#
# Makefile for list implementation and test file.
#
# Tashiana Johnson

linked_list: list.c main.c
	gcc list.c list.h main.c -o list

clean: 
	rm list 
