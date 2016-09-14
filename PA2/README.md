# PA2: Keyboard Input

# Kurt Andersen
#CS 480

#Project Description
For this project we were required to take the files from project 1, and add keyboard input into it.  We were assigned to map keys to switch the direction of the objects translation and rotation, keys to seperately freeze the rotation or translation, and keys to freeze both the translation and rotation.  At least one of these sets had to be mapped to the mouse buttons.

#Build and Run Instructions
In order to run this project, change directories into the  project directory.  Once within the project directory, enter on the command line: <br />
: mkdir build <br />
: cd build <br />
: cmake .. <br />
: make <br />
: ./Tutorial <br />

following those steps will create a folder that will hold the binary files and the executables for the program.  cmake runs a script that generates a make file for the project directory.  make will compile all of the files and create the executable.  The executable file is saved as "Tutorial"

When the program runs, the window name will contain my name "Kurt Andersen"

#Keyboard Inputs List
'q' - clockwise translation <br />
'w' - counterclockwise translation <br />
'a' - clockwise rotation <br />
's' - counterclockwise rotation <br />
'z' - freeze rotation <br />
'x' - restore rotation <br />
'c' - freeze translation <br />
'v' - restore translation <br />
left mouse button - freeze translation and rotation <br />
right mouse button - restore translation and rotation <br />