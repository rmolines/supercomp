# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rmolines/Documents/supercomp/multi-core/12-suporte

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rmolines/Documents/supercomp/multi-core/12-suporte/build

# Include any dependencies generated for this target.
include CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello.dir/flags.make

CMakeFiles/hello.dir/hello_world.cpp.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/hello_world.cpp.o: ../hello_world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rmolines/Documents/supercomp/multi-core/12-suporte/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello.dir/hello_world.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello.dir/hello_world.cpp.o -c /home/rmolines/Documents/supercomp/multi-core/12-suporte/hello_world.cpp

CMakeFiles/hello.dir/hello_world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/hello_world.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rmolines/Documents/supercomp/multi-core/12-suporte/hello_world.cpp > CMakeFiles/hello.dir/hello_world.cpp.i

CMakeFiles/hello.dir/hello_world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/hello_world.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rmolines/Documents/supercomp/multi-core/12-suporte/hello_world.cpp -o CMakeFiles/hello.dir/hello_world.cpp.s

CMakeFiles/hello.dir/hello_world.cpp.o.requires:

.PHONY : CMakeFiles/hello.dir/hello_world.cpp.o.requires

CMakeFiles/hello.dir/hello_world.cpp.o.provides: CMakeFiles/hello.dir/hello_world.cpp.o.requires
	$(MAKE) -f CMakeFiles/hello.dir/build.make CMakeFiles/hello.dir/hello_world.cpp.o.provides.build
.PHONY : CMakeFiles/hello.dir/hello_world.cpp.o.provides

CMakeFiles/hello.dir/hello_world.cpp.o.provides.build: CMakeFiles/hello.dir/hello_world.cpp.o


# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/hello_world.cpp.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

hello: CMakeFiles/hello.dir/hello_world.cpp.o
hello: CMakeFiles/hello.dir/build.make
hello: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
hello: /usr/lib/x86_64-linux-gnu/libboost_system.so
hello: CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rmolines/Documents/supercomp/multi-core/12-suporte/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello.dir/build: hello

.PHONY : CMakeFiles/hello.dir/build

CMakeFiles/hello.dir/requires: CMakeFiles/hello.dir/hello_world.cpp.o.requires

.PHONY : CMakeFiles/hello.dir/requires

CMakeFiles/hello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello.dir/clean

CMakeFiles/hello.dir/depend:
	cd /home/rmolines/Documents/supercomp/multi-core/12-suporte/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rmolines/Documents/supercomp/multi-core/12-suporte /home/rmolines/Documents/supercomp/multi-core/12-suporte /home/rmolines/Documents/supercomp/multi-core/12-suporte/build /home/rmolines/Documents/supercomp/multi-core/12-suporte/build /home/rmolines/Documents/supercomp/multi-core/12-suporte/build/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello.dir/depend

