# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/ruanjian/workspace/project_v/data_structure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ruanjian/workspace/project_v/data_structure/build

# Include any dependencies generated for this target.
include CMakeFiles/data_structure.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/data_structure.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/data_structure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data_structure.dir/flags.make

CMakeFiles/data_structure.dir/main/queue_test.cc.o: CMakeFiles/data_structure.dir/flags.make
CMakeFiles/data_structure.dir/main/queue_test.cc.o: ../main/queue_test.cc
CMakeFiles/data_structure.dir/main/queue_test.cc.o: CMakeFiles/data_structure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruanjian/workspace/project_v/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/data_structure.dir/main/queue_test.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/data_structure.dir/main/queue_test.cc.o -MF CMakeFiles/data_structure.dir/main/queue_test.cc.o.d -o CMakeFiles/data_structure.dir/main/queue_test.cc.o -c /home/ruanjian/workspace/project_v/data_structure/main/queue_test.cc

CMakeFiles/data_structure.dir/main/queue_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/data_structure.dir/main/queue_test.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ruanjian/workspace/project_v/data_structure/main/queue_test.cc > CMakeFiles/data_structure.dir/main/queue_test.cc.i

CMakeFiles/data_structure.dir/main/queue_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/data_structure.dir/main/queue_test.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ruanjian/workspace/project_v/data_structure/main/queue_test.cc -o CMakeFiles/data_structure.dir/main/queue_test.cc.s

# Object files for target data_structure
data_structure_OBJECTS = \
"CMakeFiles/data_structure.dir/main/queue_test.cc.o"

# External object files for target data_structure
data_structure_EXTERNAL_OBJECTS =

data_structure: CMakeFiles/data_structure.dir/main/queue_test.cc.o
data_structure: CMakeFiles/data_structure.dir/build.make
data_structure: CMakeFiles/data_structure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ruanjian/workspace/project_v/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable data_structure"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data_structure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data_structure.dir/build: data_structure
.PHONY : CMakeFiles/data_structure.dir/build

CMakeFiles/data_structure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/data_structure.dir/cmake_clean.cmake
.PHONY : CMakeFiles/data_structure.dir/clean

CMakeFiles/data_structure.dir/depend:
	cd /home/ruanjian/workspace/project_v/data_structure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ruanjian/workspace/project_v/data_structure /home/ruanjian/workspace/project_v/data_structure /home/ruanjian/workspace/project_v/data_structure/build /home/ruanjian/workspace/project_v/data_structure/build /home/ruanjian/workspace/project_v/data_structure/build/CMakeFiles/data_structure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/data_structure.dir/depend

