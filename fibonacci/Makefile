# Use the gcc compiler
CC = gcc

# Set preprocessor flags
#CPPFLAGS=

# Set appropriate compiling flags
CFLAGS=-Wall -std=c99

all: fibonacci

fibonacci:  fibonacci.c
	$(CC) $(CFLAGS) -o fibonacci fibonacci.c

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
