#Team members: Aaron Chasse, Jake Borg, Doug Liu
#CSE 220 - Lab 3


#!/bin/bash
# File: Makefile

lister: main.o print.o scanner.o LinkedList.o Token.o bTree.o
	g++ main.o print.o scanner.o LinkedList.o Token.o bTree.o -o lister

main.o: main.cpp
	g++ -c main.cpp
print.o: print.cpp
	g++ -c print.pp
scanner.o: scanner.cpp
	g++ -c scanner.cpp
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp
Token.o: Token.cpp
	g++ -c Token.cpp
bTree.o: bTree.cpp
	g++ -c bTree.cpp



