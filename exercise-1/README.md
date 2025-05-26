# Exercise 1

**Update this README with your answers to the questions below.**

## Learning How to Learn

- Answer the following questions in this file and commit and push your changes.
- Bonus sections are more difficult and optional.
- How can you find the information required to complete these tasks?
  - google the things to learn from some common sites. man command
- How can you tell if the source of your information is good? 
  - There are some well known sites, if it is well-written.
- How would you define "good" in this situation?
  - Something that helps us in understanding the topic well and solving the tasks

## Learn Basics of g++ CLI

- Compile the TCP client and server using `g++` from command line.
- What are the most important command line arguments to learn for `g++`? -c, -o, -g, -O
- What is the difference between debug vs release versions? 
  - debug version is used using normal testing, release is used for actual deployment in production
- What are the tradeoffs between debug and release versions?
  - debug takes lesser time to compile but code is slower, release takes longer to compile and the code is faster
- What arguments would you use in a debug build? 
  - -g
- What about for release?
  - -O
- What other kinds of build types are useful?
  - profiling build, sanitized build 

## Learn Basics of Make

- Create a Makefile that will speed up the process.
- [Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
  fundamentals with practical examples and common patterns.
- How else can you learn about make? 
  - Ask ChatGPT any doubts or look up some other websites
- How can you tell if the resource you are using is correct?
  - confirm with some other resources, generally standard sites are correct
- Create a makefile such that when you run `make` with no arguments, it will:
  - Create `build/` directory if it does not exist
  - Create executables **client** and **server** in `build/`, if needed
  - How does make know when it needs to rebuild the executables? 
    - it just checks if the prerequisites are newer than the target, executables in this case.
  - Change your Makefile such that `make clean` will remove `build/` and all
    its contents
- What are the most important command line arguments to learn for make?
  - -k, -i
- What are the most important directives to learn about in Makefile?
  - targets, variables, pattern rules
- What are the most important commands to implement in your Makefile?
  - use commands like g++, mkdir, rm to implement targets like server, client, all, clean
- Which ones are essential, which ones are nice to haves?

## Learn Basics of Git

- Read through the code in `src/`
- Answer any `#Questions` as a comment
- Commit and push your changes to git
- Each commit should be responding to a single task or question
- Why is it important to keep your commit to a single task or question?
  - helps keep track
- Is it better to have a lot of very small commits, or one big commit when 
  everything is working?
  - lot of small commits
- What are the most important commands to know in git?
  - push, pull, add, commit, rebase, checkout

## Introduction to Sockets

- Read the code in `src/tcp-echo-client.cc` and add a way to change the 
  message sent using command line arguments
- **Example**: `./client "hello message from the command prompt"` should send
  `"hello message from the command prompt"` to the server
- Commit your changes into git
- What do all these headers do? 
  - they let us use the already written code in these header files
- How do you find out which part of the below code comes from which header?
  - ctrl click
- How do you change the code so that you are sending messages to servers
  other than localhost? 
  - change the kserveraddress
- How do you change the code to send to a IPv6 address instead of IPv4?
  - we need to change the family to AF_INET6, use the struct sockaddr_in6, change the address variable according to IPv6, do things like sin6_addr, sin6_family, sin6_port
- **Bonus**: How do you change the client code to connect by hostname instead
  of IP address?
  - We use function getaddrinfo for DNS resolution
## Introduction to Memory Management

- What is happening in line 26 of `tcp-echo-client.cc`? 
  `if (inet_pton(AF_INET, kServerAddress.c_str(), &address.sin_addr) <= 0) {`
  - Converts the IP address from human readable string form to binary form and checks if it is a valid address by checking the conversion successfully happend, doest return negative
- What is happening in line 31 of `tcp-echo-client.cc`?
  `if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {`
  - tries to connect to server at given address using our socket and checks if connection was successful by seeing if it is less than 0
- What is the difference between a pointer and a reference?
  - You have to deference a pointer, dont have to dereference a reference explicitly and pointer takes some storage, and stores the adress of the variable, reference just is an alias of the variable, pointer can be null, reference cant be null, pointers have arithmetic, references dont, pointers can be reassigned.
- When is it better to use a pointer?
  - In use cases where we need to pass null values, or we need to use pointer arithmetic, or we need reassignment, for example making data structures like linked list.
- When is it better to use a reference?
  - In use cases like passing in function or for return values of funtions.
- What is the difference between `std::string` and a C-style string?
  - std::string is a class which treats strings like objects, C-style string is a character array.
- What type is a C-style string?
  - Character array
- What happens when you iterate a pointer?
  - the address stored in the pointer is changed by the appropriate number of bytes depening on type of object being pointed to, like 4 for int, 1 for char, etc.
- What are the most important safety tips to know when using pointers?
  - Never deference a null pointer, dont have dangling pointers.

## Learn Basics of Creating a C++ Project in Your IDE

- How do you compile and run your project in your IDE?
  - Just by opening a terminal in the IDE and running the commands in the terminal

## Improving Interactions with LLMs

- What is the most authoritative source of information about `socket()`
  from `<sys/socket.h>`?
  - The man command
- What is the most authoritative source of information about the TCP and IP
  protocols?
  - The RFC documents published by the IETF
- What is the most authoritative source of information about the C++
  programming language?
  - The official C++ ISO standards, the book The C++ programming language by its creator, cppreference.com
- What information can you find about using Markdown when structuring prompts 
  to LLMs?
  - I found out that markdown helps improve the LLM efficiency because of reasons like most of the LLMs are trained heavily using markdown, also it helps structure the prompt better using sections, etc.
- What is the difference between LLM and AI?
  - LLMs are a small subset of AI focussing on generating and understaning human language, whereas AI is a broader field which is about performing all tasks human perform artificially.
- Is it grammatically correct in English to say "a LLM" or "an LLM"? Why?
  - An LLM because when we say LLM there is an 'el' sound which starts with an e.