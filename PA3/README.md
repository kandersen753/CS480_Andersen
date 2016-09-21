# PA2: Keyboard Input

# Kurt Andersen
#CS 480

#Project Description
For this project we were required to take the files from project 2, and add a moon to orbit the planet. Keyboard inputs were altered from project 2.  The arrow keys now change the rotation and translation of the planet.  See input list for full mapping.  The moon buttons will have the same interactions as the planet, i.e. changing rotation or translation direction or freezing translation or rotation.

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
'q' - moon counterclockwise rotation <br />
'w' - moon clockwise rotation <br />
'e' - moon freeze rotation<br />
'r' - moon restore rotation<br />
'a' - moon clockwise translation <br />
's' - moon counterclockwise translation <br />
'd' - moon freeze translation<br />
'f' - moon restore translation<br />
'z' - freeze planet rotation <br />
'x' - restore planet rotation <br />
'c' - freeze planet translation <br />
'v' - restore planet translation <br />
left arrow - planet counterclockwise rotation<br />
right arrow - planet clockwise rotation <br />
up arrow - planet clockwise translation<br />
down arrow - planet counterclockwise translation<br />
left mouse button - freeze both translation and rotation <br />
right mouse button - restore both translation and rotation <br />