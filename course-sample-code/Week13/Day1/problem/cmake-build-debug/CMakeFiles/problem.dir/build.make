# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /cygdrive/c/Users/A00257049/.CLion2018.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/A00257049/.CLion2018.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/problem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/problem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/problem.dir/flags.make

CMakeFiles/problem.dir/problem.cpp.o: CMakeFiles/problem.dir/flags.make
CMakeFiles/problem.dir/problem.cpp.o: ../problem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/problem.dir/problem.cpp.o"
	C:/cygwin64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/problem.dir/problem.cpp.o -c /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem/problem.cpp

CMakeFiles/problem.dir/problem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem.dir/problem.cpp.i"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem/problem.cpp > CMakeFiles/problem.dir/problem.cpp.i

CMakeFiles/problem.dir/problem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem.dir/problem.cpp.s"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem/problem.cpp -o CMakeFiles/problem.dir/problem.cpp.s

# Object files for target problem
problem_OBJECTS = \
"CMakeFiles/problem.dir/problem.cpp.o"

# External object files for target problem
problem_EXTERNAL_OBJECTS =

problem.exe: CMakeFiles/problem.dir/problem.cpp.o
problem.exe: CMakeFiles/problem.dir/build.make
problem.exe: CMakeFiles/problem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable problem.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/problem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/problem.dir/build: problem.exe

.PHONY : CMakeFiles/problem.dir/build

CMakeFiles/problem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/problem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/problem.dir/clean

CMakeFiles/problem.dir/depend:
	cd /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem/cmake-build-debug /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem/cmake-build-debug /cygdrive/c/Users/A00257049/CLionProjects/COMP3522Fall2020/Week12/Week12Day2Code/problem/cmake-build-debug/CMakeFiles/problem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/problem.dir/depend

