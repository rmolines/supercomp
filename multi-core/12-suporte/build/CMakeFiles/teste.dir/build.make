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
include CMakeFiles/teste.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/teste.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/teste.dir/flags.make

CMakeFiles/teste.dir/teste_omp.cpp.o: CMakeFiles/teste.dir/flags.make
CMakeFiles/teste.dir/teste_omp.cpp.o: ../teste_omp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rmolines/Documents/supercomp/multi-core/12-suporte/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/teste.dir/teste_omp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/teste.dir/teste_omp.cpp.o -c /home/rmolines/Documents/supercomp/multi-core/12-suporte/teste_omp.cpp

CMakeFiles/teste.dir/teste_omp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/teste.dir/teste_omp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rmolines/Documents/supercomp/multi-core/12-suporte/teste_omp.cpp > CMakeFiles/teste.dir/teste_omp.cpp.i

CMakeFiles/teste.dir/teste_omp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/teste.dir/teste_omp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rmolines/Documents/supercomp/multi-core/12-suporte/teste_omp.cpp -o CMakeFiles/teste.dir/teste_omp.cpp.s

CMakeFiles/teste.dir/teste_omp.cpp.o.requires:

.PHONY : CMakeFiles/teste.dir/teste_omp.cpp.o.requires

CMakeFiles/teste.dir/teste_omp.cpp.o.provides: CMakeFiles/teste.dir/teste_omp.cpp.o.requires
	$(MAKE) -f CMakeFiles/teste.dir/build.make CMakeFiles/teste.dir/teste_omp.cpp.o.provides.build
.PHONY : CMakeFiles/teste.dir/teste_omp.cpp.o.provides

CMakeFiles/teste.dir/teste_omp.cpp.o.provides.build: CMakeFiles/teste.dir/teste_omp.cpp.o


# Object files for target teste
teste_OBJECTS = \
"CMakeFiles/teste.dir/teste_omp.cpp.o"

# External object files for target teste
teste_EXTERNAL_OBJECTS =

teste: CMakeFiles/teste.dir/teste_omp.cpp.o
teste: CMakeFiles/teste.dir/build.make
teste: /usr/lib/gcc/x86_64-linux-gnu/7/libgomp.so
teste: /usr/lib/x86_64-linux-gnu/libpthread.so
teste: CMakeFiles/teste.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rmolines/Documents/supercomp/multi-core/12-suporte/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable teste"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/teste.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/teste.dir/build: teste

.PHONY : CMakeFiles/teste.dir/build

CMakeFiles/teste.dir/requires: CMakeFiles/teste.dir/teste_omp.cpp.o.requires

.PHONY : CMakeFiles/teste.dir/requires

CMakeFiles/teste.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/teste.dir/cmake_clean.cmake
.PHONY : CMakeFiles/teste.dir/clean

CMakeFiles/teste.dir/depend:
	cd /home/rmolines/Documents/supercomp/multi-core/12-suporte/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rmolines/Documents/supercomp/multi-core/12-suporte /home/rmolines/Documents/supercomp/multi-core/12-suporte /home/rmolines/Documents/supercomp/multi-core/12-suporte/build /home/rmolines/Documents/supercomp/multi-core/12-suporte/build /home/rmolines/Documents/supercomp/multi-core/12-suporte/build/CMakeFiles/teste.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/teste.dir/depend

