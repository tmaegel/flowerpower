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
CMAKE_SOURCE_DIR = /home/moe/workspace/fp_github/flowerpower/c-s

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moe/workspace/fp_github/flowerpower/c-s/build

# Include any dependencies generated for this target.
include CMakeFiles/FP_c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FP_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FP_c.dir/flags.make

CMakeFiles/FP_c.dir/FP_c.cpp.o: CMakeFiles/FP_c.dir/flags.make
CMakeFiles/FP_c.dir/FP_c.cpp.o: ../FP_c.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/moe/workspace/fp_github/flowerpower/c-s/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FP_c.dir/FP_c.cpp.o"
	/usr/bin/gcc-4.8   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FP_c.dir/FP_c.cpp.o -c /home/moe/workspace/fp_github/flowerpower/c-s/FP_c.cpp

CMakeFiles/FP_c.dir/FP_c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FP_c.dir/FP_c.cpp.i"
	/usr/bin/gcc-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/moe/workspace/fp_github/flowerpower/c-s/FP_c.cpp > CMakeFiles/FP_c.dir/FP_c.cpp.i

CMakeFiles/FP_c.dir/FP_c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FP_c.dir/FP_c.cpp.s"
	/usr/bin/gcc-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/moe/workspace/fp_github/flowerpower/c-s/FP_c.cpp -o CMakeFiles/FP_c.dir/FP_c.cpp.s

CMakeFiles/FP_c.dir/FP_c.cpp.o.requires:
.PHONY : CMakeFiles/FP_c.dir/FP_c.cpp.o.requires

CMakeFiles/FP_c.dir/FP_c.cpp.o.provides: CMakeFiles/FP_c.dir/FP_c.cpp.o.requires
	$(MAKE) -f CMakeFiles/FP_c.dir/build.make CMakeFiles/FP_c.dir/FP_c.cpp.o.provides.build
.PHONY : CMakeFiles/FP_c.dir/FP_c.cpp.o.provides

CMakeFiles/FP_c.dir/FP_c.cpp.o.provides.build: CMakeFiles/FP_c.dir/FP_c.cpp.o

CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o: CMakeFiles/FP_c.dir/flags.make
CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o: /home/moe/workspace/fp_github/flowerpower/db/database.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/moe/workspace/fp_github/flowerpower/c-s/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o"
	/usr/bin/gcc-4.8  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o   -c /home/moe/workspace/fp_github/flowerpower/db/database.c

CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.i"
	/usr/bin/gcc-4.8  $(C_DEFINES) $(C_FLAGS) -E /home/moe/workspace/fp_github/flowerpower/db/database.c > CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.i

CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.s"
	/usr/bin/gcc-4.8  $(C_DEFINES) $(C_FLAGS) -S /home/moe/workspace/fp_github/flowerpower/db/database.c -o CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.s

CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o.requires:
.PHONY : CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o.requires

CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o.provides: CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o.requires
	$(MAKE) -f CMakeFiles/FP_c.dir/build.make CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o.provides.build
.PHONY : CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o.provides

CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o.provides.build: CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o

# Object files for target FP_c
FP_c_OBJECTS = \
"CMakeFiles/FP_c.dir/FP_c.cpp.o" \
"CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o"

# External object files for target FP_c
FP_c_EXTERNAL_OBJECTS =

FP_c: CMakeFiles/FP_c.dir/FP_c.cpp.o
FP_c: CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o
FP_c: CMakeFiles/FP_c.dir/build.make
FP_c: libzeromq.a
FP_c: CMakeFiles/FP_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable FP_c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FP_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FP_c.dir/build: FP_c
.PHONY : CMakeFiles/FP_c.dir/build

CMakeFiles/FP_c.dir/requires: CMakeFiles/FP_c.dir/FP_c.cpp.o.requires
CMakeFiles/FP_c.dir/requires: CMakeFiles/FP_c.dir/home/moe/workspace/fp_github/flowerpower/db/database.c.o.requires
.PHONY : CMakeFiles/FP_c.dir/requires

CMakeFiles/FP_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FP_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FP_c.dir/clean

CMakeFiles/FP_c.dir/depend:
	cd /home/moe/workspace/fp_github/flowerpower/c-s/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moe/workspace/fp_github/flowerpower/c-s /home/moe/workspace/fp_github/flowerpower/c-s /home/moe/workspace/fp_github/flowerpower/c-s/build /home/moe/workspace/fp_github/flowerpower/c-s/build /home/moe/workspace/fp_github/flowerpower/c-s/build/CMakeFiles/FP_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FP_c.dir/depend

