# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/snobody04/projects/textEditor3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/snobody04/projects/textEditor3/build

# Include any dependencies generated for this target.
include libs/CMakeFiles/stringDoublyLinkedList.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/CMakeFiles/stringDoublyLinkedList.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/CMakeFiles/stringDoublyLinkedList.dir/progress.make

# Include the compile flags for this target's objects.
include libs/CMakeFiles/stringDoublyLinkedList.dir/flags.make

libs/CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.o: libs/CMakeFiles/stringDoublyLinkedList.dir/flags.make
libs/CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.o: /home/snobody04/projects/textEditor3/libs/stringDoublyLinkedList.cpp
libs/CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.o: libs/CMakeFiles/stringDoublyLinkedList.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/snobody04/projects/textEditor3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.o"
	cd /home/snobody04/projects/textEditor3/build/libs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.o -MF CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.o.d -o CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.o -c /home/snobody04/projects/textEditor3/libs/stringDoublyLinkedList.cpp

libs/CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.i"
	cd /home/snobody04/projects/textEditor3/build/libs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/snobody04/projects/textEditor3/libs/stringDoublyLinkedList.cpp > CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.i

libs/CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.s"
	cd /home/snobody04/projects/textEditor3/build/libs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/snobody04/projects/textEditor3/libs/stringDoublyLinkedList.cpp -o CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.s

# Object files for target stringDoublyLinkedList
stringDoublyLinkedList_OBJECTS = \
"CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.o"

# External object files for target stringDoublyLinkedList
stringDoublyLinkedList_EXTERNAL_OBJECTS =

libs/libstringDoublyLinkedList.a: libs/CMakeFiles/stringDoublyLinkedList.dir/stringDoublyLinkedList.cpp.o
libs/libstringDoublyLinkedList.a: libs/CMakeFiles/stringDoublyLinkedList.dir/build.make
libs/libstringDoublyLinkedList.a: libs/CMakeFiles/stringDoublyLinkedList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/snobody04/projects/textEditor3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libstringDoublyLinkedList.a"
	cd /home/snobody04/projects/textEditor3/build/libs && $(CMAKE_COMMAND) -P CMakeFiles/stringDoublyLinkedList.dir/cmake_clean_target.cmake
	cd /home/snobody04/projects/textEditor3/build/libs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stringDoublyLinkedList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/CMakeFiles/stringDoublyLinkedList.dir/build: libs/libstringDoublyLinkedList.a
.PHONY : libs/CMakeFiles/stringDoublyLinkedList.dir/build

libs/CMakeFiles/stringDoublyLinkedList.dir/clean:
	cd /home/snobody04/projects/textEditor3/build/libs && $(CMAKE_COMMAND) -P CMakeFiles/stringDoublyLinkedList.dir/cmake_clean.cmake
.PHONY : libs/CMakeFiles/stringDoublyLinkedList.dir/clean

libs/CMakeFiles/stringDoublyLinkedList.dir/depend:
	cd /home/snobody04/projects/textEditor3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/snobody04/projects/textEditor3 /home/snobody04/projects/textEditor3/libs /home/snobody04/projects/textEditor3/build /home/snobody04/projects/textEditor3/build/libs /home/snobody04/projects/textEditor3/build/libs/CMakeFiles/stringDoublyLinkedList.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libs/CMakeFiles/stringDoublyLinkedList.dir/depend

