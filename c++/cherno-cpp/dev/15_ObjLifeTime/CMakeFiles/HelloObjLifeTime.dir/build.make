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
CMAKE_SOURCE_DIR = /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime

# Include any dependencies generated for this target.
include CMakeFiles/HelloObjLifeTime.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloObjLifeTime.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloObjLifeTime.dir/flags.make

CMakeFiles/HelloObjLifeTime.dir/src/main.cc.o: CMakeFiles/HelloObjLifeTime.dir/flags.make
CMakeFiles/HelloObjLifeTime.dir/src/main.cc.o: src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HelloObjLifeTime.dir/src/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HelloObjLifeTime.dir/src/main.cc.o -c /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime/src/main.cc

CMakeFiles/HelloObjLifeTime.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloObjLifeTime.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime/src/main.cc > CMakeFiles/HelloObjLifeTime.dir/src/main.cc.i

CMakeFiles/HelloObjLifeTime.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloObjLifeTime.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime/src/main.cc -o CMakeFiles/HelloObjLifeTime.dir/src/main.cc.s

# Object files for target HelloObjLifeTime
HelloObjLifeTime_OBJECTS = \
"CMakeFiles/HelloObjLifeTime.dir/src/main.cc.o"

# External object files for target HelloObjLifeTime
HelloObjLifeTime_EXTERNAL_OBJECTS =

HelloObjLifeTime: CMakeFiles/HelloObjLifeTime.dir/src/main.cc.o
HelloObjLifeTime: CMakeFiles/HelloObjLifeTime.dir/build.make
HelloObjLifeTime: CMakeFiles/HelloObjLifeTime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HelloObjLifeTime"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HelloObjLifeTime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloObjLifeTime.dir/build: HelloObjLifeTime

.PHONY : CMakeFiles/HelloObjLifeTime.dir/build

CMakeFiles/HelloObjLifeTime.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HelloObjLifeTime.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HelloObjLifeTime.dir/clean

CMakeFiles/HelloObjLifeTime.dir/depend:
	cd /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime /home/mo/Desktop/Github/polyglot/c++/cherno-cpp/dev/15_ObjLifeTime/CMakeFiles/HelloObjLifeTime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HelloObjLifeTime.dir/depend

