# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/filipjedrzejewski/cpp/Asteroids

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/filipjedrzejewski/cpp/Asteroids

# Include any dependencies generated for this target.
include CMakeFiles/Asteroids.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Asteroids.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Asteroids.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Asteroids.dir/flags.make

CMakeFiles/Asteroids.dir/src/main.cpp.o: CMakeFiles/Asteroids.dir/flags.make
CMakeFiles/Asteroids.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/Asteroids.dir/src/main.cpp.o: CMakeFiles/Asteroids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/filipjedrzejewski/cpp/Asteroids/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Asteroids.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Asteroids.dir/src/main.cpp.o -MF CMakeFiles/Asteroids.dir/src/main.cpp.o.d -o CMakeFiles/Asteroids.dir/src/main.cpp.o -c /home/filipjedrzejewski/cpp/Asteroids/src/main.cpp

CMakeFiles/Asteroids.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Asteroids.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filipjedrzejewski/cpp/Asteroids/src/main.cpp > CMakeFiles/Asteroids.dir/src/main.cpp.i

CMakeFiles/Asteroids.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Asteroids.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filipjedrzejewski/cpp/Asteroids/src/main.cpp -o CMakeFiles/Asteroids.dir/src/main.cpp.s

CMakeFiles/Asteroids.dir/src/Game.cpp.o: CMakeFiles/Asteroids.dir/flags.make
CMakeFiles/Asteroids.dir/src/Game.cpp.o: src/Game.cpp
CMakeFiles/Asteroids.dir/src/Game.cpp.o: CMakeFiles/Asteroids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/filipjedrzejewski/cpp/Asteroids/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Asteroids.dir/src/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Asteroids.dir/src/Game.cpp.o -MF CMakeFiles/Asteroids.dir/src/Game.cpp.o.d -o CMakeFiles/Asteroids.dir/src/Game.cpp.o -c /home/filipjedrzejewski/cpp/Asteroids/src/Game.cpp

CMakeFiles/Asteroids.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Asteroids.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filipjedrzejewski/cpp/Asteroids/src/Game.cpp > CMakeFiles/Asteroids.dir/src/Game.cpp.i

CMakeFiles/Asteroids.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Asteroids.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filipjedrzejewski/cpp/Asteroids/src/Game.cpp -o CMakeFiles/Asteroids.dir/src/Game.cpp.s

CMakeFiles/Asteroids.dir/src/GameEngine.cpp.o: CMakeFiles/Asteroids.dir/flags.make
CMakeFiles/Asteroids.dir/src/GameEngine.cpp.o: src/GameEngine.cpp
CMakeFiles/Asteroids.dir/src/GameEngine.cpp.o: CMakeFiles/Asteroids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/filipjedrzejewski/cpp/Asteroids/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Asteroids.dir/src/GameEngine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Asteroids.dir/src/GameEngine.cpp.o -MF CMakeFiles/Asteroids.dir/src/GameEngine.cpp.o.d -o CMakeFiles/Asteroids.dir/src/GameEngine.cpp.o -c /home/filipjedrzejewski/cpp/Asteroids/src/GameEngine.cpp

CMakeFiles/Asteroids.dir/src/GameEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Asteroids.dir/src/GameEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filipjedrzejewski/cpp/Asteroids/src/GameEngine.cpp > CMakeFiles/Asteroids.dir/src/GameEngine.cpp.i

CMakeFiles/Asteroids.dir/src/GameEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Asteroids.dir/src/GameEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filipjedrzejewski/cpp/Asteroids/src/GameEngine.cpp -o CMakeFiles/Asteroids.dir/src/GameEngine.cpp.s

CMakeFiles/Asteroids.dir/src/Player.cpp.o: CMakeFiles/Asteroids.dir/flags.make
CMakeFiles/Asteroids.dir/src/Player.cpp.o: src/Player.cpp
CMakeFiles/Asteroids.dir/src/Player.cpp.o: CMakeFiles/Asteroids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/filipjedrzejewski/cpp/Asteroids/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Asteroids.dir/src/Player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Asteroids.dir/src/Player.cpp.o -MF CMakeFiles/Asteroids.dir/src/Player.cpp.o.d -o CMakeFiles/Asteroids.dir/src/Player.cpp.o -c /home/filipjedrzejewski/cpp/Asteroids/src/Player.cpp

CMakeFiles/Asteroids.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Asteroids.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filipjedrzejewski/cpp/Asteroids/src/Player.cpp > CMakeFiles/Asteroids.dir/src/Player.cpp.i

CMakeFiles/Asteroids.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Asteroids.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filipjedrzejewski/cpp/Asteroids/src/Player.cpp -o CMakeFiles/Asteroids.dir/src/Player.cpp.s

CMakeFiles/Asteroids.dir/src/Asteroid.cpp.o: CMakeFiles/Asteroids.dir/flags.make
CMakeFiles/Asteroids.dir/src/Asteroid.cpp.o: src/Asteroid.cpp
CMakeFiles/Asteroids.dir/src/Asteroid.cpp.o: CMakeFiles/Asteroids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/filipjedrzejewski/cpp/Asteroids/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Asteroids.dir/src/Asteroid.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Asteroids.dir/src/Asteroid.cpp.o -MF CMakeFiles/Asteroids.dir/src/Asteroid.cpp.o.d -o CMakeFiles/Asteroids.dir/src/Asteroid.cpp.o -c /home/filipjedrzejewski/cpp/Asteroids/src/Asteroid.cpp

