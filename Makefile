#
# PROGRAM:    assignX
# PROGRAMMER: Afifah Arif
# LOGON ID:   Z1791755
# DATE DUE:   X/X/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignX: assignX.o
        g++ $(CCFLAGS) -o assignX assignX.o

# Rule to compile source code file to object code
assignX.o: assignX.cpp
        g++ $(CCFLAGS) -c assignX.cpp

# Pseudo-target to remove object code and executable files
clean:
        -rm *.o assignX
