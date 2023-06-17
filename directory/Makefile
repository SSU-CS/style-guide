# Makefile for compiling the SchoolDirectory program, written in C++

# Type "make" in the directory with the required classes.
# to construct the full application

# Use the g++ compiler
CXX = g++

# Set preprocessor flags
#CPPFLAGS=

# Set appropriate compiling flags
CXXFLAGS=-Wall -std=c++98

all: SchoolDirectory

SchoolDirectory:  SchoolDirectory.cpp Entry.o Student.o Faculty.o Staff.o
	$(CXX) $(CXXFLAGS) -o SchoolDirectory SchoolDirectory.cpp Entry.o Student.o Faculty.o Staff.o

Entry.o:  Entry.cpp Entry.h
	$(CXX) $(CXXFLAGS) -c Entry.cpp

Student.o:  Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -c Student.cpp

Faculty.o: Faculty.cpp Faculty.h
	$(CXX) $(CFLAGS) -c Faculty.cpp

Staff.o: Staff.h Staff.cpp
	$(CXX) $(CXXFLAGS) -c Staff.cpp

#----------------------------------------------------------------------------
# cleanup rules: To invoke this command, type "make clean".
# Use this target to clean up your directory, deleting (without warning) 
#   object files, old emacs source versions, and core dumps.

clean: 
	rm -f *.o *~ core*


#----------------------------------------------------------------------------
# Doxygen documentation

Doxyfile: Doxyfile-simple
	cp Doxyfile-simple Doxyfile

docs/html/index.html: Doxyfile
	doxygen Doxyfile

docs/latex/refman.pdf: Doxyfile
	doxygen Doxyfile
	make refman.pdf -C docs/latex
