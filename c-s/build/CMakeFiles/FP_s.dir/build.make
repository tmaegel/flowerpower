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
CMAKE_SOURCE_DIR = /home/moe/workspace/FP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moe/workspace/FP/build

# Include any dependencies generated for this target.
include CMakeFiles/FP_s.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FP_s.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FP_s.dir/flags.make

CMakeFiles/FP_s.dir/FP_s.cpp.o: CMakeFiles/FP_s.dir/flags.make
CMakeFiles/FP_s.dir/FP_s.cpp.o: ../FP_s.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/moe/workspace/FP/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FP_s.dir/FP_s.cpp.o"
	/usr/bin/gcc-4.8   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FP_s.dir/FP_s.cpp.o -c /home/moe/workspace/FP/FP_s.cpp

CMakeFiles/FP_s.dir/FP_s.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FP_s.dir/FP_s.cpp.i"
	/usr/bin/gcc-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/moe/workspace/FP/FP_s.cpp > CMakeFiles/FP_s.dir/FP_s.cpp.i

CMakeFiles/FP_s.dir/FP_s.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FP_s.dir/FP_s.cpp.s"
	/usr/bin/gcc-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/moe/workspace/FP/FP_s.cpp -o CMakeFiles/FP_s.dir/FP_s.cpp.s

CMakeFiles/FP_s.dir/FP_s.cpp.o.requires:
.PHONY : CMakeFiles/FP_s.dir/FP_s.cpp.o.requires

CMakeFiles/FP_s.dir/FP_s.cpp.o.provides: CMakeFiles/FP_s.dir/FP_s.cpp.o.requires
	$(MAKE) -f CMakeFiles/FP_s.dir/build.make CMakeFiles/FP_s.dir/FP_s.cpp.o.provides.build
.PHONY : CMakeFiles/FP_s.dir/FP_s.cpp.o.provides

CMakeFiles/FP_s.dir/FP_s.cpp.o.provides.build: CMakeFiles/FP_s.dir/FP_s.cpp.o

CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o: CMakeFiles/FP_s.dir/flags.make
CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o: ../FP_S_to_DB.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/moe/workspace/FP/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o"
	/usr/bin/gcc-4.8   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o -c /home/moe/workspace/FP/FP_S_to_DB.cpp

CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.i"
	/usr/bin/gcc-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/moe/workspace/FP/FP_S_to_DB.cpp > CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.i

CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.s"
	/usr/bin/gcc-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/moe/workspace/FP/FP_S_to_DB.cpp -o CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.s

CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o.requires:
.PHONY : CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o.requires

CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o.provides: CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o.requires
	$(MAKE) -f CMakeFiles/FP_s.dir/build.make CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o.provides.build
.PHONY : CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o.provides

CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o.provides.build: CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o

# Object files for target FP_s
FP_s_OBJECTS = \
"CMakeFiles/FP_s.dir/FP_s.cpp.o" \
"CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o"

# External object files for target FP_s
FP_s_EXTERNAL_OBJECTS =

FP_s: CMakeFiles/FP_s.dir/FP_s.cpp.o
FP_s: CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o
FP_s: CMakeFiles/FP_s.dir/build.make
FP_s: libzeromq.a
FP_s: CMakeFiles/FP_s.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable FP_s"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FP_s.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FP_s.dir/build: FP_s
.PHONY : CMakeFiles/FP_s.dir/build

CMakeFiles/FP_s.dir/requires: CMakeFiles/FP_s.dir/FP_s.cpp.o.requires
CMakeFiles/FP_s.dir/requires: CMakeFiles/FP_s.dir/FP_S_to_DB.cpp.o.requires
.PHONY : CMakeFiles/FP_s.dir/requires

CMakeFiles/FP_s.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FP_s.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FP_s.dir/clean

CMakeFiles/FP_s.dir/depend:
	cd /home/moe/workspace/FP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moe/workspace/FP /home/moe/workspace/FP /home/moe/workspace/FP/build /home/moe/workspace/FP/build /home/moe/workspace/FP/build/CMakeFiles/FP_s.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FP_s.dir/depend

