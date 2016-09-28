# PA4: Object Loading

#Kurt Andersen

## Description
For this project we were instructed to write our own file loader.  The loader red a .obj file and loaded all the data properly in order to build the object contained within the file.  In this project I added random colors to every vertex to give my objects a fun look.  

# Dependencies, Building, and Running

## Dependency Instructions
For both of the operating systems to run this project installation of these three programs are required [GLEW](http://glew.sourceforge.net/), [GLM](http://glm.g-truc.net/0.9.7/index.html), and [SDL2](https://wiki.libsdl.org/Tutorials).

This project uses OpenGL 3.3. Some computers, such as virtual machines in the ECC, can not run this version. In in order to run OpenGL 2.7 follow the instructions at [Using OpenGL 2.7](https://github.com/HPC-Vis/computer-graphics/wiki/Using-OpenGL-2.7)

### Ubuntu/Linux
```bash
sudo apt-get install libglew-dev libglm-dev libsdl2-dev
```

### Mac OSX
Installation of brew is suggested to easily install the libs. Ensure that the latest version of the Developer Tools is installed.
```bash
brew install glew glm sdl2
```

## Building and Running
To build this project, be within the PA4 directory.  Once inside enter the following commands on the command line...
: mkdir build <br />
: cd build <br />
: cmake .. <br />
: make <br />

Now that the file is made, we will run the file.  To run the file input on the command line...
: ./Tutorial

Once the program begins click back into the command prompt and enter the name of the file you wish to use within the objects folder.  DO NOT add the .obj as it is taken care of within the code.  There are 3 objects that are included in the objects folder, which are box, pinball, and dragon.  Once the file name is input, reopen the window that was generated when the program was executed.


## Ubuntu.cse.unr.edu
OpenGL 3.3 will run on the [ubuntu.cse.unr.edu](https://ubuntu.cse.unr.edu/) website. To do so follow the build instructions, but when running the Tutorial executable use this line to execute.
```bash
/usr/NX/scripts/vgl/vglrun ./Tutorial
```
