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
CMAKE_SOURCE_DIR = /home/ub-l/project/maman14

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ub-l/project/maman14/cmake-build-debug

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
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MAMN14.dir/main.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/main.c.o -MF CMakeFiles/MAMN14.dir/main.c.o.d -o CMakeFiles/MAMN14.dir/main.c.o -c /home/ub-l/project/maman14/main.c

CMakeFiles/MAMN14.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/main.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/project/maman14/main.c > CMakeFiles/MAMN14.dir/main.c.i

CMakeFiles/MAMN14.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/main.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/project/maman14/main.c -o CMakeFiles/MAMN14.dir/main.c.s

CMakeFiles/MAMN14.dir/hashmap.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/hashmap.c.o: ../hashmap.c
CMakeFiles/MAMN14.dir/hashmap.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MAMN14.dir/hashmap.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/hashmap.c.o -MF CMakeFiles/MAMN14.dir/hashmap.c.o.d -o CMakeFiles/MAMN14.dir/hashmap.c.o -c /home/ub-l/project/maman14/hashmap.c

CMakeFiles/MAMN14.dir/hashmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/hashmap.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/project/maman14/hashmap.c > CMakeFiles/MAMN14.dir/hashmap.c.i

CMakeFiles/MAMN14.dir/hashmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/hashmap.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/project/maman14/hashmap.c -o CMakeFiles/MAMN14.dir/hashmap.c.s

CMakeFiles/MAMN14.dir/preprocessor.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/preprocessor.c.o: ../preprocessor.c
CMakeFiles/MAMN14.dir/preprocessor.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MAMN14.dir/preprocessor.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/preprocessor.c.o -MF CMakeFiles/MAMN14.dir/preprocessor.c.o.d -o CMakeFiles/MAMN14.dir/preprocessor.c.o -c /home/ub-l/project/maman14/preprocessor.c

CMakeFiles/MAMN14.dir/preprocessor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/preprocessor.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/project/maman14/preprocessor.c > CMakeFiles/MAMN14.dir/preprocessor.c.i

CMakeFiles/MAMN14.dir/preprocessor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/preprocessor.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/project/maman14/preprocessor.c -o CMakeFiles/MAMN14.dir/preprocessor.c.s

CMakeFiles/MAMN14.dir/assembler_iterations.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/assembler_iterations.c.o: ../assembler_iterations.c
CMakeFiles/MAMN14.dir/assembler_iterations.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MAMN14.dir/assembler_iterations.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/assembler_iterations.c.o -MF CMakeFiles/MAMN14.dir/assembler_iterations.c.o.d -o CMakeFiles/MAMN14.dir/assembler_iterations.c.o -c /home/ub-l/project/maman14/assembler_iterations.c

CMakeFiles/MAMN14.dir/assembler_iterations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/assembler_iterations.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/project/maman14/assembler_iterations.c > CMakeFiles/MAMN14.dir/assembler_iterations.c.i

CMakeFiles/MAMN14.dir/assembler_iterations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/assembler_iterations.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/project/maman14/assembler_iterations.c -o CMakeFiles/MAMN14.dir/assembler_iterations.c.s

CMakeFiles/MAMN14.dir/file_utils.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/file_utils.c.o: ../file_utils.c
CMakeFiles/MAMN14.dir/file_utils.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/MAMN14.dir/file_utils.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/file_utils.c.o -MF CMakeFiles/MAMN14.dir/file_utils.c.o.d -o CMakeFiles/MAMN14.dir/file_utils.c.o -c /home/ub-l/project/maman14/file_utils.c

CMakeFiles/MAMN14.dir/file_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/file_utils.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/project/maman14/file_utils.c > CMakeFiles/MAMN14.dir/file_utils.c.i

CMakeFiles/MAMN14.dir/file_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/file_utils.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/project/maman14/file_utils.c -o CMakeFiles/MAMN14.dir/file_utils.c.s

CMakeFiles/MAMN14.dir/assembler_utils.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/assembler_utils.c.o: ../assembler_utils.c
CMakeFiles/MAMN14.dir/assembler_utils.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/MAMN14.dir/assembler_utils.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/assembler_utils.c.o -MF CMakeFiles/MAMN14.dir/assembler_utils.c.o.d -o CMakeFiles/MAMN14.dir/assembler_utils.c.o -c /home/ub-l/project/maman14/assembler_utils.c

CMakeFiles/MAMN14.dir/assembler_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/assembler_utils.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/project/maman14/assembler_utils.c > CMakeFiles/MAMN14.dir/assembler_utils.c.i

CMakeFiles/MAMN14.dir/assembler_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/assembler_utils.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/project/maman14/assembler_utils.c -o CMakeFiles/MAMN14.dir/assembler_utils.c.s

CMakeFiles/MAMN14.dir/constants.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/constants.c.o: ../constants.c
CMakeFiles/MAMN14.dir/constants.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/MAMN14.dir/constants.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/constants.c.o -MF CMakeFiles/MAMN14.dir/constants.c.o.d -o CMakeFiles/MAMN14.dir/constants.c.o -c /home/ub-l/project/maman14/constants.c

CMakeFiles/MAMN14.dir/constants.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/constants.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/project/maman14/constants.c > CMakeFiles/MAMN14.dir/constants.c.i

