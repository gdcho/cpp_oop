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
CMAKE_SOURCE_DIR = /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/functor_fun.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/functor_fun.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/functor_fun.dir/flags.make

CMakeFiles/functor_fun.dir/functor_fun.cpp.o: CMakeFiles/functor_fun.dir/flags.make
CMakeFiles/functor_fun.dir/functor_fun.cpp.o: ../functor_fun.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/functor_fun.dir/functor_fun.cpp.o"
	C:/cygwin64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/functor_fun.dir/functor_fun.cpp.o -c /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun/functor_fun.cpp

CMakeFiles/functor_fun.dir/functor_fun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/functor_fun.dir/functor_fun.cpp.i"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun/functor_fun.cpp > CMakeFiles/functor_fun.dir/functor_fun.cpp.i

CMakeFiles/functor_fun.dir/functor_fun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/functor_fun.dir/functor_fun.cpp.s"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun/functor_fun.cpp -o CMakeFiles/functor_fun.dir/functor_fun.cpp.s

# Object files for target functor_fun
functor_fun_OBJECTS = \
"CMakeFiles/functor_fun.dir/functor_fun.cpp.o"

# External object files for target functor_fun
functor_fun_EXTERNAL_OBJECTS =

functor_fun.exe: CMakeFiles/functor_fun.dir/functor_fun.cpp.o
functor_fun.exe: CMakeFiles/functor_fun.dir/build.make
functor_fun.exe: CMakeFiles/functor_fun.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable functor_fun.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/functor_fun.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/functor_fun.dir/build: functor_fun.exe

.PHONY : CMakeFiles/functor_fun.dir/build

CMakeFiles/functor_fun.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/functor_fun.dir/cmake_clean.cmake
.PHONY : CMakeFiles/functor_fun.dir/clean

CMakeFiles/functor_fun.dir/depend:
	cd /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun/cmake-build-debug /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun/cmake-build-debug /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week9/Day1Code/functor_fun/cmake-build-debug/CMakeFiles/functor_fun.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/functor_fun.dir/depend

