# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/build

# Include any dependencies generated for this target.
include CMakeFiles/I2C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/I2C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/I2C.dir/flags.make

CMakeFiles/I2C.dir/I2C.cpp.o: CMakeFiles/I2C.dir/flags.make
CMakeFiles/I2C.dir/I2C.cpp.o: ../I2C.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/I2C.dir/I2C.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/I2C.dir/I2C.cpp.o -c /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/I2C.cpp

CMakeFiles/I2C.dir/I2C.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/I2C.dir/I2C.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/I2C.cpp > CMakeFiles/I2C.dir/I2C.cpp.i

CMakeFiles/I2C.dir/I2C.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/I2C.dir/I2C.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/I2C.cpp -o CMakeFiles/I2C.dir/I2C.cpp.s

CMakeFiles/I2C.dir/I2C.cpp.o.requires:

.PHONY : CMakeFiles/I2C.dir/I2C.cpp.o.requires

CMakeFiles/I2C.dir/I2C.cpp.o.provides: CMakeFiles/I2C.dir/I2C.cpp.o.requires
	$(MAKE) -f CMakeFiles/I2C.dir/build.make CMakeFiles/I2C.dir/I2C.cpp.o.provides.build
.PHONY : CMakeFiles/I2C.dir/I2C.cpp.o.provides

CMakeFiles/I2C.dir/I2C.cpp.o.provides.build: CMakeFiles/I2C.dir/I2C.cpp.o


CMakeFiles/I2C.dir/I2CMain.cpp.o: CMakeFiles/I2C.dir/flags.make
CMakeFiles/I2C.dir/I2CMain.cpp.o: ../I2CMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/I2C.dir/I2CMain.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/I2C.dir/I2CMain.cpp.o -c /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/I2CMain.cpp

CMakeFiles/I2C.dir/I2CMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/I2C.dir/I2CMain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/I2CMain.cpp > CMakeFiles/I2C.dir/I2CMain.cpp.i

CMakeFiles/I2C.dir/I2CMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/I2C.dir/I2CMain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/I2CMain.cpp -o CMakeFiles/I2C.dir/I2CMain.cpp.s

CMakeFiles/I2C.dir/I2CMain.cpp.o.requires:

.PHONY : CMakeFiles/I2C.dir/I2CMain.cpp.o.requires

CMakeFiles/I2C.dir/I2CMain.cpp.o.provides: CMakeFiles/I2C.dir/I2CMain.cpp.o.requires
	$(MAKE) -f CMakeFiles/I2C.dir/build.make CMakeFiles/I2C.dir/I2CMain.cpp.o.provides.build
.PHONY : CMakeFiles/I2C.dir/I2CMain.cpp.o.provides

CMakeFiles/I2C.dir/I2CMain.cpp.o.provides.build: CMakeFiles/I2C.dir/I2CMain.cpp.o


# Object files for target I2C
I2C_OBJECTS = \
"CMakeFiles/I2C.dir/I2C.cpp.o" \
"CMakeFiles/I2C.dir/I2CMain.cpp.o"

# External object files for target I2C
I2C_EXTERNAL_OBJECTS =

I2C: CMakeFiles/I2C.dir/I2C.cpp.o
I2C: CMakeFiles/I2C.dir/I2CMain.cpp.o
I2C: CMakeFiles/I2C.dir/build.make
I2C: CMakeFiles/I2C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable I2C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/I2C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/I2C.dir/build: I2C

.PHONY : CMakeFiles/I2C.dir/build

CMakeFiles/I2C.dir/requires: CMakeFiles/I2C.dir/I2C.cpp.o.requires
CMakeFiles/I2C.dir/requires: CMakeFiles/I2C.dir/I2CMain.cpp.o.requires

.PHONY : CMakeFiles/I2C.dir/requires

CMakeFiles/I2C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/I2C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/I2C.dir/clean

CMakeFiles/I2C.dir/depend:
	cd /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/build /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/build /home/ttase97/HEVT/UGV/Follow_Vehicle/I2C_Code/Jetson/build/CMakeFiles/I2C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/I2C.dir/depend

