#
# PROGRAM: Program9
# PROGRAMMER(S): Afifah Arif
# LOGON ID: XXXXXXXX
# DATE DUE: 05/02/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign9: assign9.o Shape.o Circle.o Triangle.o Rectangle.o
	g++ $(CCFLAGS) -o assign9 assign9.o Shape.o Circle.o Triangle.o Rectangle.o

# Rules to compile source code files to object code
assign9.o: assign9.cpp Shape.h Circle.h Triangle.h Rectangle.h
	g++ $(CCFLAGS) -c assign9.cpp

Shape.o: Shape.cpp Shape.h
	g++ $(CCFLAGS) -c Shape.cpp

Circle.o: Circle.cpp Circle.h
	g++ $(CCFLAGS) -c Circle.cpp

Triangle.o: Triangle.cpp Triangle.h
	g++ $(CCFLAGS) -c Triangle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ $(CCFLAGS) -c Rectangle.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign9
