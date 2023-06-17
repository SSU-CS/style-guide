# Tutorials

## Using Doxygen with graphviz

This tutorial provides streamlined instructions to create both html and LaTeX documentation for a basic C or C++ program or package. Thus, this page should be considered a guide to get started with Doxygen. Beyond these instructions, the Doxygen software system provides numerous features for generating software software that allow considerable tailoring of input and output. Overall, learning all options can require much time and effort, but this document can help you get started.

### Basic Steps for Using Doxygen with graphviz
Typically, production of basic documentation with Doxygen follows four steps:

1. Prepare the C/C++ source code with comments holding annotations and documentation;
2. Run Doxygen using the C/C++ files as inputs, producing `.html` and/or `.tex` files as outputs;
3. Generate a pdf file by running LaTeX on the `.tex` files;
4. Generate graphics for calling diagrams, class hierarchies, and file dependencies.

### 1. Prepare the Source Code
As you write your C/C++ code, follow the [SSU Style Guide](../cpp), especially:

- Use the file extension `.h` for header files, `.c` for C code, `.cpp` for C++ code, and `.tcc` for C++ template files

- Doxygen annotations employ a special comment convention: use `/**`, followed by whitespace, at the start of a comment preceding a function, and use `*/` at the end of the comment.

- Within a Doxygen comment (starting with `/**`), use:
     - `@param` to identify function parameters
     - `@pre` so happy to see all of for pre-conditions
     - `@returns` to describe what a function returns.
     - `@remark` to begin a note that should begin on a line by itself.

    !!! info

        The annotations listed above likely are adequate to get started, although [the Doxygen Manual on "Documenting the code"](https://www.doxygen.nl/manual/docblocks.html) describes many more details that can further improve the generated documentation.

- To simplify working with Doxygen, copy all the annotated project files into a separate directory. That directory, which we will refer to as the _working directory_, should contain the `.h`, `.c`, `.cpp` and `.tcc` files for the software package, but no other files (e.g., no files for other projects).

    !!! warning

        Be sure the working directory holds the actual files, since Doxygen may lose some functionality with symbolic links.


### 2. Run Doxygen
Doxygen can be run from the command-line or using a GUI. This tutorial is written relative to the Doxygen GUI front-end on Mac OS X. Start Doxygen by double-clicking the Doxygen.app in the Applications directory. Then, note several elements of the first screen when Doxygen opens its graphical interface:

- The top line contains a space to identify a "working directory"
- The left panel contains links for "Project", "Mode", "Output", and "Diagrams"
- The right panel has titles "Wizard", "Expert", and "Run", together with several lines to be completed

The next steps in these instructions go through these elements step-by-step.

1. Complete the first page on "Project" page in Doxygen's Wizard:

    - The first line on the "Project" page asks, "Specify the working directory from which doxygen will run". Use the "Select" button to navigate to the Working Directory containing the program(s) for this project.
    - The first blanks on the right ask for the "Project Name" and "Project synopsis". These two lines will form the title and opening description of the documentation to be produced.
    - The Project version and logo are optional fields--fill in these blanks or not (as you wish).
    - Although Doxygen allows flexibility in the location of the source code and the placement of the document, in basic programming the "working directory" can be used for both the "Source code directory" and the "Destination directory". (If not set explicitly, these may default to the "working directory".)
    - Once these fields for the "Project" screen are completed, use the "next" button to continue.

2. Doxygen's next page clarifies the "Mode" for generating document.

    - In the top section, the default, "Documented entities only", often can be used; However, if the resulting documentation does not show function information, change this setting to "All Entries"!
    - In the bottom section, check the optimization option for the language used in your program(s) (either C++ or C/PHP).
    - Once these fields for the "Mode" screen are completed, use the "next" button to continue.

3. The next page identifies the type of output desired.

    - Typically, the defaults for both "plain HTML" and "LaTeX" can be accepted.
    - After specifying the "Output" screen, click "next" to continue.

4. The next page may identify the type of "diagrams to generate", although doxygen sometimes may skip this step.

    - Typically, the defaults can be accepted.
    - After specifying the "Diagrams" screen, click "next" to continue.

5. The "Run" screen appears next.

    - Click "Run doxygen". Doxygen will print progress notifications in the designated box.
        - If the "run doxygen" button is grayed out, use the "File" at the top of the screen, and use the "save as" option to save a file called "Doxygen" to the working directory.
        - If the "run doxygen" button is active, click it, and review the progress box. If you find an "Error" that a configuration file was not found, run doxygen again.

    - When complete, a note, "***Doxygen has finished" appears. When no errors appear in the progress box (and many lines appear saying "Generating ..."), the documentation has been produced
        - Check your working directory for the `html/` and `latex/` directories. 
        - Opening `html/index.html` in a browser should display the program documentation.


### 3. Generate a pdf file
The LaTeX documentation system is a widely-used package designed for mathematical typesetting. Doxygen normally generates a `latex/` directory that contains numerous files in LaTeX format. 
    
!!! note

    These instructions assume that you have the LaTeX utilities already installed. If not, several free versions are available. Try a Web search for "LaTeX" and your type of computer. For example, "latex Mac OS X" should identify the TexShop package which is widely available at no cost.

In a terminal window, go the `latex/` directory, and check the file `refman.tex` is present. You can generate the `refman.pdf` using the command:

```
make
```

The document `refman.pdf` should contain the full project documentation as a single, multi-page _reference manual_.


### 4. Generate graphics
One step of the Doxygen wizard involves Diagrams. This allows you to generate graphics for calling diagrams, class hierarchies, and file dependencies

Within the "Diagrams" section of the Doxygen wizard:

 - Click the option for "Use Dot tool from the GraphViz package Dot graphs to generate". This will selected several graph options.
 - In addition, click the options "Call graphs" and "Called by graphs".

At this point, all graphical options will be set. With this option, moving to the "Run" tab allows one to click "Run doxygen" as before.

 - If this process runs smoothly, with no error reported, then the full documentation is ready, and nothing more need be done.
 - If "Run doxygen" generates an error like "dot not found", the underlying issue often is that doxygen cannot find the graphviz package (even if graphviz is installed). This issue is resolved by configuring Doxygen to specify the location of the `dot` utility (see below).


#### Specify the location of the `dot` utility

 - Within Doxygen, move to the "File" option at the top of the page and select "Save". This saves a configuration in the working directory for project.

 - Within a terminal window, use the following command to determine where the "dot" program is located:

    ```
    whereis dot
    ```
        
    (On my machine, this is `/usr/local/bin/dot` but another possibility might be `/usr/bin/dot`, etc. If no path is returned, you may need to reinstall graphviz!

 - Use an editor to open that Doxygen file and search for the line

    ```
    DOT_PATH   =
    ```
    Then, insert the path where `dot` was located, such as

    ```
    DOT_PATH               = /usr/local/bin/dot
    ```
            
 - Also, check that HAVE_DOT is set to YES:

    ```
    HAVE_DOT               = YES
    ```

 - After saving the edited file, go back to the file menu of Doxygen, and open the Doxygen file that has just been edited.

 - With this editing complete, try running Doxygen again on your project. With luck, all will proceed smoothly.


### Further Reading
- [Doxygen home page](https://www.doxygen.nl/index.html)
- [Overview of the Doxygen Manual](https://www.doxygen.nl/manual/index.html)
- [Special Commands in Doxygen](https://www.doxygen.nl/manual/commands.html#cmdmainpage)
