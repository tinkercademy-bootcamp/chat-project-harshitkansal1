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
- Why are there so many different ways to do it?
  
## Static Linking vs Dynamic Linking

- What are the differences between static linking and dynamic linking?
- What are the tradeoffs?
- How do you enable static linking or dynamic linking in your makefile?

## Git Clone and Building from Source

- Where is `g++` looking for the include files and library files?
- How do you find out?

## C++ Package Managers

- Why are there so many C++ package managers?
- Which one is the best one?
- Which are the most notable ways to manage the compilation of C++ projects?