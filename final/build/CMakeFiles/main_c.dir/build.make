# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/toni/Downloads/flowerpower-clone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/toni/Downloads/flowerpower-clone/build

# Include any dependencies generated for this target.
include CMakeFiles/main_c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_c.dir/flags.make

CMakeFiles/main_c.dir/main_c.cpp.o: CMakeFiles/main_c.dir/flags.make
CMakeFiles/main_c.dir/main_c.cpp.o: ../main_c.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/toni/Downloads/flowerpower-clone/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main_c.dir/main_c.cpp.o"
	/usr/bin/gcc   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main_c.dir/main_c.cpp.o -c /home/toni/Downloads/flowerpower-clone/main_c.cpp

CMakeFiles/main_c.dir/main_c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_c.dir/main_c.cpp.i"
	/usr/bin/gcc  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/toni/Downloads/flowerpower-clone/main_c.cpp > CMakeFiles/main_c.dir/main_c.cpp.i

CMakeFiles/main_c.dir/main_c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_c.dir/main_c.cpp.s"
	/usr/bin/gcc  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/toni/Downloads/flowerpower-clone/main_c.cpp -o CMakeFiles/main_c.dir/main_c.cpp.s

CMakeFiles/main_c.dir/main_c.cpp.o.requires:
.PHONY : CMakeFiles/main_c.dir/main_c.cpp.o.requires

CMakeFiles/main_c.dir/main_c.cpp.o.provides: CMakeFiles/main_c.dir/main_c.cpp.o.requires
	$(MAKE) -f CMakeFiles/main_c.dir/build.make CMakeFiles/main_c.dir/main_c.cpp.o.provides.build
.PHONY : CMakeFiles/main_c.dir/main_c.cpp.o.provides

CMakeFiles/main_c.dir/main_c.cpp.o.provides.build: CMakeFiles/main_c.dir/main_c.cpp.o

# Object files for target main_c
main_c_OBJECTS = \
"CMakeFiles/main_c.dir/main_c.cpp.o"

# External object files for target main_c
main_c_EXTERNAL_OBJECTS =

main_c: CMakeFiles/main_c.dir/main_c.cpp.o
main_c: CMakeFiles/main_c.dir/build.make
main_c: /usr/lib/libm.so.6
main_c: /usr/lib/libmysqlclient.so
main_c: libzeromq.a
main_c: CMakeFiles/main_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable main_c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_c.dir/build: main_c
.PHONY : CMakeFiles/main_c.dir/build

CMakeFiles/main_c.dir/requires: CMakeFiles/main_c.dir/main_c.cpp.o.requires
.PHONY : CMakeFiles/main_c.dir/requires

CMakeFiles/main_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_c.dir/clean

CMakeFiles/main_c.dir/depend:
	cd /home/toni/Downloads/flowerpower-clone/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/toni/Downloads/flowerpower-clone /home/toni/Downloads/flowerpower-clone /home/toni/Downloads/flowerpower-clone/build /home/toni/Downloads/flowerpower-clone/build /home/toni/Downloads/flowerpower-clone/build/CMakeFiles/main_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_c.dir/depend

