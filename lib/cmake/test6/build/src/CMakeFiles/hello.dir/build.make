# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake.exe

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/e/workgroup/cmake/test5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/e/workgroup/cmake/test5/build

# Include any dependencies generated for this target.
include src/CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/hello.dir/flags.make

src/CMakeFiles/hello.dir/main.o: src/CMakeFiles/hello.dir/flags.make
src/CMakeFiles/hello.dir/main.o: ../src/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /cygdrive/e/workgroup/cmake/test5/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/hello.dir/main.o"
	cd /cygdrive/e/workgroup/cmake/test5/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hello.dir/main.o   -c /cygdrive/e/workgroup/cmake/test5/src/main.c

src/CMakeFiles/hello.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello.dir/main.i"
	cd /cygdrive/e/workgroup/cmake/test5/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /cygdrive/e/workgroup/cmake/test5/src/main.c > CMakeFiles/hello.dir/main.i

src/CMakeFiles/hello.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello.dir/main.s"
	cd /cygdrive/e/workgroup/cmake/test5/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /cygdrive/e/workgroup/cmake/test5/src/main.c -o CMakeFiles/hello.dir/main.s

src/CMakeFiles/hello.dir/main.o.requires:
.PHONY : src/CMakeFiles/hello.dir/main.o.requires

src/CMakeFiles/hello.dir/main.o.provides: src/CMakeFiles/hello.dir/main.o.requires
	$(MAKE) -f src/CMakeFiles/hello.dir/build.make src/CMakeFiles/hello.dir/main.o.provides.build
.PHONY : src/CMakeFiles/hello.dir/main.o.provides

src/CMakeFiles/hello.dir/main.o.provides.build: src/CMakeFiles/hello.dir/main.o

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/main.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

bin/hello.exe: src/CMakeFiles/hello.dir/main.o
bin/hello.exe: src/CMakeFiles/hello.dir/build.make
bin/hello.exe: lib/libhello.a
bin/hello.exe: src/CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../bin/hello.exe"
	cd /cygdrive/e/workgroup/cmake/test5/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/hello.dir/build: bin/hello.exe
.PHONY : src/CMakeFiles/hello.dir/build

src/CMakeFiles/hello.dir/requires: src/CMakeFiles/hello.dir/main.o.requires
.PHONY : src/CMakeFiles/hello.dir/requires

src/CMakeFiles/hello.dir/clean:
	cd /cygdrive/e/workgroup/cmake/test5/build/src && $(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/hello.dir/clean

src/CMakeFiles/hello.dir/depend:
	cd /cygdrive/e/workgroup/cmake/test5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/e/workgroup/cmake/test5 /cygdrive/e/workgroup/cmake/test5/src /cygdrive/e/workgroup/cmake/test5/build /cygdrive/e/workgroup/cmake/test5/build/src /cygdrive/e/workgroup/cmake/test5/build/src/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/hello.dir/depend

