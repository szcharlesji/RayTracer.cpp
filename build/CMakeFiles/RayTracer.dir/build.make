# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/codespace/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/codespace/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/RayTracer.cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/RayTracer.cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/RayTracer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RayTracer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RayTracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RayTracer.dir/flags.make

CMakeFiles/RayTracer.dir/main.cpp.o: CMakeFiles/RayTracer.dir/flags.make
CMakeFiles/RayTracer.dir/main.cpp.o: /workspaces/RayTracer.cpp/main.cpp
CMakeFiles/RayTracer.dir/main.cpp.o: CMakeFiles/RayTracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/RayTracer.cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RayTracer.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RayTracer.dir/main.cpp.o -MF CMakeFiles/RayTracer.dir/main.cpp.o.d -o CMakeFiles/RayTracer.dir/main.cpp.o -c /workspaces/RayTracer.cpp/main.cpp

CMakeFiles/RayTracer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/RayTracer.cpp/main.cpp > CMakeFiles/RayTracer.dir/main.cpp.i

CMakeFiles/RayTracer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/RayTracer.cpp/main.cpp -o CMakeFiles/RayTracer.dir/main.cpp.s

# Object files for target RayTracer
RayTracer_OBJECTS = \
"CMakeFiles/RayTracer.dir/main.cpp.o"

# External object files for target RayTracer
RayTracer_EXTERNAL_OBJECTS =

RayTracer: CMakeFiles/RayTracer.dir/main.cpp.o
RayTracer: CMakeFiles/RayTracer.dir/build.make
RayTracer: CMakeFiles/RayTracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/RayTracer.cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RayTracer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RayTracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RayTracer.dir/build: RayTracer
.PHONY : CMakeFiles/RayTracer.dir/build

CMakeFiles/RayTracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RayTracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RayTracer.dir/clean

CMakeFiles/RayTracer.dir/depend:
	cd /workspaces/RayTracer.cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/RayTracer.cpp /workspaces/RayTracer.cpp /workspaces/RayTracer.cpp/build /workspaces/RayTracer.cpp/build /workspaces/RayTracer.cpp/build/CMakeFiles/RayTracer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RayTracer.dir/depend

