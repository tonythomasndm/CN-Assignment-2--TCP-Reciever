# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/byte_stream_construction.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/byte_stream_construction.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/byte_stream_construction.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/byte_stream_construction.dir/flags.make

tests/CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.o: tests/CMakeFiles/byte_stream_construction.dir/flags.make
tests/CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.o: /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/tests/byte_stream_construction.cc
tests/CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.o: tests/CMakeFiles/byte_stream_construction.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.o"
	cd /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.o -MF CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.o.d -o CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.o -c /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/tests/byte_stream_construction.cc

tests/CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.i"
	cd /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/tests/byte_stream_construction.cc > CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.i

tests/CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.s"
	cd /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/tests/byte_stream_construction.cc -o CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.s

# Object files for target byte_stream_construction
byte_stream_construction_OBJECTS = \
"CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.o"

# External object files for target byte_stream_construction
byte_stream_construction_EXTERNAL_OBJECTS =

tests/byte_stream_construction: tests/CMakeFiles/byte_stream_construction.dir/byte_stream_construction.cc.o
tests/byte_stream_construction: tests/CMakeFiles/byte_stream_construction.dir/build.make
tests/byte_stream_construction: tests/libtcp_reciever_checks.a
tests/byte_stream_construction: src/libtcp_reciever.a
tests/byte_stream_construction: tests/CMakeFiles/byte_stream_construction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable byte_stream_construction"
	cd /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/byte_stream_construction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/byte_stream_construction.dir/build: tests/byte_stream_construction
.PHONY : tests/CMakeFiles/byte_stream_construction.dir/build

tests/CMakeFiles/byte_stream_construction.dir/clean:
	cd /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/byte_stream_construction.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/byte_stream_construction.dir/clean

tests/CMakeFiles/byte_stream_construction.dir/depend:
	cd /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2 /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/tests /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build/tests /home/tonythomasndm/cn-assignment/cn-assignment2/2021360-TonyThomas-Assignment2/build/tests/CMakeFiles/byte_stream_construction.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/byte_stream_construction.dir/depend

