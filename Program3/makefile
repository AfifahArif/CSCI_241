#
#	Program: program3
#	Programmer: Afifah Arif
#	Logon ID: XXXXXXX
#	Date due: 02/28/18
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign3: assign3.o Verifier.o
	g++ $(CCFLAGS) -o assign3 assign3.o Verifier.o

# Rules to compile source code files to object code
assign3.o: assign3.cpp Verifier.h
	g++ $(CCFLAGS) -c assign3.cpp

Verifier.o: Verifier.cpp Verifier.h
	g++ $(CCFLAGS) -c Verifier.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign3
