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
CMAKE_SOURCE_DIR = /mnt/c/Cpp-Assignments/Assignments/Assignment4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Cpp-Assignments/Assignments/Assignment4/build

# Utility rule file for ExperimentalBuild.

# Include any custom commands dependencies for this target.
include CMakeFiles/ExperimentalBuild.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ExperimentalBuild.dir/progress.make

CMakeFiles/ExperimentalBuild:
	/usr/bin/ctest -D ExperimentalBuild

ExperimentalBuild: CMakeFiles/ExperimentalBuild
ExperimentalBuild: CMakeFiles/ExperimentalBuild.dir/build.make
.PHONY : ExperimentalBuild

# Rule to build all files generated by this target.
CMakeFiles/ExperimentalBuild.dir/build: ExperimentalBuild
.PHONY : CMakeFiles/ExperimentalBuild.dir/build

CMakeFiles/ExperimentalBuild.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ExperimentalBuild.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ExperimentalBuild.dir/clean

CMakeFiles/ExperimentalBuild.dir/depend:
	cd /mnt/c/Cpp-Assignments/Assignments/Assignment4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Cpp-Assignments/Assignments/Assignment4 /mnt/c/Cpp-Assignments/Assignments/Assignment4 /mnt/c/Cpp-Assignments/Assignments/Assignment4/build /mnt/c/Cpp-Assignments/Assignments/Assignment4/build /mnt/c/Cpp-Assignments/Assignments/Assignment4/build/CMakeFiles/ExperimentalBuild.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ExperimentalBuild.dir/depend

