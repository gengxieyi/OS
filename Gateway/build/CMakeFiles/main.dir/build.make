# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/OS/Gateway

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/OS/Gateway/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/Common.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Common.cpp.o: ../Common.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/OS/Gateway/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/Common.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/Common.cpp.o -c /root/OS/Gateway/Common.cpp

CMakeFiles/main.dir/Common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Common.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/OS/Gateway/Common.cpp > CMakeFiles/main.dir/Common.cpp.i

CMakeFiles/main.dir/Common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Common.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/OS/Gateway/Common.cpp -o CMakeFiles/main.dir/Common.cpp.s

CMakeFiles/main.dir/Common.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/Common.cpp.o.requires

CMakeFiles/main.dir/Common.cpp.o.provides: CMakeFiles/main.dir/Common.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Common.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/Common.cpp.o.provides

CMakeFiles/main.dir/Common.cpp.o.provides.build: CMakeFiles/main.dir/Common.cpp.o

CMakeFiles/main.dir/OpCtx.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/OpCtx.cpp.o: ../OpCtx.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/OS/Gateway/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/OpCtx.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/OpCtx.cpp.o -c /root/OS/Gateway/OpCtx.cpp

CMakeFiles/main.dir/OpCtx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/OpCtx.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/OS/Gateway/OpCtx.cpp > CMakeFiles/main.dir/OpCtx.cpp.i

CMakeFiles/main.dir/OpCtx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/OpCtx.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/OS/Gateway/OpCtx.cpp -o CMakeFiles/main.dir/OpCtx.cpp.s

CMakeFiles/main.dir/OpCtx.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/OpCtx.cpp.o.requires

CMakeFiles/main.dir/OpCtx.cpp.o.provides: CMakeFiles/main.dir/OpCtx.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/OpCtx.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/OpCtx.cpp.o.provides

CMakeFiles/main.dir/OpCtx.cpp.o.provides.build: CMakeFiles/main.dir/OpCtx.cpp.o

CMakeFiles/main.dir/Server.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Server.cpp.o: ../Server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/OS/Gateway/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/Server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/Server.cpp.o -c /root/OS/Gateway/Server.cpp

CMakeFiles/main.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/OS/Gateway/Server.cpp > CMakeFiles/main.dir/Server.cpp.i

CMakeFiles/main.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/OS/Gateway/Server.cpp -o CMakeFiles/main.dir/Server.cpp.s

CMakeFiles/main.dir/Server.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/Server.cpp.o.requires

CMakeFiles/main.dir/Server.cpp.o.provides: CMakeFiles/main.dir/Server.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Server.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/Server.cpp.o.provides

CMakeFiles/main.dir/Server.cpp.o.provides.build: CMakeFiles/main.dir/Server.cpp.o

CMakeFiles/main.dir/ServerManager.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/ServerManager.cpp.o: ../ServerManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/OS/Gateway/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/ServerManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/ServerManager.cpp.o -c /root/OS/Gateway/ServerManager.cpp

CMakeFiles/main.dir/ServerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/ServerManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/OS/Gateway/ServerManager.cpp > CMakeFiles/main.dir/ServerManager.cpp.i

CMakeFiles/main.dir/ServerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/ServerManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/OS/Gateway/ServerManager.cpp -o CMakeFiles/main.dir/ServerManager.cpp.s

CMakeFiles/main.dir/ServerManager.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/ServerManager.cpp.o.requires

CMakeFiles/main.dir/ServerManager.cpp.o.provides: CMakeFiles/main.dir/ServerManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/ServerManager.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/ServerManager.cpp.o.provides

CMakeFiles/main.dir/ServerManager.cpp.o.provides.build: CMakeFiles/main.dir/ServerManager.cpp.o

CMakeFiles/main.dir/Worker.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Worker.cpp.o: ../Worker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/OS/Gateway/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/Worker.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/Worker.cpp.o -c /root/OS/Gateway/Worker.cpp

CMakeFiles/main.dir/Worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Worker.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/OS/Gateway/Worker.cpp > CMakeFiles/main.dir/Worker.cpp.i

CMakeFiles/main.dir/Worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Worker.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/OS/Gateway/Worker.cpp -o CMakeFiles/main.dir/Worker.cpp.s

CMakeFiles/main.dir/Worker.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/Worker.cpp.o.requires

CMakeFiles/main.dir/Worker.cpp.o.provides: CMakeFiles/main.dir/Worker.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Worker.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/Worker.cpp.o.provides

CMakeFiles/main.dir/Worker.cpp.o.provides.build: CMakeFiles/main.dir/Worker.cpp.o

CMakeFiles/main.dir/Connection.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Connection.cpp.o: ../Connection.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/OS/Gateway/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/Connection.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/Connection.cpp.o -c /root/OS/Gateway/Connection.cpp

CMakeFiles/main.dir/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Connection.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/OS/Gateway/Connection.cpp > CMakeFiles/main.dir/Connection.cpp.i

CMakeFiles/main.dir/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Connection.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/OS/Gateway/Connection.cpp -o CMakeFiles/main.dir/Connection.cpp.s

CMakeFiles/main.dir/Connection.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/Connection.cpp.o.requires

CMakeFiles/main.dir/Connection.cpp.o.provides: CMakeFiles/main.dir/Connection.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Connection.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/Connection.cpp.o.provides

CMakeFiles/main.dir/Connection.cpp.o.provides.build: CMakeFiles/main.dir/Connection.cpp.o

CMakeFiles/main.dir/Main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Main.cpp.o: ../Main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/OS/Gateway/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/Main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/Main.cpp.o -c /root/OS/Gateway/Main.cpp

CMakeFiles/main.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/OS/Gateway/Main.cpp > CMakeFiles/main.dir/Main.cpp.i

CMakeFiles/main.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/OS/Gateway/Main.cpp -o CMakeFiles/main.dir/Main.cpp.s

CMakeFiles/main.dir/Main.cpp.o.requires:
.PHONY : CMakeFiles/main.dir/Main.cpp.o.requires

CMakeFiles/main.dir/Main.cpp.o.provides: CMakeFiles/main.dir/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Main.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/Main.cpp.o.provides

CMakeFiles/main.dir/Main.cpp.o.provides.build: CMakeFiles/main.dir/Main.cpp.o

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/Common.cpp.o" \
"CMakeFiles/main.dir/OpCtx.cpp.o" \
"CMakeFiles/main.dir/Server.cpp.o" \
"CMakeFiles/main.dir/ServerManager.cpp.o" \
"CMakeFiles/main.dir/Worker.cpp.o" \
"CMakeFiles/main.dir/Connection.cpp.o" \
"CMakeFiles/main.dir/Main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/Common.cpp.o
main: CMakeFiles/main.dir/OpCtx.cpp.o
main: CMakeFiles/main.dir/Server.cpp.o
main: CMakeFiles/main.dir/ServerManager.cpp.o
main: CMakeFiles/main.dir/Worker.cpp.o
main: CMakeFiles/main.dir/Connection.cpp.o
main: CMakeFiles/main.dir/Main.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/Common.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/OpCtx.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/Server.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/ServerManager.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/Worker.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/Connection.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/Main.cpp.o.requires
.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /root/OS/Gateway/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/OS/Gateway /root/OS/Gateway /root/OS/Gateway/build /root/OS/Gateway/build /root/OS/Gateway/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

