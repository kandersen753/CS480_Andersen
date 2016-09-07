# PA1: Spinning Cube

# Kurt Andersen
#CS 480

For this project, we were required to take the existing spinning cube, then make it orbit around the origin of our field of view, and keep the cube itself rotating.

We were also required to make the shaders load from file. The way I handled the shaders is, I changed the function call for the shaders themselves. When the function is called, it is called with the shader type, as well as the file path for the particular shader.

When I changed the path of the cube, I origially had the functions rotate * translate.  After some confusion I adjusted the functions to go translate * rotate.

In order to run this project, change directories into the build directory.  From there in the command line input : > make clean; make
then once the build is complete, input : > ./Tutorial

When the program runs, the window name will contain my name "Kurt Andersen"
