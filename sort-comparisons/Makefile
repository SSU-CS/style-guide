# Use the gcc compiler
CC = gcc

# Set preprocessor flags
#CPPFLAGS=

# Set appropriate compiling flags
CFLAGS=-Wall -std=c99

all: sort_compare

sort_compare:  sort-comparisons.c
	$(CC) $(CFLAGS) -o sort_compare sort-comparisons.c

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
