# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /mnt/d/repos/Sulfur

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/repos/Sulfur/bld

# Include any dependencies generated for this target.
include CMakeFiles/Sulfur.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Sulfur.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Sulfur.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sulfur.dir/flags.make

CMakeFiles/Sulfur.dir/src/lexer.c.o: CMakeFiles/Sulfur.dir/flags.make
CMakeFiles/Sulfur.dir/src/lexer.c.o: /mnt/d/repos/Sulfur/src/lexer.c
CMakeFiles/Sulfur.dir/src/lexer.c.o: CMakeFiles/Sulfur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/repos/Sulfur/bld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Sulfur.dir/src/lexer.c.o"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Sulfur.dir/src/lexer.c.o -MF CMakeFiles/Sulfur.dir/src/lexer.c.o.d -o CMakeFiles/Sulfur.dir/src/lexer.c.o -c /mnt/d/repos/Sulfur/src/lexer.c

CMakeFiles/Sulfur.dir/src/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Sulfur.dir/src/lexer.c.i"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/repos/Sulfur/src/lexer.c > CMakeFiles/Sulfur.dir/src/lexer.c.i

CMakeFiles/Sulfur.dir/src/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Sulfur.dir/src/lexer.c.s"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/repos/Sulfur/src/lexer.c -o CMakeFiles/Sulfur.dir/src/lexer.c.s

CMakeFiles/Sulfur.dir/src/main.c.o: CMakeFiles/Sulfur.dir/flags.make
CMakeFiles/Sulfur.dir/src/main.c.o: /mnt/d/repos/Sulfur/src/main.c
CMakeFiles/Sulfur.dir/src/main.c.o: CMakeFiles/Sulfur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/repos/Sulfur/bld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Sulfur.dir/src/main.c.o"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Sulfur.dir/src/main.c.o -MF CMakeFiles/Sulfur.dir/src/main.c.o.d -o CMakeFiles/Sulfur.dir/src/main.c.o -c /mnt/d/repos/Sulfur/src/main.c

CMakeFiles/Sulfur.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Sulfur.dir/src/main.c.i"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/repos/Sulfur/src/main.c > CMakeFiles/Sulfur.dir/src/main.c.i

CMakeFiles/Sulfur.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Sulfur.dir/src/main.c.s"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/repos/Sulfur/src/main.c -o CMakeFiles/Sulfur.dir/src/main.c.s

# Object files for target Sulfur
Sulfur_OBJECTS = \
"CMakeFiles/Sulfur.dir/src/lexer.c.o" \
"CMakeFiles/Sulfur.dir/src/main.c.o"

# External object files for target Sulfur
Sulfur_EXTERNAL_OBJECTS =

Sulfur: CMakeFiles/Sulfur.dir/src/lexer.c.o
Sulfur: CMakeFiles/Sulfur.dir/src/main.c.o
Sulfur: CMakeFiles/Sulfur.dir/build.make
Sulfur: CMakeFiles/Sulfur.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/d/repos/Sulfur/bld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Sulfur"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sulfur.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sulfur.dir/build: Sulfur
.PHONY : CMakeFiles/Sulfur.dir/build

CMakeFiles/Sulfur.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Sulfur.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Sulfur.dir/clean

CMakeFiles/Sulfur.dir/depend:
	cd /mnt/d/repos/Sulfur/bld && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/repos/Sulfur /mnt/d/repos/Sulfur /mnt/d/repos/Sulfur/bld /mnt/d/repos/Sulfur/bld /mnt/d/repos/Sulfur/bld/CMakeFiles/Sulfur.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Sulfur.dir/depend

