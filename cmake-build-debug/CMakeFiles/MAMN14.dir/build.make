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
CMAKE_COMMAND = /home/ub-l/clion-2022.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ub-l/clion-2022.1.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ub-l/maman14

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ub-l/maman14/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MAMN14.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MAMN14.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MAMN14.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MAMN14.dir/flags.make

CMakeFiles/MAMN14.dir/main.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/main.c.o: ../main.c
CMakeFiles/MAMN14.dir/main.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MAMN14.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/main.c.o -MF CMakeFiles/MAMN14.dir/main.c.o.d -o CMakeFiles/MAMN14.dir/main.c.o -c /home/ub-l/maman14/main.c

CMakeFiles/MAMN14.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/maman14/main.c > CMakeFiles/MAMN14.dir/main.c.i

CMakeFiles/MAMN14.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/maman14/main.c -o CMakeFiles/MAMN14.dir/main.c.s

CMakeFiles/MAMN14.dir/utils/hashmap.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/utils/hashmap.c.o: ../utils/hashmap.c
CMakeFiles/MAMN14.dir/utils/hashmap.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MAMN14.dir/utils/hashmap.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/utils/hashmap.c.o -MF CMakeFiles/MAMN14.dir/utils/hashmap.c.o.d -o CMakeFiles/MAMN14.dir/utils/hashmap.c.o -c /home/ub-l/maman14/utils/hashmap.c

CMakeFiles/MAMN14.dir/utils/hashmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/utils/hashmap.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/maman14/utils/hashmap.c > CMakeFiles/MAMN14.dir/utils/hashmap.c.i

CMakeFiles/MAMN14.dir/utils/hashmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/utils/hashmap.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/maman14/utils/hashmap.c -o CMakeFiles/MAMN14.dir/utils/hashmap.c.s

CMakeFiles/MAMN14.dir/preprocessor.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/preprocessor.c.o: ../preprocessor.c
CMakeFiles/MAMN14.dir/preprocessor.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MAMN14.dir/preprocessor.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/preprocessor.c.o -MF CMakeFiles/MAMN14.dir/preprocessor.c.o.d -o CMakeFiles/MAMN14.dir/preprocessor.c.o -c /home/ub-l/maman14/preprocessor.c

CMakeFiles/MAMN14.dir/preprocessor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/preprocessor.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/maman14/preprocessor.c > CMakeFiles/MAMN14.dir/preprocessor.c.i

CMakeFiles/MAMN14.dir/preprocessor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/preprocessor.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/maman14/preprocessor.c -o CMakeFiles/MAMN14.dir/preprocessor.c.s

CMakeFiles/MAMN14.dir/first_pass.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/first_pass.c.o: ../first_pass.c
CMakeFiles/MAMN14.dir/first_pass.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MAMN14.dir/first_pass.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/first_pass.c.o -MF CMakeFiles/MAMN14.dir/first_pass.c.o.d -o CMakeFiles/MAMN14.dir/first_pass.c.o -c /home/ub-l/maman14/first_pass.c

CMakeFiles/MAMN14.dir/first_pass.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/first_pass.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/maman14/first_pass.c > CMakeFiles/MAMN14.dir/first_pass.c.i

CMakeFiles/MAMN14.dir/first_pass.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/first_pass.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/maman14/first_pass.c -o CMakeFiles/MAMN14.dir/first_pass.c.s

CMakeFiles/MAMN14.dir/assembler_iterations.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/assembler_iterations.c.o: ../assembler_iterations.c
CMakeFiles/MAMN14.dir/assembler_iterations.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/MAMN14.dir/assembler_iterations.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/assembler_iterations.c.o -MF CMakeFiles/MAMN14.dir/assembler_iterations.c.o.d -o CMakeFiles/MAMN14.dir/assembler_iterations.c.o -c /home/ub-l/maman14/assembler_iterations.c

CMakeFiles/MAMN14.dir/assembler_iterations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/assembler_iterations.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/maman14/assembler_iterations.c > CMakeFiles/MAMN14.dir/assembler_iterations.c.i

CMakeFiles/MAMN14.dir/assembler_iterations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/assembler_iterations.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/maman14/assembler_iterations.c -o CMakeFiles/MAMN14.dir/assembler_iterations.c.s

CMakeFiles/MAMN14.dir/utils/file_utils.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/utils/file_utils.c.o: ../utils/file_utils.c
CMakeFiles/MAMN14.dir/utils/file_utils.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/MAMN14.dir/utils/file_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/utils/file_utils.c.o -MF CMakeFiles/MAMN14.dir/utils/file_utils.c.o.d -o CMakeFiles/MAMN14.dir/utils/file_utils.c.o -c /home/ub-l/maman14/utils/file_utils.c

CMakeFiles/MAMN14.dir/utils/file_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/utils/file_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/maman14/utils/file_utils.c > CMakeFiles/MAMN14.dir/utils/file_utils.c.i

CMakeFiles/MAMN14.dir/utils/file_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/utils/file_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/maman14/utils/file_utils.c -o CMakeFiles/MAMN14.dir/utils/file_utils.c.s