CMakeFiles/MAMN14.dir/constants.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/constants.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/project/maman14/constants.c -o CMakeFiles/MAMN14.dir/constants.c.s

CMakeFiles/MAMN14.dir/errors_utils.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/errors_utils.c.o: ../errors_utils.c
CMakeFiles/MAMN14.dir/errors_utils.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/MAMN14.dir/errors_utils.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/errors_utils.c.o -MF CMakeFiles/MAMN14.dir/errors_utils.c.o.d -o CMakeFiles/MAMN14.dir/errors_utils.c.o -c /home/ub-l/project/maman14/errors_utils.c

CMakeFiles/MAMN14.dir/errors_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/errors_utils.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/project/maman14/errors_utils.c > CMakeFiles/MAMN14.dir/errors_utils.c.i

CMakeFiles/MAMN14.dir/errors_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/errors_utils.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/project/maman14/errors_utils.c -o CMakeFiles/MAMN14.dir/errors_utils.c.s

CMakeFiles/MAMN14.dir/input_utils.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/input_utils.c.o: ../input_utils.c
CMakeFiles/MAMN14.dir/input_utils.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/MAMN14.dir/input_utils.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/input_utils.c.o -MF CMakeFiles/MAMN14.dir/input_utils.c.o.d -o CMakeFiles/MAMN14.dir/input_utils.c.o -c /home/ub-l/project/maman14/input_utils.c

CMakeFiles/MAMN14.dir/input_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/input_utils.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/project/maman14/input_utils.c > CMakeFiles/MAMN14.dir/input_utils.c.i

CMakeFiles/MAMN14.dir/input_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/input_utils.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/project/maman14/input_utils.c -o CMakeFiles/MAMN14.dir/input_utils.c.s

CMakeFiles/MAMN14.dir/operands_related.c.o: CMakeFiles/MAMN14.dir/flags.make
CMakeFiles/MAMN14.dir/operands_related.c.o: ../operands_related.c
CMakeFiles/MAMN14.dir/operands_related.c.o: CMakeFiles/MAMN14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/MAMN14.dir/operands_related.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MAMN14.dir/operands_related.c.o -MF CMakeFiles/MAMN14.dir/operands_related.c.o.d -o CMakeFiles/MAMN14.dir/operands_related.c.o -c /home/ub-l/project/maman14/operands_related.c

CMakeFiles/MAMN14.dir/operands_related.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MAMN14.dir/operands_related.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ub-l/project/maman14/operands_related.c > CMakeFiles/MAMN14.dir/operands_related.c.i

CMakeFiles/MAMN14.dir/operands_related.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MAMN14.dir/operands_related.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ub-l/project/maman14/operands_related.c -o CMakeFiles/MAMN14.dir/operands_related.c.s

# Object files for target MAMN14
MAMN14_OBJECTS = \
"CMakeFiles/MAMN14.dir/main.c.o" \
"CMakeFiles/MAMN14.dir/hashmap.c.o" \
"CMakeFiles/MAMN14.dir/preprocessor.c.o" \
"CMakeFiles/MAMN14.dir/assembler_iterations.c.o" \
"CMakeFiles/MAMN14.dir/file_utils.c.o" \
"CMakeFiles/MAMN14.dir/assembler_utils.c.o" \
"CMakeFiles/MAMN14.dir/constants.c.o" \
"CMakeFiles/MAMN14.dir/errors_utils.c.o" \
"CMakeFiles/MAMN14.dir/input_utils.c.o" \
"CMakeFiles/MAMN14.dir/operands_related.c.o"

# External object files for target MAMN14
MAMN14_EXTERNAL_OBJECTS =

MAMN14: CMakeFiles/MAMN14.dir/main.c.o
MAMN14: CMakeFiles/MAMN14.dir/hashmap.c.o
MAMN14: CMakeFiles/MAMN14.dir/preprocessor.c.o
MAMN14: CMakeFiles/MAMN14.dir/assembler_iterations.c.o
MAMN14: CMakeFiles/MAMN14.dir/file_utils.c.o
MAMN14: CMakeFiles/MAMN14.dir/assembler_utils.c.o
MAMN14: CMakeFiles/MAMN14.dir/constants.c.o
MAMN14: CMakeFiles/MAMN14.dir/errors_utils.c.o
MAMN14: CMakeFiles/MAMN14.dir/input_utils.c.o
MAMN14: CMakeFiles/MAMN14.dir/operands_related.c.o
MAMN14: CMakeFiles/MAMN14.dir/build.make
MAMN14: CMakeFiles/MAMN14.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ub-l/project/maman14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable MAMN14"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MAMN14.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MAMN14.dir/build: MAMN14
.PHONY : CMakeFiles/MAMN14.dir/build

CMakeFiles/MAMN14.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MAMN14.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MAMN14.dir/clean

CMakeFiles/MAMN14.dir/depend:
	cd /home/ub-l/project/maman14/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ub-l/project/maman14 /home/ub-l/project/maman14 /home/ub-l/project/maman14/cmake-build-debug /home/ub-l/project/maman14/cmake-build-debug /home/ub-l/project/maman14/cmake-build-debug/CMakeFiles/MAMN14.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MAMN14.dir/depend

