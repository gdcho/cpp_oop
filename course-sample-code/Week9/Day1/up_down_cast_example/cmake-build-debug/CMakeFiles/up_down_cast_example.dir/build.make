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
CMAKE_SOURCE_DIR = /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/up_down_cast_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/up_down_cast_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/up_down_cast_example.dir/flags.make

CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.o: CMakeFiles/up_down_cast_example.dir/flags.make
CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.o: ../up_down_cast_example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.o"
	C:/cygwin64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.o -c /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example/up_down_cast_example.cpp

CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.i"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example/up_down_cast_example.cpp > CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.i

CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.s"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example/up_down_cast_example.cpp -o CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.s

# Object files for target up_down_cast_example
up_down_cast_example_OBJECTS = \
"CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.o"

# External object files for target up_down_cast_example
up_down_cast_example_EXTERNAL_OBJECTS =

up_down_cast_example.exe: CMakeFiles/up_down_cast_example.dir/up_down_cast_example.cpp.o
up_down_cast_example.exe: CMakeFiles/up_down_cast_example.dir/build.make
up_down_cast_example.exe: CMakeFiles/up_down_cast_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable up_down_cast_example.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/up_down_cast_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/up_down_cast_example.dir/build: up_down_cast_example.exe

.PHONY : CMakeFiles/up_down_cast_example.dir/build

CMakeFiles/up_down_cast_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/up_down_cast_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/up_down_cast_example.dir/clean

CMakeFiles/up_down_cast_example.dir/depend:
	cd /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example/cmake-build-debug /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example/cmake-build-debug /cygdrive/c/Users/A00257049/CLionProjects/COMP3512Winter/Week8/Week8Day1Code/up_down_cast_example/cmake-build-debug/CMakeFiles/up_down_cast_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/up_down_cast_example.dir/depend

