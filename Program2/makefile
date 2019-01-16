#
# PROGRAM: Program2
# PROGRAMMER: Afifah Arif
# LOGON ID: XXXXXXXX
# DATE DUE: 02/15/18
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign2: assign2.o Book.o BookStore.o
	g++ $(CCFLAGS) -o assign2 assign2.o Book.o BookStore.o

# Rules to compile source code files to object code
assign2.o: assign2.cpp BookStore.h
	g++ $(CCFLAGS) -c assign2.cpp

Book.o: Book.cpp Book.h
	g++ $(CCFLAGS) -c Book.cpp

BookStore.o: BookStore.cpp BookStore.h
	g++ $(CCFLAGS) -c BookStore.cpp

BookStore.h: Book.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign2
