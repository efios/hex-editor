# temporary makefile

GC=g++
CO=-pedantic -Wall -Wextra
STD=-std=c++11
OUT=-o bin/
DIR=src/
LD=-lncurses


hex_edit:
	$(GC) $(DIR)hex_edit.cpp $(CO) $(LD) $(STD) $(OUT)hex_edit.o

directories:
	mkdir bin && mkdir bin/tmp
