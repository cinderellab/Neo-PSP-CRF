# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xduser/lihuan/lbplib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xduser/lihuan/lbplib/build

# Include any dependencies generated for this target.
include CMakeFiles/opencv_lbp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opencv_lbp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opencv_lbp.dir/flags.make

CMakeFiles/opencv_lbp.dir/test.cpp.o: CMakeFiles/opencv_lbp.dir/flags.make
CMakeFiles/opencv_lbp.dir/test.cpp.o: ../test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xduser/lihuan/lbplib/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/opencv_lbp.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_lbp.dir/test.cpp.o -c /home/xduser/lihuan/lbplib/test.cpp

CMakeFiles/opencv_lbp.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_lbp.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xduser/lihuan/lbplib/test.cpp > CMakeFiles/opencv_lbp.dir/test.cpp.i

CMakeFiles/opencv_lbp.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_lbp.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xduser/lihuan/lbplib/test.cpp -o CMakeFiles/opencv_lbp.dir/test.cpp.s

CMakeFiles/opencv_lbp.dir/test.cpp.o.requires:
.PHONY : CMakeFiles/opencv_lbp.dir/test.cpp.o.requires

CMakeFiles/opencv_lbp.dir/test.cpp.o.provides: CMakeFiles/opencv_lbp.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/opencv_lbp.dir/build.make CMakeFiles/opencv_lbp.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/opencv_lbp.dir/test.cpp.o.provides

CMakeFiles/opencv_lbp.dir/test.cpp.o.provides.build: CMakeFiles/opencv_lbp.dir/test.cpp.o

# Object files for target opencv_lbp
opencv_lbp_OBJECTS = \
"CMakeFiles/opencv_lbp.dir/test.cpp.o"

# External object files for target opencv_lbp
opencv_lbp_EXTERNAL_OBJECTS =

libopencv_lbp.a: CMakeFiles/opencv_lbp.dir/test.cpp.o
libopencv_lbp.a: CMakeFiles/opencv_lbp.di