# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/guyver/Prog/homework_for_Qt/Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guyver/Prog/homework_for_Qt/Server/build/debug

# Utility rule file for serverChat_autogen.

# Include the progress variables for this target.
include CMakeFiles/serverChat_autogen.dir/progress.make

CMakeFiles/serverChat_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/guyver/Prog/homework_for_Qt/Server/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target serverChat"
	/usr/bin/cmake -E cmake_autogen /home/guyver/Prog/homework_for_Qt/Server/build/debug/CMakeFiles/serverChat_autogen.dir/AutogenInfo.json Debug

serverChat_autogen: CMakeFiles/serverChat_autogen
serverChat_autogen: CMakeFiles/serverChat_autogen.dir/build.make

.PHONY : serverChat_autogen

# Rule to build all files generated by this target.
CMakeFiles/serverChat_autogen.dir/build: serverChat_autogen

.PHONY : CMakeFiles/serverChat_autogen.dir/build

CMakeFiles/serverChat_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serverChat_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serverChat_autogen.dir/clean

CMakeFiles/serverChat_autogen.dir/depend:
	cd /home/guyver/Prog/homework_for_Qt/Server/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guyver/Prog/homework_for_Qt/Server /home/guyver/Prog/homework_for_Qt/Server /home/guyver/Prog/homework_for_Qt/Server/build/debug /home/guyver/Prog/homework_for_Qt/Server/build/debug /home/guyver/Prog/homework_for_Qt/Server/build/debug/CMakeFiles/serverChat_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serverChat_autogen.dir/depend
