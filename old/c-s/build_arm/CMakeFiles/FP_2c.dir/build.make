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
CMAKE_SOURCE_DIR = /home/pi/flowerpower/c-s

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/flowerpower/c-s/build_arm

# Include any dependencies generated for this target.
include CMakeFiles/FP_2c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FP_2c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FP_2c.dir/flags.make

CMakeFiles/FP_2c.dir/FP_2c.cpp.o: CMakeFiles/FP_2c.dir/flags.make
CMakeFiles/FP_2c.dir/FP_2c.cpp.o: ../FP_2c.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/flowerpower/c-s/build_arm/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FP_2c.dir/FP_2c.cpp.o"
	/usr/bin/gcc   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FP_2c.dir/FP_2c.cpp.o -c /home/pi/flowerpower/c-s/FP_2c.cpp

CMakeFiles/FP_2c.dir/FP_2c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FP_2c.dir/FP_2c.cpp.i"
	/usr/bin/gcc  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/flowerpower/c-s/FP_2c.cpp > CMakeFiles/FP_2c.dir/FP_2c.cpp.i

CMakeFiles/FP_2c.dir/FP_2c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FP_2c.dir/FP_2c.cpp.s"
	/usr/bin/gcc  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/flowerpower/c-s/FP_2c.cpp -o CMakeFiles/FP_2c.dir/FP_2c.cpp.s

CMakeFiles/FP_2c.dir/FP_2c.cpp.o.requires:
.PHONY : CMakeFiles/FP_2c.dir/FP_2c.cpp.o.requires

CMakeFiles/FP_2c.dir/FP_2c.cpp.o.provides: CMakeFiles/FP_2c.dir/FP_2c.cpp.o.requires
	$(MAKE) -f CMakeFiles/FP_2c.dir/build.make CMakeFiles/FP_2c.dir/FP_2c.cpp.o.provides.build
.PHONY : CMakeFiles/FP_2c.dir/FP_2c.cpp.o.provides

CMakeFiles/FP_2c.dir/FP_2c.cpp.o.provides.build: CMakeFiles/FP_2c.dir/FP_2c.cpp.o

# Object files for target FP_2c
FP_2c_OBJECTS = \
"CMakeFiles/FP_2c.dir/FP_2c.cpp.o"

# External object files for target FP_2c
FP_2c_EXTERNAL_OBJECTS =

FP_2c: CMakeFiles/FP_2c.dir/FP_2c.cpp.o
FP_2c: CMakeFiles/FP_2c.dir/build.make
FP_2c: libzeromq.a
FP_2c: CMakeFiles/FP_2c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable FP_2c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FP_2c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FP_2c.dir/build: FP_2c
.PHONY : CMakeFiles/FP_2c.dir/build

CMakeFiles/FP_2c.dir/requires: CMakeFiles/FP_2c.dir/FP_2c.cpp.o.requires
.PHONY : CMakeFiles/FP_2c.dir/requires

CMakeFiles/FP_2c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FP_2c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FP_2c.dir/clean

CMakeFiles/FP_2c.dir/depend:
	cd /home/pi/flowerpower/c-s/build_arm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/flowerpower/c-s /home/pi/flowerpower/c-s /home/pi/flowerpower/c-s/build_arm /home/pi/flowerpower/c-s/build_arm /home/pi/flowerpower/c-s/build_arm/CMakeFiles/FP_2c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FP_2c.dir/depend

