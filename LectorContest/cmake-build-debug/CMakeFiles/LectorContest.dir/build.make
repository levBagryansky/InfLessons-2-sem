# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tardis3/InfLessons-2-sem/LectorContest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tardis3/InfLessons-2-sem/LectorContest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LectorContest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LectorContest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LectorContest.dir/flags.make

CMakeFiles/LectorContest.dir/library.c.o: CMakeFiles/LectorContest.dir/flags.make
CMakeFiles/LectorContest.dir/library.c.o: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tardis3/InfLessons-2-sem/LectorContest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LectorContest.dir/library.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LectorContest.dir/library.c.o -c /home/tardis3/InfLessons-2-sem/LectorContest/library.c

CMakeFiles/LectorContest.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LectorContest.dir/library.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tardis3/InfLessons-2-sem/LectorContest/library.c > CMakeFiles/LectorContest.dir/library.c.i

CMakeFiles/LectorContest.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LectorContest.dir/library.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tardis3/InfLessons-2-sem/LectorContest/library.c -o CMakeFiles/LectorContest.dir/library.c.s

# Object files for target LectorContest
LectorContest_OBJECTS = \
"CMakeFiles/LectorContest.dir/library.c.o"

# External object files for target LectorContest
LectorContest_EXTERNAL_OBJECTS =

libLectorContest.a: CMakeFiles/LectorContest.dir/library.c.o
libLectorContest.a: CMakeFiles/LectorContest.dir/build.make
libLectorContest.a: CMakeFiles/LectorContest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tardis3/InfLessons-2-sem/LectorContest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libLectorContest.a"
	$(CMAKE_COMMAND) -P CMakeFiles/LectorContest.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LectorContest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LectorContest.dir/build: libLectorContest.a

.PHONY : CMakeFiles/LectorContest.dir/build

CMakeFiles/LectorContest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LectorContest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LectorContest.dir/clean

CMakeFiles/LectorContest.dir/depend:
	cd /home/tardis3/InfLessons-2-sem/LectorContest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tardis3/InfLessons-2-sem/LectorContest /home/tardis3/InfLessons-2-sem/LectorContest /home/tardis3/InfLessons-2-sem/LectorContest/cmake-build-debug /home/tardis3/InfLessons-2-sem/LectorContest/cmake-build-debug /home/tardis3/InfLessons-2-sem/LectorContest/cmake-build-debug/CMakeFiles/LectorContest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LectorContest.dir/depend

