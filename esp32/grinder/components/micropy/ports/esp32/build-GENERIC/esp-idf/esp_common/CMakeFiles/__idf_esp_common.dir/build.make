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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC

# Include any dependencies generated for this target.
include esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/compiler_depend.make

# Include the progress variables for this target.
include esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/flags.make

esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.obj: esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/flags.make
esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.obj: /home/tuan/esp/esp-idf/components/esp_common/src/esp_err_to_name.c
esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.obj: esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.obj"
	cd /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC/esp-idf/esp_common && /home/tuan/.espressif/tools/xtensa-esp32-elf/esp-2021r2-patch5-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.obj -MF CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.obj.d -o CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.obj -c /home/tuan/esp/esp-idf/components/esp_common/src/esp_err_to_name.c

esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.i"
	cd /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC/esp-idf/esp_common && /home/tuan/.espressif/tools/xtensa-esp32-elf/esp-2021r2-patch5-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tuan/esp/esp-idf/components/esp_common/src/esp_err_to_name.c > CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.i

esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.s"
	cd /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC/esp-idf/esp_common && /home/tuan/.espressif/tools/xtensa-esp32-elf/esp-2021r2-patch5-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tuan/esp/esp-idf/components/esp_common/src/esp_err_to_name.c -o CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.s

# Object files for target __idf_esp_common
__idf_esp_common_OBJECTS = \
"CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.obj"

# External object files for target __idf_esp_common
__idf_esp_common_EXTERNAL_OBJECTS =

esp-idf/esp_common/libesp_common.a: esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/src/esp_err_to_name.c.obj
esp-idf/esp_common/libesp_common.a: esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/build.make
esp-idf/esp_common/libesp_common.a: esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libesp_common.a"
	cd /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC/esp-idf/esp_common && $(CMAKE_COMMAND) -P CMakeFiles/__idf_esp_common.dir/cmake_clean_target.cmake
	cd /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC/esp-idf/esp_common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_esp_common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/build: esp-idf/esp_common/libesp_common.a
.PHONY : esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/build

esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/clean:
	cd /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC/esp-idf/esp_common && $(CMAKE_COMMAND) -P CMakeFiles/__idf_esp_common.dir/cmake_clean.cmake
.PHONY : esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/clean

esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/depend:
	cd /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32 /home/tuan/esp/esp-idf/components/esp_common /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC/esp-idf/esp_common /home/tuan/grinder/esp32/grinder/components/micropy/ports/esp32/build-GENERIC/esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/esp_common/CMakeFiles/__idf_esp_common.dir/depend

