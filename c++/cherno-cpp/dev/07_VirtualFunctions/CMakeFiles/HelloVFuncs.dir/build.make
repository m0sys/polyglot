# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions

# Include any dependencies generated for this target.
include CMakeFiles/HelloVFuncs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloVFuncs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloVFuncs.dir/flags.make

CMakeFiles/HelloVFuncs.dir/src/main.cc.o: CMakeFiles/HelloVFuncs.dir/flags.make
CMakeFiles/HelloVFuncs.dir/src/main.cc.o: src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HelloVFuncs.dir/src/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HelloVFuncs.dir/src/main.cc.o -c /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions/src/main.cc

CMakeFiles/HelloVFuncs.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloVFuncs.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions/src/main.cc > CMakeFiles/HelloVFuncs.dir/src/main.cc.i

CMakeFiles/HelloVFuncs.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloVFuncs.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions/src/main.cc -o CMakeFiles/HelloVFuncs.dir/src/main.cc.s

# Object files for target HelloVFuncs
HelloVFuncs_OBJECTS = \
"CMakeFiles/HelloVFuncs.dir/src/main.cc.o"

# External object files for target HelloVFuncs
HelloVFuncs_EXTERNAL_OBJECTS =

HelloVFuncs: CMakeFiles/HelloVFuncs.dir/src/main.cc.o
HelloVFuncs: CMakeFiles/HelloVFuncs.dir/build.make
HelloVFuncs: CMakeFiles/HelloVFuncs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HelloVFuncs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HelloVFuncs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloVFuncs.dir/build: HelloVFuncs

.PHONY : CMakeFiles/HelloVFuncs.dir/build

CMakeFiles/HelloVFuncs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HelloVFuncs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HelloVFuncs.dir/clean

CMakeFiles/HelloVFuncs.dir/depend:
	cd /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/07_VirtualFunctions/CMakeFiles/HelloVFuncs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HelloVFuncs.dir/depend
