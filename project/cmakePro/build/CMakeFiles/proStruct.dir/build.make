# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\cmake-3.22.1-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\cmake-3.22.1-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\c_family\c\learnC\project\cmakePro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\c_family\c\learnC\project\cmakePro\build

# Include any dependencies generated for this target.
include CMakeFiles/proStruct.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/proStruct.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/proStruct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proStruct.dir/flags.make

CMakeFiles/proStruct.dir/main.cpp.obj: CMakeFiles/proStruct.dir/flags.make
CMakeFiles/proStruct.dir/main.cpp.obj: ../main.cpp
CMakeFiles/proStruct.dir/main.cpp.obj: CMakeFiles/proStruct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\c_family\c\learnC\project\cmakePro\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proStruct.dir/main.cpp.obj"
	D:\compiler\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proStruct.dir/main.cpp.obj -MF CMakeFiles\proStruct.dir\main.cpp.obj.d -o CMakeFiles\proStruct.dir\main.cpp.obj -c D:\c_family\c\learnC\project\cmakePro\main.cpp

CMakeFiles/proStruct.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proStruct.dir/main.cpp.i"
	D:\compiler\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\c_family\c\learnC\project\cmakePro\main.cpp > CMakeFiles\proStruct.dir\main.cpp.i

CMakeFiles/proStruct.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proStruct.dir/main.cpp.s"
	D:\compiler\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\c_family\c\learnC\project\cmakePro\main.cpp -o CMakeFiles\proStruct.dir\main.cpp.s

CMakeFiles/proStruct.dir/source.cpp.obj: CMakeFiles/proStruct.dir/flags.make
CMakeFiles/proStruct.dir/source.cpp.obj: ../source.cpp
CMakeFiles/proStruct.dir/source.cpp.obj: CMakeFiles/proStruct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\c_family\c\learnC\project\cmakePro\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/proStruct.dir/source.cpp.obj"
	D:\compiler\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proStruct.dir/source.cpp.obj -MF CMakeFiles\proStruct.dir\source.cpp.obj.d -o CMakeFiles\proStruct.dir\source.cpp.obj -c D:\c_family\c\learnC\project\cmakePro\source.cpp

CMakeFiles/proStruct.dir/source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proStruct.dir/source.cpp.i"
	D:\compiler\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\c_family\c\learnC\project\cmakePro\source.cpp > CMakeFiles\proStruct.dir\source.cpp.i

CMakeFiles/proStruct.dir/source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proStruct.dir/source.cpp.s"
	D:\compiler\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\c_family\c\learnC\project\cmakePro\source.cpp -o CMakeFiles\proStruct.dir\source.cpp.s

# Object files for target proStruct
proStruct_OBJECTS = \
"CMakeFiles/proStruct.dir/main.cpp.obj" \
"CMakeFiles/proStruct.dir/source.cpp.obj"

# External object files for target proStruct
proStruct_EXTERNAL_OBJECTS =

proStruct.exe: CMakeFiles/proStruct.dir/main.cpp.obj
proStruct.exe: CMakeFiles/proStruct.dir/source.cpp.obj
proStruct.exe: CMakeFiles/proStruct.dir/build.make
proStruct.exe: CMakeFiles/proStruct.dir/linklibs.rsp
proStruct.exe: CMakeFiles/proStruct.dir/objects1.rsp
proStruct.exe: CMakeFiles/proStruct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\c_family\c\learnC\project\cmakePro\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable proStruct.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\proStruct.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proStruct.dir/build: proStruct.exe
.PHONY : CMakeFiles/proStruct.dir/build

CMakeFiles/proStruct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\proStruct.dir\cmake_clean.cmake
.PHONY : CMakeFiles/proStruct.dir/clean

CMakeFiles/proStruct.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\c_family\c\learnC\project\cmakePro D:\c_family\c\learnC\project\cmakePro D:\c_family\c\learnC\project\cmakePro\build D:\c_family\c\learnC\project\cmakePro\build D:\c_family\c\learnC\project\cmakePro\build\CMakeFiles\proStruct.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proStruct.dir/depend

