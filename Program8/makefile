#
# PROGRAM: Program8
# PROGRAMMER: Afifah Arif
# LOGON ID: XXXXXXXX
# DATE DUE: 04/26/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o
	g++ $(CCFLAGS) -o assign8 assign8.o

# Rules to compile source code files to object code
assign8.o: assign8.cpp sorts.h
	g++ $(CCFLAGS) -c assign8.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8