CMakeFiles/Asteroids.dir/src/Asteroid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Asteroids.dir/src/Asteroid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filipjedrzejewski/cpp/Asteroids/src/Asteroid.cpp > CMakeFiles/Asteroids.dir/src/Asteroid.cpp.i

CMakeFiles/Asteroids.dir/src/Asteroid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Asteroids.dir/src/Asteroid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filipjedrzejewski/cpp/Asteroids/src/Asteroid.cpp -o CMakeFiles/Asteroids.dir/src/Asteroid.cpp.s

CMakeFiles/Asteroids.dir/src/Bullet.cpp.o: CMakeFiles/Asteroids.dir/flags.make
CMakeFiles/Asteroids.dir/src/Bullet.cpp.o: src/Bullet.cpp
CMakeFiles/Asteroids.dir/src/Bullet.cpp.o: CMakeFiles/Asteroids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/filipjedrzejewski/cpp/Asteroids/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Asteroids.dir/src/Bullet.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Asteroids.dir/src/Bullet.cpp.o -MF CMakeFiles/Asteroids.dir/src/Bullet.cpp.o.d -o CMakeFiles/Asteroids.dir/src/Bullet.cpp.o -c /home/filipjedrzejewski/cpp/Asteroids/src/Bullet.cpp

CMakeFiles/Asteroids.dir/src/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Asteroids.dir/src/Bullet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filipjedrzejewski/cpp/Asteroids/src/Bullet.cpp > CMakeFiles/Asteroids.dir/src/Bullet.cpp.i

CMakeFiles/Asteroids.dir/src/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Asteroids.dir/src/Bullet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filipjedrzejewski/cpp/Asteroids/src/Bullet.cpp -o CMakeFiles/Asteroids.dir/src/Bullet.cpp.s

CMakeFiles/Asteroids.dir/src/GameObject.cpp.o: CMakeFiles/Asteroids.dir/flags.make
CMakeFiles/Asteroids.dir/src/GameObject.cpp.o: src/GameObject.cpp
CMakeFiles/Asteroids.dir/src/GameObject.cpp.o: CMakeFiles/Asteroids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/filipjedrzejewski/cpp/Asteroids/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Asteroids.dir/src/GameObject.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Asteroids.dir/src/GameObject.cpp.o -MF CMakeFiles/Asteroids.dir/src/GameObject.cpp.o.d -o CMakeFiles/Asteroids.dir/src/GameObject.cpp.o -c /home/filipjedrzejewski/cpp/Asteroids/src/GameObject.cpp

CMakeFiles/Asteroids.dir/src/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Asteroids.dir/src/GameObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filipjedrzejewski/cpp/Asteroids/src/GameObject.cpp > CMakeFiles/Asteroids.dir/src/GameObject.cpp.i

CMakeFiles/Asteroids.dir/src/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Asteroids.dir/src/GameObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filipjedrzejewski/cpp/Asteroids/src/GameObject.cpp -o CMakeFiles/Asteroids.dir/src/GameObject.cpp.s

# Object files for target Asteroids
Asteroids_OBJECTS = \
"CMakeFiles/Asteroids.dir/src/main.cpp.o" \
"CMakeFiles/Asteroids.dir/src/Game.cpp.o" \
"CMakeFiles/Asteroids.dir/src/GameEngine.cpp.o" \
"CMakeFiles/Asteroids.dir/src/Player.cpp.o" \
"CMakeFiles/Asteroids.dir/src/Asteroid.cpp.o" \
"CMakeFiles/Asteroids.dir/src/Bullet.cpp.o" \
"CMakeFiles/Asteroids.dir/src/GameObject.cpp.o"

# External object files for target Asteroids
Asteroids_EXTERNAL_OBJECTS =

Asteroids: CMakeFiles/Asteroids.dir/src/main.cpp.o
Asteroids: CMakeFiles/Asteroids.dir/src/Game.cpp.o
Asteroids: CMakeFiles/Asteroids.dir/src/GameEngine.cpp.o
Asteroids: CMakeFiles/Asteroids.dir/src/Player.cpp.o
Asteroids: CMakeFiles/Asteroids.dir/src/Asteroid.cpp.o
Asteroids: CMakeFiles/Asteroids.dir/src/Bullet.cpp.o
Asteroids: CMakeFiles/Asteroids.dir/src/GameObject.cpp.o
Asteroids: CMakeFiles/Asteroids.dir/build.make
Asteroids: /usr/lib64/libsfml-graphics.so.2.6.1
Asteroids: /usr/lib64/libsfml-window.so.2.6.1
Asteroids: /usr/lib64/libsfml-system.so.2.6.1
Asteroids: CMakeFiles/Asteroids.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/filipjedrzejewski/cpp/Asteroids/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Asteroids"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Asteroids.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Asteroids.dir/build: Asteroids
.PHONY : CMakeFiles/Asteroids.dir/build

CMakeFiles/Asteroids.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Asteroids.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Asteroids.dir/clean

CMakeFiles/Asteroids.dir/depend:
	cd /home/filipjedrzejewski/cpp/Asteroids && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filipjedrzejewski/cpp/Asteroids /home/filipjedrzejewski/cpp/Asteroids /home/filipjedrzejewski/cpp/Asteroids /home/filipjedrzejewski/cpp/Asteroids /home/filipjedrzejewski/cpp/Asteroids/CMakeFiles/Asteroids.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Asteroids.dir/depend

