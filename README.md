# laserThingConsole
 laserThingConsole
a console app that simulates a laser entering a 5 x 5 grid of spaces containing either a +45 degree mirror, a -45 degree mirror or no mirror indicated by backslashes and forwardslashes and zeroes(for no mirror).  User chooses an entrance port (0-19).  Output is exit port number (0-19).  Slashes are implied to be +45 and -45 degree angles for 90 degree reflections.  Placement of mirrors is customizable through gridPattern.txt.  Size of grid is not yet customizable and changes must follow exisiting text formatting.

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


NOTE: Depending on your build system, you may have to manually move gridPattern.txt from the build folder to wherver your build system put the binary.
