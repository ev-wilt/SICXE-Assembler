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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pjoyjr/csci300/SICXE-Assembler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pjoyjr/csci300/SICXE-Assembler

# Include any dependencies generated for this target.
include CMakeFiles/SICXE-Assembler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SICXE-Assembler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SICXE-Assembler.dir/flags.make

CMakeFiles/SICXE-Assembler.dir/main.cpp.o: CMakeFiles/SICXE-Assembler.dir/flags.make
CMakeFiles/SICXE-Assembler.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pjoyjr/csci300/SICXE-Assembler/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SICXE-Assembler.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SICXE-Assembler.dir/main.cpp.o -c /home/pjoyjr/csci300/SICXE-Assembler/main.cpp

CMakeFiles/SICXE-Assembler.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SICXE-Assembler.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pjoyjr/csci300/SICXE-Assembler/main.cpp > CMakeFiles/SICXE-Assembler.dir/main.cpp.i

CMakeFiles/SICXE-Assembler.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SICXE-Assembler.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pjoyjr/csci300/SICXE-Assembler/main.cpp -o CMakeFiles/SICXE-Assembler.dir/main.cpp.s

CMakeFiles/SICXE-Assembler.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/SICXE-Assembler.dir/main.cpp.o.requires

CMakeFiles/SICXE-Assembler.dir/main.cpp.o.provides: CMakeFiles/SICXE-Assembler.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SICXE-Assembler.dir/build.make CMakeFiles/SICXE-Assembler.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SICXE-Assembler.dir/main.cpp.o.provides

CMakeFiles/SICXE-Assembler.dir/main.cpp.o.provides.build: CMakeFiles/SICXE-Assembler.dir/main.cpp.o

CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o: CMakeFiles/SICXE-Assembler.dir/flags.make
CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o: op_table.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pjoyjr/csci300/SICXE-Assembler/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o -c /home/pjoyjr/csci300/SICXE-Assembler/op_table.cpp

CMakeFiles/SICXE-Assembler.dir/op_table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SICXE-Assembler.dir/op_table.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pjoyjr/csci300/SICXE-Assembler/op_table.cpp > CMakeFiles/SICXE-Assembler.dir/op_table.cpp.i

CMakeFiles/SICXE-Assembler.dir/op_table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SICXE-Assembler.dir/op_table.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pjoyjr/csci300/SICXE-Assembler/op_table.cpp -o CMakeFiles/SICXE-Assembler.dir/op_table.cpp.s

CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o.requires:
.PHONY : CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o.requires

CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o.provides: CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o.requires
	$(MAKE) -f CMakeFiles/SICXE-Assembler.dir/build.make CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o.provides.build
.PHONY : CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o.provides

CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o.provides.build: CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o

CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o: CMakeFiles/SICXE-Assembler.dir/flags.make
CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o: sym_table.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pjoyjr/csci300/SICXE-Assembler/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o -c /home/pjoyjr/csci300/SICXE-Assembler/sym_table.cpp

CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pjoyjr/csci300/SICXE-Assembler/sym_table.cpp > CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.i

CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pjoyjr/csci300/SICXE-Assembler/sym_table.cpp -o CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.s

CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o.requires:
.PHONY : CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o.requires

CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o.provides: CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o.requires
	$(MAKE) -f CMakeFiles/SICXE-Assembler.dir/build.make CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o.provides.build
.PHONY : CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o.provides

CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o.provides.build: CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o

CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o: CMakeFiles/SICXE-Assembler.dir/flags.make
CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o: symbol.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pjoyjr/csci300/SICXE-Assembler/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o -c /home/pjoyjr/csci300/SICXE-Assembler/symbol.cpp

CMakeFiles/SICXE-Assembler.dir/symbol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SICXE-Assembler.dir/symbol.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pjoyjr/csci300/SICXE-Assembler/symbol.cpp > CMakeFiles/SICXE-Assembler.dir/symbol.cpp.i

CMakeFiles/SICXE-Assembler.dir/symbol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SICXE-Assembler.dir/symbol.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pjoyjr/csci300/SICXE-Assembler/symbol.cpp -o CMakeFiles/SICXE-Assembler.dir/symbol.cpp.s

CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o.requires:
.PHONY : CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o.requires

CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o.provides: CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o.requires
	$(MAKE) -f CMakeFiles/SICXE-Assembler.dir/build.make CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o.provides.build
.PHONY : CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o.provides

CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o.provides.build: CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o

# Object files for target SICXE-Assembler
SICXE__Assembler_OBJECTS = \
"CMakeFiles/SICXE-Assembler.dir/main.cpp.o" \
"CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o" \
"CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o" \
"CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o"

# External object files for target SICXE-Assembler
SICXE__Assembler_EXTERNAL_OBJECTS =

SICXE-Assembler: CMakeFiles/SICXE-Assembler.dir/main.cpp.o
SICXE-Assembler: CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o
SICXE-Assembler: CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o
SICXE-Assembler: CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o
SICXE-Assembler: CMakeFiles/SICXE-Assembler.dir/build.make
SICXE-Assembler: CMakeFiles/SICXE-Assembler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable SICXE-Assembler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SICXE-Assembler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SICXE-Assembler.dir/build: SICXE-Assembler
.PHONY : CMakeFiles/SICXE-Assembler.dir/build

CMakeFiles/SICXE-Assembler.dir/requires: CMakeFiles/SICXE-Assembler.dir/main.cpp.o.requires
CMakeFiles/SICXE-Assembler.dir/requires: CMakeFiles/SICXE-Assembler.dir/op_table.cpp.o.requires
CMakeFiles/SICXE-Assembler.dir/requires: CMakeFiles/SICXE-Assembler.dir/sym_table.cpp.o.requires
CMakeFiles/SICXE-Assembler.dir/requires: CMakeFiles/SICXE-Assembler.dir/symbol.cpp.o.requires
.PHONY : CMakeFiles/SICXE-Assembler.dir/requires

CMakeFiles/SICXE-Assembler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SICXE-Assembler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SICXE-Assembler.dir/clean

CMakeFiles/SICXE-Assembler.dir/depend:
	cd /home/pjoyjr/csci300/SICXE-Assembler && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pjoyjr/csci300/SICXE-Assembler /home/pjoyjr/csci300/SICXE-Assembler /home/pjoyjr/csci300/SICXE-Assembler /home/pjoyjr/csci300/SICXE-Assembler /home/pjoyjr/csci300/SICXE-Assembler/CMakeFiles/SICXE-Assembler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SICXE-Assembler.dir/depend

