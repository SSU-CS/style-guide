# C/C++ Style Guide for SSU


## Introduction
The style guidelines identified in this document represent the default standards for C/C++ programs that are written for courses within the Department of Computer Science at Sonoma State University.

### Purpose
Computer programs convey proposed solutions to problems and have at least three audiences:

 * The original programmer, or the programmer's team, who are developing, debugging, or refining a solution.
 * Other programmers who may wish to understand, review, modify, or expand a program.
 * The compiler which will translate the program to machine language for subsequent machine execution.

As a vital mechanism for effective communication, programs must convey solutions clearly and concisely, and programs must be easily readable by a broad audience: a programmer, the programmer's team, and future programmers who may need to study, correct, or maintain the code. Google identifies further "Background" and "Goals of the Style Sheet" at the beginning of [Google's C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

Although the C/C++ Programming Language allows programmers to utilize a wide range of formatting conventions, the programming culture for both C/C++ and Java largely has settled upon several widely-adopted conventions. Although some style elements vary somewhat from one organization to another, several central elements are identified and will form the style manual for use within computer science courses at Sonoma State University (unless otherwise stated by the instructor of a specific course).


### Alignment with Doxygen
[Doxygen](https://www.doxygen.nl/index.html) allows the automatic generation of html and Latex documentation directly from the annotations in C/C++ programs. Many elements in this style guide are compatible with and conformant to Doxygen's code annotations. 

Individual faculty may or may not require programs to conform to all of Doxygen's conventions. If faculty require code submissions to be fully conformant with Doxygen annotations, they may require source code and/or documentation files to be submitted as artifacts.

Doxygen relies upon the software package [graphviz](https://graphviz.org/) for generating images for calling diagrams, class diagrams, and file dependencies. See the [Tutorial: Using Doxygen with graphviz](../tutorials) for resources.

!!! quote "Doxygen"

    Doxygen is the de facto standard tool for generating documentation from annotated C++ sources, but it also supports other popular programming languages such as C, Objective-C, C#, PHP, Java, Python, IDL (Corba, Microsoft, and UNO/OpenOffice flavors), Fortran, VHDL and to some extent D.

Example configuration files to create Doxygen-generated documentation are included for every sample project with this style guide. If you like, you can checkout the repository and re-build its documentation to experiment.

| Sample Project | Using Doxygen | Using Doxygen + dot |
|----------------|:------------------:|:------------------------:|
| [`directory/`](https://github.com/SSU-CS/style-guide/tree/main/directory) | [:material-web:HTML](../directory-docs/simple/html/) &nbsp; [:fontawesome-regular-file-pdf:PDF](../directory-docs/simple/latex/refman.pdf) | [:material-web:HTML](../directory-docs/graphics/html) &nbsp; [:fontawesome-regular-file-pdf:PDF](../directory-docs/graphics/latex/refman.pdf) |
| [`fibonacci/`](https://github.com/SSU-CS/style-guide/tree/main/fibonacci) | [:material-web:HTML](../fibonacci-docs/simple/html/) &nbsp; [:fontawesome-regular-file-pdf:PDF](../fibonacci-docs/simple/latex/refman.pdf) | [:material-web:HTML](../fibonacci-docs/graphics/html) &nbsp; [:fontawesome-regular-file-pdf:PDF](../fibonacci-docs/graphics/latex/refman.pdf) |
| [`sort-comparisons/`](https://github.com/SSU-CS/style-guide/tree/main/sort-comparisons) | [:material-web:HTML](../sort-comparisons-docs/simple/html/) &nbsp; [:fontawesome-regular-file-pdf:PDF](../sort-comparisons-docs/simple/latex/refman.pdf) | [:material-web:HTML](../sort-comparisons-docs/graphics/html) &nbsp;  [:fontawesome-regular-file-pdf:PDF](../sort-comparisons-docs/graphics/latex/refman.pdf)  |
 
 

## Whitespace
These conventions are intended for any code that will be read on a screen or printed on paper.

### Line Length
Ensure that no line of code is longer than 80 characters. 

???+ info

    The 80 character rule is a common [line limit in C/C++ style guides](https://en.wikipedia.org/wiki/Characters_per_line). While technological constraints originating the rule (punchcard length and dumb terminal width) may no longer be relevant, this standard re-affirms its reasonableness as a limit.

### Use spaces for indentation
Any block of code enclosed in curly braces should be indented one level deeper than the surrounding code. 

 -  Choose a reasonable and consistent convention for indentation; generally 3--5 spaces is acceptable. We recommend 3 spaces for indentation.
 - Although a programmer may choose indenting between 3 and 5 characters within a block, all indenting must be consistent throughout the code. Thus, if indentation within an `if` block is 4 spaces in one instance, then all blocks (`if`, `while`, functions, etc) should also be indented 4 spaces.
 - Do not indent with tab characters (`\t`).  Tab stop settings vary from one environment to another.

???+ Tip "Tip: Adjust the tab settings of your editor"

    Set the "Tab policy" of your editor for all projects.
    
    - For Eclipse: see ["Spaces only" option](http://stackoverflow.com/questions/407929/how-do-i-change-eclipse-to-use-spaces-instead-of-tabs)".
    - For emacs: see [Google's C/C++ style for c-mode](https://raw.githubusercontent.com/google/styleguide/gh-pages/google-c-style.elsx).



### Use curly braces consistently
Use "Egyptian"-style curly braces in your code in accordance with the C/C++ style guidelines.

???+ example

    ``` cpp
    /* Egyptian braces: opening brace on same line, closing brace on own line */
    if (a == b) {
       cout << "these are Egyptian braces";
    }
    else {
       cout << "hello, world!";
    }
    ```

### Use curly braces around all blocks
Although C/C++ permits the omission of curly braces in cases where the body if-statement or loop consists of a single statement, we require that every block (no matter the number of statements) be enclosed inside curly braces on a new line.

???+ example
        
    ``` cpp
    // YES   YES   YES  
    while (x < 5) {
       cout << "Inside block";
    }
    cout << "OK -- Not inside block!";
    ```

It is far too easy to make programming errors of this form otherwise:

???+ bug    
        
    ``` cpp 
    // NO  NO  NO
    while (x < 5)
       cout << "Inside block";
       cout << "BUG -- Not inside block!";
    ```

### One statement per line
There should be no more than one statement (declaration, assignment, or function call) on any line of your program.

### Vertical whitespace to separate chunks of code
Within a block of code, use vertical whitespace (blank lines) to separate groups of statements. This makes code more readable and clarifies which statements are logically related. Note that if you have to resort to this rule, you should consider breaking your code up into multiple functions instead.

### Use spaces around operators
Every C/C++ operator should have spaces around it (except the dot operator, e.g. method calls `c.foo()`). Use parentheses to communicate precedence. For example, `5 - (x + 4) * 8`

### Printing standards
These additional requirements are only relevant when printing code on paper.

 - Use only full sheets of clean white paper. Colored paper or paper with other printing on one or both sides is not appropriate.

 - Use a fixed-width font of size at least 12 point size. We recommend Courier font.

 - Use a dark font (e.g., black, dark blue, dark green, dark brown) on a light background (e.g., white or cream). Dark backgrounds are wasteful of ink resources, expensive to print, and sometimes streak or bleed together when printed. Thus, dark backgrounds are unacceptable.


## Naming Conventions

### Use descriptive names
Names should reflect their use within the context of the program. For example, `total` and `subTotal` describe the contents of the variables, while `foo` and `bar` do not.

### Use more descriptive names for larger scopes
Variables that have greater scope should have more descriptive names. While it is often preferred to use a short name like `i` or `j` as a loop index, when the scope of an identifier increases, so should the meaningfulness of its name. For example, prefer `leftChild` over `l` for a class field.

### Naming variables and methods
All single-word names should be in lowercase.

For multiple word names:

 - In C/C++, use [lowerCamelCase](https://en.wikipedia.org/wiki/Camel_case) for variable and method names, where subsequent words should be joined with their first character capitalized and should not contain underscores.
 - In C, it is acceptable to use [snake_case](https://en.wikipedia.org/wiki/Snake_case) for variable and method names (subsequent words are joined with underscores, in lower case). Do not mix snake_case and lowerCamelCase conventions.

### Naming classes
Use [UpperCamelCase](https://en.wikipedia.org/wiki/Camel_case) for class names and enum type names. Do not capitalize acronyms within camelCased names; the string "TCP socket ID" should be written `TcpSocketId` rather than `TCPSocketID`.

### Naming constant and enum values
Values that are constants, including final static variables and enum values, should follow `CAPITALIZED_WITH_UNDERSCORES` conventions, in which all-caps words are separated by underscore characters.

### Naming files
Follow common conventions for file extensions. In particular, use `.h` for header files, `.c` for C code, `.cpp` for C++ code, and `.tcc` for C++ template files. 

Although the C Standard does not require specific file extensions and `#include` statements require explicit inclusion of extensions within file names, numerous editors and some compilers (e.g., `gcc`) draw inferences from the extensions used.

## Comments

### Do not over-comment code
If a piece of code is reasonably obvious to experienced C/C++ programmers, then it does not need to be commented. Be judicious; if you are unsure, it is often best not to include a redundant comment. If you feel like it is necessary to extensively comment your code, consider how to rewrite it to make it more straightforward.

### Comments describe purpose over implementation
The code itself is a description of an implementation, so it is unnecessary to comment what the code is doing (e.g., `x++` does not need a comment like "Increment x"). Instead, describe at a high level the intended use of the piece of code, such as what task the function performs.

### Include a program header
At the start of a program file, write comments to introduce the program. These should include:

 - a description of the overall purpose of the program, such as the problem the program addresses. 
 - a listing of the programmers involved, with an `@author` annotation for each author.
 - a list of all references from which the code (or ideas for the code) were drawn, with a `@remark` annotation.
 - each reference should be in its own `@remark` block:

???+ example

    ```cpp
    /**
     * @remark Uses a basic recursive approach to compute the 
     *  n-th Catalan number, both with and without dynamic prog.
     * 
     * @author Henry M. Walker
     * @author Ali K. Kooshesh
     * 
     * @remark References
     * 
     * @remark Dynamic Programming: Anany Levitin, "The Design and
     *  and Analysis of Algorithms", Second Edition,
     *  Chapter 8: Dynamic Programming                                    
     * 
     * @remark Dynamic Programming: Anany Levitin, "The Design and
     *  and Analysis of Algorithms", Second Edition,
     *  Section 2.5:  Example: Computing the nth Fibonacci Number          
     * 
     * @remark People involved in problem/program discussions: 
     *   - Mark Gondree
     */
    ```

???+ tip

    Doxygen also supports using bibliographic references in BibTex format (`.bib` files). BibTex/LaTeX details are beyond the scope of this Style Guide.

### Procedures should be commented
All C functions, all C++ public methods, and all non-trivial C++ private methods should include comments holding documentation. Each should describe:

 - the function's intended use,
 - the function's parameters, using a `@param` tag for each function/method parameter,
 - the function's return value, using a `@returns` tag (if applicable), 
 - exceptions thrown (if any), and
 - any pre-conditions using a `@pre` tag.

???+ example

    ``` pre
    /**
     * merge sort helper function
     * 
     * @param   initArr   the array to be sorted
     * @param   n         the size of the array
     * @post    the first n elements of the array are sorted in non-descending order
     * @returns  zero on success, non-zero on error
     **/
    int mergeSort (int initArr [ ], int n) {
       // to be implemented 
    }
    ```


### Logic within procedures should be commented
Within a procedure or method, include comments to explain the logic of each section of code. At a minimum, at least one comment describing logic should be included within any block of 20 lines.

### Control blocks should be commented
Every non-trivial control block (`if`, `for`, `while`, etc) should include a “why” comment: why is this block of code needed? What is the purpose of the condition in the case of a controlled block of code. 

???+ example

    ``` cpp
       int i, j, smallIndex;
       int temp;
       // put largest remaining element in a[i]
       for (i = n-1; i >= 0; i--) {
          // find largest in a[i..n-1]
          smallIndex = i;
          for (j = i-1; j >= 0; j--) {
             if (a[smallIndex] < a[j]) {
                smallIndex = j;
             }
         }
    ```

### No dead code
Remove any dead or commented-out code from your source files before submission. Commenting out code is useful in development, but do not submit commented-out code in your final product.

## Reuse code and efficiency

### Use library functions, when possible
C/C++ has quite a rich standard library. You should make use of its provided functions instead of re-implementing them (unless otherwise directed). Your re-implementation will almost always be less efficient (and is less likely to be correct).

### Avoid redundant computation
Use a helper variable or method to avoid computing values multiple times. If you find that a particular sequence of computations is being repeated more than twice, you should assign it to a variable and/or abstract it into a helper function which returns the desired value.

### Avoid redundant or verbose expressions
Write expressions for `if` conditions, `while` loop guards, etc. in the most succinct and expressive way possible. Especially, consider whether a long expression involving multiple `||` or `&&` operators is easily readable and whether it could be written with fewer or simpler sub-expressions.

## Organization

### Class implementation organization

Classes should be organized internally in the order:

 1. Import statements,
 2. Fields,
 3. Constructors, and
 4. Methods

### Decompose logic into unique, specific tasks

Methods and classes should perform one specific and unique task. This is known as the _principle of separation of concerns_: each class and method should be responsible for one thing and one thing only. Your program should be composed of a group of such classes which cooperate to achieve a goal.

Put another way: avoid creating a single method or class that "does too much," meaning a method or class that serves multiple disjoint purposes or is responsible for too much. Such implementations are often unwieldy and difficult to extend or debug. 

### Class extension should always represent "is-a" relationships
When creating a subclass, make sure that the subtype Foo "is-a" version or variant of supertype Bar. 

???+ tip

    If the relationship is more appropriately described by a "has-a" relationship, then consider making Bar a field of Foo instead.

## More Examples, with Annotations


### Example: header

=== "fibonacci.c header"

    ``` cpp linenums="1"
    
    /** ***************************************************************************
     * @remark computation and timing of elements of the Fibonnaci sequence       *
     *  using the basic recurisve formula for the sequence                        *
     *  with and without dynamic prog.                                            *
     *                                                                            *
     * @author Henry M. Walker                                                    *
     * @file  fibonacci.c                                                         *
     * @date  August 14, 2022                                                     *
     *                                                                            *
     * @remark References                                                         *
     * @remark Dynamic Programming:  Anany Levitin, "The Design and               *
     *         and Analysis of Algorithms", Second Edition,                       *
     *         Chapter 8:  Dynamic Programming                                    *
     * @remark Dynamic Programming:  Anany Levitin, "The Design and               *
     *         and Analysis of Algorithms", Second Edition,                       *
     *         Section 2.5:  Example: Computing the nth Fibonacci Number          *
     *                                                                            *
     * @remark People participating with Problem/Progra Discussions:              *
     *         None                                                               *
     *                                                                            *
     *****************************************************************************/

    
    #include <stdio.h>
    #include <time.h>     // for time
    
    ```

=== "Annotated"

    ``` cpp linenums="1"
    /** (1) ***********************************************************************
     * @remark (2) computation and timing of elements of the Fibonnaci sequence   *
     *  using the basic recurisve formula for the sequence                        *
     *  with and without dynamic prog.                                            *
     *                                                                            *
     * (4) @author  Henry M. Walker                                               *
     * @file  fibonacci.c                                                         *
     * @date  August 14, 2022                                                     *
     *                                                                            *
     * @remark (3) References                                                     *
     * @remark Dynamic Programming:  Anany Levitin, "The Design and               *
     *         and Analysis of Algorithms", Second Edition,                       *
     *         Chapter 8:  Dynamic Programming                                    *
     * @remark Dynamic Programming:  Anany Levitin, "The Design and               *
     *         and Analysis of Algorithms", Second Edition,                       *
     *         Section 2.5:  Example: Computing the nth Fibonacci Number          *
     *                                                                            *
     * @remark People participating with Problem/Progra Discussions:              *
     *         None                                                               *
     *                                                                            *
     *****************************************************************************/


    #include <stdio.h>
    #include <time.h>     // for time (5)
    ```

    1. `/**` designates the beginning of an annotation for use in Doxygen. Whitespace is needed after the second asterisk. If a line of astericks is desired at the start of a comment block, leave 1 space after the second asterisk before completing the line. Doxygen does not copy entire lines of asterisks (e.g., at the beginning or end of an annotation.) However, Doxygen does include individual asterisks within a line of text.
    2. The initial `@remark` tag identifies the purpose of program
    3. The `@remark` tag tells Doxygen that a comment follows.
        - The comment continues until a blank line or the next tag
        - If two or more `@remark` tags, commentary for each tag starts on a new line.
    4. The author, file, and date tags tell Doxygen to use specified labels and formatting
    5. Comment for `time.h` indicates the function motivating including this library


### Example: function

=== "fibSeq1()"

    ``` cpp linenums="26"
    
    /** ***************************************************************************
     * compute the nth fibonacci number directly,                                 *
     * using the recursive definition of the sequence                             *
     * @param  n:  the nth Fibonacci number to be computed                        *
     *              (starting the sequence at index 0)                            *
     * @pre   0 <= n                                                              *
     * @returns  the nth Fibonacci number                                         *
     *****************************************************************************/
    int fibSeq1(int n) {
      if (n <= 1 ) {
        return 1;
      }
      else {
        return fibSeq1 (n-1) + fibSeq1 (n-2);
      }
    }
    ```

=== "Annotated"

    ``` cpp linenums="26"
    
    /** **********************************************************************(1)**
     * (2) compute the nth fibonacci number directly,                             *
     * using the recursive definition of the sequence                             *
     * @param  n:  the nth Fibonacci number to be computed                        *
     *              (starting the sequence at index 0)                            *
     * @pre   0 <= n                                                              *
     * @returns  the nth Fibonacci number                                         *
     *****************************************************************************/
    int fibSeq1(int n) {
      if (n <= 1 ) {
        return 1; 
      } // (3)
      else {
        return fibSeq1 (n-1) + fibSeq1 (n-2);
      }
    }
    ```

    1.  The block for a function can combine two forms: use a rectangle of asterisks, in the style of a text box; leave a space after the second asterisk of the opening line, as required by Doxygen.
    2.  This function header identifies :material-numeric-1-circle-outline: purpose of function, :material-numeric-2-circle-outline: clarification of parameter `n` with a `@param` tag, :material-numeric-3-circle-outline: clarification of pre-condition for `n` with a `@pre` tag, :material-numeric-4-circle-outline: identification of value returned with a `@returns` tag
    3.  Although the `if` and `else` control only one statement, braces are still used for consistency and to ease the addition of additional statements later.


### Example: `main()`

=== "main()"

    ``` cpp linenums="79"

    /** ***************************************************************************
     * main procedure controls computation, timing, and printing                  *
     *****************************************************************************/
    int main ( ) {
      int reps = 100;  // number of times call repeated to help timings
      
      printf ("timing of two functions to compute the nth Fib number\n");
      printf ("    (each function call repeated %d times)\n", reps);
      printf ("               Approach 1          Approach 2\n");
      printf ("     n      Fib[n]     time    Fib[n]     time\n");
    
      // variables used for loops and timing
      int n;
      int value;
      clock_t start_time, end_time;
      double elapsed_time;
    
      for (n = 1; n <= 45; n += 4) {
        printf ("%6d", n);
    
        // time first approach
        start_time = clock ();
        for (int j = 0; j < reps; j++) {
          value = fibSeq1 (n);
        }
        end_time = clock();
        elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        printf ("%11d   %6.1lf", value, elapsed_time);
    
        // time second approach
        start_time = clock ();
        for (int k = 0; k < reps; k++) {
          value = fibSeq2 (n);
        }
        end_time = clock();
        elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        printf ("%11d   %6.1lf\n", value, elapsed_time);
      }
    }
    ```

=== "Annotated"

    ``` cpp linenums="79"
    
    /** ***************************************************************************
     * (1) main procedure controls computation, timing, and printing              *
     *****************************************************************************/
    int main ( ) {
      int reps = 100;  // number of times call repeated to help timings (2)
      
      printf ("timing of two functions to compute the nth Fib number\n");
      printf ("    (each function call repeated %d times)\n", reps);
      printf ("               Approach 1          Approach 2\n");
      printf ("     n      Fib[n]     time    Fib[n]     time\n"); // (3)
    
      // variables used for loops and timing
      int n;
      int value;
      clock_t start_time, end_time;
      double elapsed_time;
    
      for (n = 1; n <= 45; n += 4) {
        printf ("%6d", n);
    
        // time first approach (4)
        start_time = clock ();
        for (int j = 0; j < reps; j++) {
          value = fibSeq1 (n);
        }
        end_time = clock();
        elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        printf ("%11d   %6.1lf", value, elapsed_time);
    
        // time second approach (5)
        start_time = clock ();
        for (int k = 0; k < reps; k++) {
          value = fibSeq2 (n);
        }
        end_time = clock();
        elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        printf ("%11d   %6.1lf\n", value, elapsed_time);
      }
    }
    ```
    
    1. Initial comment identifies primary scope of the main procedure
    2. Comment for reps briefly describes purpose of variable
    3. Text within printf clarifies purpose of output -- no need to say more
    4. Comments identify a section of code which handles timing
    5. This section section of code is separated by white space and a comment, to highlight the two different blocks of logic handling timing

## Acknowledgments
Although the C/C++ Programming Language allows programmers to utilize a wide range of formatting conventions, C/C++ and Java programming cultures largely have settled upon several widely-adopted conventions. Although some style elements vary somewhat from one organization to another, elements in this style guide are derived from these primary sources:

- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html), (accessed April 29, 2022)
- [Google Java Style Guide](https://google.github.io/styleguide/javaguide.html)
- [Code Conventions for the Java Programming Language](https://www.oracle.com/technetwork/java/codeconvtoc-136057.html) (from Oracle, Revised April 20, 1999)
- [CIS 120](http://www.cis.upenn.edu/~cis120/) at the University of Pennsylvania.
- CSC 207 Java Style Guide by Peter-Michael Osera, Grinnell College.  
