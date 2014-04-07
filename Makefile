#Team members: Aaron Chasse, Jake Borg, Doug Liu
#CSE 220 - Lab 3


#!/bin/bash
# File: Makefile

lister: main.o Print.o Scanner.o LinkedList.o Token.o bTree.o
	g++ main.o Print.o Scanner.o LinkedList.o Token.o bTree.o -o lister

main.o: main.cpp
	g++ -c main.cpp
Print.o: Print.cpp
	g++ -c Print.cpp
Scanner.o: Scanner.cpp
	g++ -c Scanner.cpp
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp
Token.o: Token.cpp
	g++ -c Token.cpp
bTree.o: bTree.cpp
	g++ -c bTree.cpp



