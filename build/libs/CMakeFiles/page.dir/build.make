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
include libs/CMakeFiles/page.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/CMakeFiles/page.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/CMakeFiles/page.dir/progress.make

# Include the compile flags for this target's objects.
include libs/CMakeFiles/page.dir/flags.make

libs/CMakeFiles/page.dir/page.cpp.o: libs/CMakeFiles/page.dir/flags.make
libs/CMakeFiles/page.dir/page.cpp.o: /home/snobody04/projects/textEditor3/libs/page.cpp
libs/CMakeFiles/page.dir/page.cpp.o: libs/CMakeFiles/page.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/snobody04/projects/textEditor3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/CMakeFiles/page.dir/page.cpp.o"
	cd /home/snobody04/projects/textEditor3/build/libs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/CMakeFiles/page.dir/page.cpp.o -MF CMakeFiles/page.dir/page.cpp.o.d -o CMakeFiles/page.dir/page.cpp.o -c /home/snobody04/projects/textEditor3/libs/page.cpp

libs/CMakeFiles/page.dir/page.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/page.dir/page.cpp.i"
	cd /home/snobody04/projects/textEditor3/build/libs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/snobody04/projects/textEditor3/libs/page.cpp > CMakeFiles/page.dir/page.cpp.i

libs/CMakeFiles/page.dir/page.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/page.dir/page.cpp.s"
	cd /home/snobody04/projects/textEditor3/build/libs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/snobody04/projects/textEditor3/libs/page.cpp -o CMakeFiles/page.dir/page.cpp.s

# Object files for target page
page_OBJECTS = \
"CMakeFiles/page.dir/page.cpp.o"

# External object files for target page
page_EXTERNAL_OBJECTS =

libs/libpage.a: libs/CMakeFiles/page.dir/page.cpp.o
libs/libpage.a: libs/CMakeFiles/page.dir/build.make
libs/libpage.a: libs/CMakeFiles/page.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/snobody04/projects/textEditor3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libpage.a"
	cd /home/snobody04/projects/textEditor3/build/libs && $(CMAKE_COMMAND) -P CMakeFiles/page.dir/cmake_clean_target.cmake
	cd /home/snobody04/projects/textEditor3/build/libs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/page.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/CMakeFiles/page.dir/build: libs/libpage.a
.PHONY : libs/CMakeFiles/page.dir/build

libs/CMakeFiles/page.dir/clean:
	cd /home/snobody04/projects/textEditor3/build/libs && $(CMAKE_COMMAND) -P CMakeFiles/page.dir/cmake_clean.cmake
.PHONY : libs/CMakeFiles/page.dir/clean

libs/CMakeFiles/page.dir/depend:
	cd /home/snobody04/projects/textEditor3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/snobody04/projects/textEditor3 /home/snobody04/projects/textEditor3/libs /home/snobody04/projects/textEditor3/build /home/snobody04/projects/textEditor3/build/libs /home/snobody04/projects/textEditor3/build/libs/CMakeFiles/page.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libs/CMakeFiles/page.dir/depend

