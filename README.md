# laserThingConsole
 laserThingConsole
a console app that simulates a laser entering a grid of spaces containing either a +45 degree mirror, a -45 degree mirror or no mirror indicated by backslashes and forwardslashes and zeroes(for no mirror).  User chooses an entrance port number.  Output is exit port number.  Slashes are implied to be +45 and -45 degree angles for 90 degree reflections.  Placement of mirrors is customizable through text files formatted in the manner of the exisiting text files.  Size of grid is customizable and user can use their own custom text files by adding the path as a command-line arg.  Grid size will change according to grid size in text file.

# Requirements for building
On Windows, you need CMake and Visual Studio including the C++ build tools or another compatible build system and other C++ compiler.  
On Linux, you need CMake, GNU make or other compatible build system, g++ or other C++ compiler

# Build instructions

Install CMake on whatever platform you're on


Clone repository with Git or download zip and extract


From cloned repository or extracted zip folder in cmd/terminal:

cd build

cmake ..

cmake --build .


NOTE: Depending on your build system, you may have to manually move gridPattern.txt(the default if no path given at invocation) from the repo's root folder to the parent folder of the binary.
