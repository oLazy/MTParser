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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.20.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.20.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/eric79/CLionProjects/myparser/MTParser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/eric79/CLionProjects/myparser/MTParser/build

# Include any dependencies generated for this target.
include CMakeFiles/MTParser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MTParser.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MTParser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MTParser.dir/flags.make

CMakeFiles/MTParser.dir/main.cpp.o: CMakeFiles/MTParser.dir/flags.make
CMakeFiles/MTParser.dir/main.cpp.o: ../main.cpp
CMakeFiles/MTParser.dir/main.cpp.o: CMakeFiles/MTParser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/eric79/CLionProjects/myparser/MTParser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MTParser.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MTParser.dir/main.cpp.o -MF CMakeFiles/MTParser.dir/main.cpp.o.d -o CMakeFiles/MTParser.dir/main.cpp.o -c /Users/eric79/CLionProjects/myparser/MTParser/main.cpp

CMakeFiles/MTParser.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MTParser.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/eric79/CLionProjects/myparser/MTParser/main.cpp > CMakeFiles/MTParser.dir/main.cpp.i

CMakeFiles/MTParser.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MTParser.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/eric79/CLionProjects/myparser/MTParser/main.cpp -o CMakeFiles/MTParser.dir/main.cpp.s

CMakeFiles/MTParser.dir/Tokenizer.cpp.o: CMakeFiles/MTParser.dir/flags.make
CMakeFiles/MTParser.dir/Tokenizer.cpp.o: ../Tokenizer.cpp
CMakeFiles/MTParser.dir/Tokenizer.cpp.o: CMakeFiles/MTParser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/eric79/CLionProjects/myparser/MTParser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MTParser.dir/Tokenizer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MTParser.dir/Tokenizer.cpp.o -MF CMakeFiles/MTParser.dir/Tokenizer.cpp.o.d -o CMakeFiles/MTParser.dir/Tokenizer.cpp.o -c /Users/eric79/CLionProjects/myparser/MTParser/Tokenizer.cpp

CMakeFiles/MTParser.dir/Tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MTParser.dir/Tokenizer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/eric79/CLionProjects/myparser/MTParser/Tokenizer.cpp > CMakeFiles/MTParser.dir/Tokenizer.cpp.i

CMakeFiles/MTParser.dir/Tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MTParser.dir/Tokenizer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/eric79/CLionProjects/myparser/MTParser/Tokenizer.cpp -o CMakeFiles/MTParser.dir/Tokenizer.cpp.s

# Object files for target MTParser
MTParser_OBJECTS = \
"CMakeFiles/MTParser.dir/main.cpp.o" \
"CMakeFiles/MTParser.dir/Tokenizer.cpp.o"

# External object files for target MTParser
MTParser_EXTERNAL_OBJECTS =

MTParser: CMakeFiles/MTParser.dir/main.cpp.o
MTParser: CMakeFiles/MTParser.dir/Tokenizer.cpp.o
MTParser: CMakeFiles/MTParser.dir/build.make
MTParser: CMakeFiles/MTParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/eric79/CLionProjects/myparser/MTParser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MTParser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MTParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MTParser.dir/build: MTParser
.PHONY : CMakeFiles/MTParser.dir/build

CMakeFiles/MTParser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MTParser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MTParser.dir/clean

CMakeFiles/MTParser.dir/depend:
	cd /Users/eric79/CLionProjects/myparser/MTParser/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eric79/CLionProjects/myparser/MTParser /Users/eric79/CLionProjects/myparser/MTParser /Users/eric79/CLionProjects/myparser/MTParser/build /Users/eric79/CLionProjects/myparser/MTParser/build /Users/eric79/CLionProjects/myparser/MTParser/build/CMakeFiles/MTParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MTParser.dir/depend

