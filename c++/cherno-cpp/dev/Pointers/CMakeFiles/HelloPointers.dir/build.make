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
CMAKE_SOURCE_DIR = /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers

# Include any dependencies generated for this target.
include CMakeFiles/HelloPointers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloPointers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloPointers.dir/flags.make

CMakeFiles/HelloPointers.dir/src/main.cc.o: CMakeFiles/HelloPointers.dir/flags.make
CMakeFiles/HelloPointers.dir/src/main.cc.o: src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HelloPointers.dir/src/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HelloPointers.dir/src/main.cc.o -c /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers/src/main.cc

CMakeFiles/HelloPointers.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloPointers.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers/src/main.cc > CMakeFiles/HelloPointers.dir/src/main.cc.i

CMakeFiles/HelloPointers.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloPointers.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers/src/main.cc -o CMakeFiles/HelloPointers.dir/src/main.cc.s

# Object files for target HelloPointers
HelloPointers_OBJECTS = \
"CMakeFiles/HelloPointers.dir/src/main.cc.o"

# External object files for target HelloPointers
HelloPointers_EXTERNAL_OBJECTS =

HelloPointers: CMakeFiles/HelloPointers.dir/src/main.cc.o
HelloPointers: CMakeFiles/HelloPointers.dir/build.make
HelloPointers: CMakeFiles/HelloPointers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HelloPointers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HelloPointers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloPointers.dir/build: HelloPointers

.PHONY : CMakeFiles/HelloPointers.dir/build

CMakeFiles/HelloPointers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HelloPointers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HelloPointers.dir/clean

CMakeFiles/HelloPointers.dir/depend:
	cd /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/Pointers/CMakeFiles/HelloPointers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HelloPointers.dir/depend
