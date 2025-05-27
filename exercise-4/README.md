# Exercise 4

**Update this README with your answers to the questions below.**

## Learning Multi-File C++ Projects

- Move code that can be shared between `tcp_echo_server.cc` and 
  `tcp_echo_client.cc` to separate `.h` and `.cc` files
  - After commiting once i learnt that only template functions or inline functions should be defined entirely in the header and rest it should only contain the declarations, so made the required changes.
- How would you compile from the command line?
  first compile the common.cc in a common.o object file and that use that with the g++ commands to compile the server and client executables. Example g++ tcp_echo_client.cpp common.o -o client
- How would you compile using make?
  - Just make a new target for common.o with the command g++ -c common.cc -o common.o and add common.o in the existing g++ commands for server client, along with adding dependancies for it in the targets.
- How would you compile using VS Code?
  - We can configure the tasks.json file in .vscode folder with the commands, or just run them by opening a terminal in vs code.

### Compiling vs Linking

- What is the difference between compiling and linking in C++?
  - First step is compiling which takes the code for each individual files and converts it into an object file which contains the assembly code and some other instructions for the linker to use, linker links the various objects files and the library files together to make the final executable.
- What is the difference between creating an executable and creating a 
  library?
- How do you compile a library, and then use that library to compile an
  executable?

### Reminder 
[Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
fundamentals with practical examples and common patterns.

## Experiments in Performance

- Is it better to have many small files spread across many directories, or
  a few large files across fewer directories?
- Is there a difference in compilation time between the two?
- How can you assess performance other than compilation speed?