CMakeFiles/MAMN14.dir/utils/assembler_utils.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/utils/assembler_utils.c.o: ../utils/assembler_utils.c
CMakeFiles/MAMN14.dir/utils/assembler_utils.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/MAMN14.dir/utils/assembler_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/utils/assembler_utils.c.o -MF CMakeFiles/MAMN14.dir/utils/assembler_utils.c.o.d -o CMakeFiles/MAMN14.dir/utils/assembler_utils.c.o -c /home/ub-l/maman14/utils/assembler_utils.c

CMakeFiles/MAMN14.dir/utils/assembler_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/utils/assembler_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/maman14/utils/assembler_utils.c > CMakeFiles/MAMN14.dir/utils/assembler_utils.c.i

CMakeFiles/MAMN14.dir/utils/assembler_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/utils/assembler_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/maman14/utils/assembler_utils.c -o CMakeFiles/MAMN14.dir/utils/assembler_utils.c.s

CMakeFiles/MAMN14.dir/utils/constants.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/utils/constants.c.o: ../utils/constants.c
CMakeFiles/MAMN14.dir/utils/constants.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/MAMN14.dir/utils/constants.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/utils/constants.c.o -MF CMakeFiles/MAMN14.dir/utils/constants.c.o.d -o CMakeFiles/MAMN14.dir/utils/constants.c.o -c /home/ub-l/maman14/utils/constants.c

CMakeFiles/MAMN14.dir/utils/constants.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/utils/constants.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/maman14/utils/constants.c > CMakeFiles/MAMN14.dir/utils/constants.c.i

CMakeFiles/MAMN14.dir/utils/constants.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/utils/constants.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/maman14/utils/constants.c -o CMakeFiles/MAMN14.dir/utils/constants.c.s

CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.o: ../utils/assembler_addressing_utils.c
CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.o -MF CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.o.d -o CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.o -c /home/ub-l/maman14/utils/assembler_addressing_utils.c

CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/maman14/utils/assembler_addressing_utils.c > CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.i

CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/maman14/utils/assembler_addressing_utils.c -o CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.s

CMakeFiles/MAMN14.dir/utils/errors_utils.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/utils/errors_utils.c.o: ../utils/errors_utils.c
CMakeFiles/MAMN14.dir/utils/errors_utils.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/MAMN14.dir/utils/errors_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/utils/errors_utils.c.o -MF CMakeFiles/MAMN14.dir/utils/errors_utils.c.o.d -o CMakeFiles/MAMN14.dir/utils/errors_utils.c.o -c /home/ub-l/maman14/utils/errors_utils.c

CMakeFiles/MAMN14.dir/utils/errors_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/utils/errors_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/maman14/utils/errors_utils.c > CMakeFiles/MAMN14.dir/utils/errors_utils.c.i

CMakeFiles/MAMN14.dir/utils/errors_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/utils/errors_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/maman14/utils/errors_utils.c -o CMakeFiles/MAMN14.dir/utils/errors_utils.c.s

# Object files for target MAMN14
MAMN14_OBJECTS = \
"CMakeFiles/MAMN14.dir/main.c.o" \
"CMakeFiles/MAMN14.dir/utils/hashmap.c.o" \
"CMakeFiles/MAMN14.dir/preprocessor.c.o" \
"CMakeFiles/MAMN14.dir/first_pass.c.o" \
"CMakeFiles/MAMN14.dir/assembler_iterations.c.o" \
"CMakeFiles/MAMN14.dir/utils/file_utils.c.o" \
"CMakeFiles/MAMN14.dir/utils/assembler_utils.c.o" \
"CMakeFiles/MAMN14.dir/utils/constants.c.o" \
"CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.o" \
"CMakeFiles/MAMN14.dir/utils/errors_utils.c.o"

# External object files for target MAMN14
MAMN14_EXTERNAL_OBJECTS =

MAMN14: CMakeFiles/MAMN14.dir/main.c.o
MAMN14: CMakeFiles/MAMN14.dir/utils/hashmap.c.o
MAMN14: CMakeFiles/MAMN14.dir/preprocessor.c.o
MAMN14: CMakeFiles/MAMN14.dir/first_pass.c.o
MAMN14: CMakeFiles/MAMN14.dir/assembler_iterations.c.o
MAMN14: CMakeFiles/MAMN14.dir/utils/file_utils.c.o
MAMN14: CMakeFiles/MAMN14.dir/utils/assembler_utils.c.o
MAMN14: CMakeFiles/MAMN14.dir/utils/constants.c.o
MAMN14: CMakeFiles/MAMN14.dir/utils/assembler_addressing_utils.c.o
MAMN14: CMakeFiles/MAMN14.dir/utils/errors_utils.c.o
MAMN14: CMakeFiles/MAMN14.dir/build.make
MAMN14: CMakeFiles/MAMN14.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ub-l/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable MAMN14"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MAMN14.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MAMN14.dir/build: MAMN14
.PHONY : CMakeFiles/MAMN14.dir/build

CMakeFiles/MAMN14.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MAMN14.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MAMN14.dir/clean

CMakeFiles/MAMN14.dir/depend:
	cd /home/ub-l/maman14/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ub-l/maman14 /home/ub-l/maman14 /home/ub-l/maman14/cmake-build-debug /home/ub-l/maman14/cmake-build-debug /home/ub-l/maman14/cmake-build-debug/CMakeFiles/MAMN14.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MAMN14.dir/depend

