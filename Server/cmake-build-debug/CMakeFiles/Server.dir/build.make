# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/main.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/main.cpp.o -c "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server/main.cpp"

CMakeFiles/Server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server/main.cpp" > CMakeFiles/Server.dir/main.cpp.i

CMakeFiles/Server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server/main.cpp" -o CMakeFiles/Server.dir/main.cpp.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/main.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/main.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server

.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server" "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server" "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server/cmake-build-debug" "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server/cmake-build-debug" "/Users/simonlaursen/Dropbox/AAU/3Semester/Programming of Complex Software Systems/ComplexSoftware_MiniProject_ClientToServer/Server/cmake-build-debug/CMakeFiles/Server.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend

