# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab3template.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab3template.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab3template.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab3template.dir/flags.make

CMakeFiles/lab3template.dir/main.cpp.o: CMakeFiles/lab3template.dir/flags.make
CMakeFiles/lab3template.dir/main.cpp.o: /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/main.cpp
CMakeFiles/lab3template.dir/main.cpp.o: CMakeFiles/lab3template.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab3template.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3template.dir/main.cpp.o -MF CMakeFiles/lab3template.dir/main.cpp.o.d -o CMakeFiles/lab3template.dir/main.cpp.o -c /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/main.cpp

CMakeFiles/lab3template.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab3template.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/main.cpp > CMakeFiles/lab3template.dir/main.cpp.i

CMakeFiles/lab3template.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab3template.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/main.cpp -o CMakeFiles/lab3template.dir/main.cpp.s

CMakeFiles/lab3template.dir/myStack.cpp.o: CMakeFiles/lab3template.dir/flags.make
CMakeFiles/lab3template.dir/myStack.cpp.o: /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/myStack.cpp
CMakeFiles/lab3template.dir/myStack.cpp.o: CMakeFiles/lab3template.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab3template.dir/myStack.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3template.dir/myStack.cpp.o -MF CMakeFiles/lab3template.dir/myStack.cpp.o.d -o CMakeFiles/lab3template.dir/myStack.cpp.o -c /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/myStack.cpp

CMakeFiles/lab3template.dir/myStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab3template.dir/myStack.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/myStack.cpp > CMakeFiles/lab3template.dir/myStack.cpp.i

CMakeFiles/lab3template.dir/myStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab3template.dir/myStack.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/myStack.cpp -o CMakeFiles/lab3template.dir/myStack.cpp.s

CMakeFiles/lab3template.dir/unit_tests.cpp.o: CMakeFiles/lab3template.dir/flags.make
CMakeFiles/lab3template.dir/unit_tests.cpp.o: /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/unit_tests.cpp
CMakeFiles/lab3template.dir/unit_tests.cpp.o: CMakeFiles/lab3template.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab3template.dir/unit_tests.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3template.dir/unit_tests.cpp.o -MF CMakeFiles/lab3template.dir/unit_tests.cpp.o.d -o CMakeFiles/lab3template.dir/unit_tests.cpp.o -c /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/unit_tests.cpp

CMakeFiles/lab3template.dir/unit_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab3template.dir/unit_tests.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/unit_tests.cpp > CMakeFiles/lab3template.dir/unit_tests.cpp.i

CMakeFiles/lab3template.dir/unit_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab3template.dir/unit_tests.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/unit_tests.cpp -o CMakeFiles/lab3template.dir/unit_tests.cpp.s

# Object files for target lab3template
lab3template_OBJECTS = \
"CMakeFiles/lab3template.dir/main.cpp.o" \
"CMakeFiles/lab3template.dir/myStack.cpp.o" \
"CMakeFiles/lab3template.dir/unit_tests.cpp.o"

# External object files for target lab3template
lab3template_EXTERNAL_OBJECTS =

lab3template: CMakeFiles/lab3template.dir/main.cpp.o
lab3template: CMakeFiles/lab3template.dir/myStack.cpp.o
lab3template: CMakeFiles/lab3template.dir/unit_tests.cpp.o
lab3template: CMakeFiles/lab3template.dir/build.make
lab3template: CMakeFiles/lab3template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lab3template"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab3template.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab3template.dir/build: lab3template
.PHONY : CMakeFiles/lab3template.dir/build

CMakeFiles/lab3template.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab3template.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab3template.dir/clean

CMakeFiles/lab3template.dir/depend:
	cd /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/cmake-build-debug /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/cmake-build-debug /Users/davidcho/CLionProjects/lab-3---oop-and-testing-gdcho/cmake-build-debug/CMakeFiles/lab3template.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab3template.dir/depend

