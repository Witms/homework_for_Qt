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
CMAKE_SOURCE_DIR = /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug

# Utility rule file for translate_my_ru.

# Include the progress variables for this target.
include CMakeFiles/translate_my_ru.dir/progress.make

CMakeFiles/translate_my_ru: ../../translations/my_ru.ts


../../translations/my_ru.ts: CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp
../../translations/my_ru.ts: Chat_autogen/EXY53EAHJJ/moc_loginform.cpp
../../translations/my_ru.ts: Chat_autogen/EXY53EAHJJ/moc_mainwindow.cpp
../../translations/my_ru.ts: Chat_autogen/EXY53EAHJJ/moc_registrationform.cpp
../../translations/my_ru.ts: Chat_autogen/moc_predefs.h
../../translations/my_ru.ts: Chat_autogen/mocs_compilation.cpp
../../translations/my_ru.ts: ui_loginform.h
../../translations/my_ru.ts: ui_mainwindow.h
../../translations/my_ru.ts: ui_registrationform.h
../../translations/my_ru.ts: ../../sources/ConnectToDB.cpp
../../translations/my_ru.ts: ../../sources/ConnectToDB.h
../../translations/my_ru.ts: ../../sources/Message.cpp
../../translations/my_ru.ts: ../../sources/Message.h
../../translations/my_ru.ts: ../../sources/User.cpp
../../translations/my_ru.ts: ../../sources/User.h
../../translations/my_ru.ts: ../../sources/loginform.cpp
../../translations/my_ru.ts: ../../sources/loginform.h
../../translations/my_ru.ts: ../../sources/main.cpp
../../translations/my_ru.ts: ../../sources/mainwindow.cpp
../../translations/my_ru.ts: ../../sources/mainwindow.h
../../translations/my_ru.ts: ../../sources/registrationform.cpp
../../translations/my_ru.ts: ../../sources/registrationform.h
../../translations/my_ru.ts: ../../sources/startscreen.cpp
../../translations/my_ru.ts: ../../sources/startscreen.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../../translations/my_ru.ts"
	/usr/lib/qt5/bin/lupdate -recursive /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg -ts /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/translations/my_ru.ts

ui_loginform.h: ../../sources/loginform.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating ui_loginform.h"
	/usr/lib/qt5/bin/uic -o /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug/ui_loginform.h /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/sources/loginform.ui

ui_mainwindow.h: ../../sources/mainwindow.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating ui_mainwindow.h"
	/usr/lib/qt5/bin/uic -o /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug/ui_mainwindow.h /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/sources/mainwindow.ui

ui_registrationform.h: ../../sources/registrationform.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating ui_registrationform.h"
	/usr/lib/qt5/bin/uic -o /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug/ui_registrationform.h /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/sources/registrationform.ui

translate_my_ru: CMakeFiles/translate_my_ru
translate_my_ru: ../../translations/my_ru.ts
translate_my_ru: ui_loginform.h
translate_my_ru: ui_mainwindow.h
translate_my_ru: ui_registrationform.h
translate_my_ru: CMakeFiles/translate_my_ru.dir/build.make

.PHONY : translate_my_ru

# Rule to build all files generated by this target.
CMakeFiles/translate_my_ru.dir/build: translate_my_ru

.PHONY : CMakeFiles/translate_my_ru.dir/build

CMakeFiles/translate_my_ru.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/translate_my_ru.dir/cmake_clean.cmake
.PHONY : CMakeFiles/translate_my_ru.dir/clean

CMakeFiles/translate_my_ru.dir/depend:
	cd /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug /home/guyver/Prog/Qt_from_SkillFactory/Homework_Qt/clientProg/build/debug/CMakeFiles/translate_my_ru.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/translate_my_ru.dir/depend

