# Compiler variables
CCFLAGS = -Wall -std=c++11
PROGNAME = main

# Rule to link object code files to create executable file
$(PROGNAME): $(PROGNAME).o verify.o
	g++ $(CCFLAGS) -o $(PROGNAME) $(PROGNAME).o verify.o
   
# Rules to compile source code files to object code
$(PROGNAME).o: $(PROGNAME).cpp verify.h
	g++ $(CCFLAGS) -c $(PROGNAME).cpp
      
verify.o: verify.cpp verify.h
	g++ $(CCFLAGS) -c verify.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o $(PROGNAME)
