# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/164/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/164/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tardis3/ILab_MIPT/HW_3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tardis3/ILab_MIPT/HW_3D/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW_3D.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/HW_3D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW_3D.dir/flags.make

CMakeFiles/HW_3D.dir/main.cpp.o: CMakeFiles/HW_3D.dir/flags.make
CMakeFiles/HW_3D.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tardis3/ILab_MIPT/HW_3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW_3D.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW_3D.dir/main.cpp.o -c /home/tardis3/ILab_MIPT/HW_3D/main.cpp

CMakeFiles/HW_3D.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW_3D.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tardis3/ILab_MIPT/HW_3D/main.cpp > CMakeFiles/HW_3D.dir/main.cpp.i

CMakeFiles/HW_3D.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW_3D.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tardis3/ILab_MIPT/HW_3D/main.cpp -o CMakeFiles/HW_3D.dir/main.cpp.s

# Object files for target HW_3D
HW_3D_OBJECTS = \
"CMakeFiles/HW_3D.dir/main.cpp.o"

# External object files for target HW_3D
HW_3D_EXTERNAL_OBJECTS =

HW_3D: CMakeFiles/HW_3D.dir/main.cpp.o
HW_3D: CMakeFiles/HW_3D.dir/build.make
HW_3D: CMakeFiles/HW_3D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tardis3/ILab_MIPT/HW_3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HW_3D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW_3D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW_3D.dir/build: HW_3D
.PHONY : CMakeFiles/HW_3D.dir/build

CMakeFiles/HW_3D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW_3D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW_3D.dir/clean

CMakeFiles/HW_3D.dir/depend:
	cd /home/tardis3/ILab_MIPT/HW_3D/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tardis3/ILab_MIPT/HW_3D /home/tardis3/ILab_MIPT/HW_3D /home/tardis3/ILab_MIPT/HW_3D/cmake-build-debug /home/tardis3/ILab_MIPT/HW_3D/cmake-build-debug /home/tardis3/ILab_MIPT/HW_3D/cmake-build-debug/CMakeFiles/HW_3D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW_3D.dir/depend
