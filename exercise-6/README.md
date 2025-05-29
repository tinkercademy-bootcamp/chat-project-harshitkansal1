# Exercise 6

**Update this README with your answers to the questions below.**

## Adding Third Party Libraries or Source Code to Your Project

- There is a new file `src/spdlog-hello-world-main.cc`
- It uses the spdlog and fmt libraries. 
  [More info here](https://github.com/gabime/spdlog) - Fast C++ logging 
  library with various sink types and formatting options
- How do you compile this file using the `g++` CLI?
  - i used the command g++ -Iinclude spdlog-hello-world-main.cc after putting the include folder in the same directory
- What do you need to change in your makefile to use this library?
  - Just add -Iinclude in the CXXFLAGS in the makefile and it worked
- How many different ways can this library be added into your project?
  - There are two ways, one is the header only version where you just add the include folder to my directory or in the compiled version i can compile and build the libary then use it.
- What are the tradeoffs in the different ways?
  - Header-only version is easy to setup and use but the compile times are longer, where as the in the compiled version, compile times are smaller but it is harder to setup.
- Why are there so many different ways to do it?
  - The choice to use a particular way depends on the size of the project, and other requirements, for a small project header only version might work fine, and for a big project you might need to use the compiled version if you need smaller compile times.
  
## Static Linking vs Dynamic Linking

- What are the differences between static linking and dynamic linking?
  - Static linking copies the entire library code which is being used in the executable itself, whereas in dynamic linking, shared library code from the system is used.
- What are the tradeoffs?
  - in static linking, the executable size is larger, in case of any updates to library executable has to be recompiled, compile time is slower, whereas in dynamic linking, executable size is smaller, in case of updates to library no need to recompile and compile time is faster, but its deployment is complex compared to static linking.
- How do you enable static linking or dynamic linking in your makefile?
  - By default, the linking is dynamic while using g++. To enable static linking we can use the -static flag, but that will require us to statically link the standard libraries as well, for statically linking some specific libraries we can provide their .a files in the g++ command.

## Git Clone and Building from Source

- Where is `g++` looking for the include files and library files?
  - g++ looks for include files and library files in some default system paths like /usr/include , /usr/local/include, /usr/lib , /usr/local/lib, if we want to add place we can do so using -I and -L flag respectively.
- How do you find out?
  - I found commands like echo | g++ -E -x c++ - -v and g++ -print-search-dirs online and they seem to work.

## C++ Package Managers

- Why are there so many C++ package managers?
  - Because there is no official c++ package manager and c++ is a diverse language with a lot of different use cases, different package managers are more suited to different use cases.
- Which one is the best one?
  - The best package manager depends upon one's needs and project, some good package managers are conan, vcpkg, hunter, etc.
- Which are the most notable ways to manage the compilation of C++ projects?