
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
CMAKE_SOURCE_DIR = /home/xduser/lihuan/cnpy-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xduser/lihuan/cnpy-master/build

# Include any dependencies generated for this target.
include CMakeFiles/cnpy-static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cnpy-static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cnpy-static.dir/flags.make

CMakeFiles/cnpy-static.dir/cnpy.cpp.o: CMakeFiles/cnpy-static.dir/flags.make
CMakeFiles/cnpy-static.dir/cnpy.cpp.o: ../cnpy.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xduser/lihuan/cnpy-master/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/cnpy-static.dir/cnpy.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cnpy-static.dir/cnpy.cpp.o -c /home/xduser/lihuan/cnpy-master/cnpy.cpp

CMakeFiles/cnpy-static.dir/cnpy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cnpy-static.dir/cnpy.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xduser/lihuan/cnpy-master/cnpy.cpp > CMakeFiles/cnpy-static.dir/cnpy.cpp.i

CMakeFiles/cnpy-static.dir/cnpy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cnpy-static.dir/cnpy.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xduser/lihuan/cnpy-master/cnpy.cpp -o CMakeFiles/cnpy-static.dir/cnpy.cpp.s

CMakeFiles/cnpy-static.dir/cnpy.cpp.o.requires:
.PHONY : CMakeFiles/cnpy-static.dir/cnpy.cpp.o.requires

CMakeFiles/cnpy-static.dir/cnpy.cpp.o.provides: CMakeFiles/cnpy-static.dir/cnpy.cpp.o.requires
	$(MAKE) -f CMakeFiles/cnpy-static.dir/build.make CMakeFiles/cnpy-static.dir/cnpy.cpp.o.provides.build
.PHONY : CMakeFiles/cnpy-static.dir/cnpy.cpp.o.provides

CMakeFiles/cnpy-static.dir/cnpy.cpp.o.provides.build: CMakeFiles/cnpy-static.dir/cnpy.cpp.o

# Object files for target cnpy-static
cnpy__static_OBJECTS = \
"CMakeFiles/cnpy-static.dir/cnpy.cpp.o"

# External object files for target cnpy-static
cnpy__static_EXTERNAL_OBJECTS =

libcnpy.a: CMakeFiles/cnpy-static.dir/cnpy.cpp.o
libcnpy.a: CMakeFiles/cnpy-static.dir/build.make
libcnpy.a: CMakeFiles/cnpy-static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libcnpy.a"
	$(CMAKE_COMMAND) -P CMakeFiles/cnpy-static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cnpy-static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cnpy-static.dir/build: libcnpy.a
.PHONY : CMakeFiles/cnpy-static.dir/build

CMakeFiles/cnpy-static.dir/requires: CMakeFiles/cnpy-static.dir/cnpy.cpp.o.requires
.PHONY : CMakeFiles/cnpy-static.dir/requires

CMakeFiles/cnpy-static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cnpy-static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cnpy-static.dir/clean

CMakeFiles/cnpy-static.dir/depend:
	cd /home/xduser/lihuan/cnpy-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xduser/lihuan/cnpy-master /home/xduser/lihuan/cnpy-master /home/xduser/lihuan/cnpy-master/build /home/xduser/lihuan/cnpy-master/build /home/xduser/lihuan/cnpy-master/build/CMakeFiles/cnpy-static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cnpy-static.dir/depend
