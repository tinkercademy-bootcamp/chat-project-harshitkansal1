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
  - ???
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
  - g++, 
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
  - right click and select from dropdown
- How do you change the code so that you are sending messages to servers
  other than localhost? 
  - change the kserveraddress
- How do you change the code to send to a IPv6 address instead of IPv4?
  - we need to change the family to AF_INET6, use the struct sockaddr_in6, change the address variable according to IPv6
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
  - You have to deference a pointer, dont have to dereference a reference explicitly
- When is it better to use a pointer? can be null
- When is it better to use a reference? cant be null
- What is the difference between `std::string` and a C-style string?
- What type is a C-style string?
- What happens when you iterate a pointer?
- What are the most important safety tips to know when using pointers?

## Learn Basics of Creating a C++ Project in Your IDE

- How do you compile and run your project in your IDE?

## Improving Interactions with LLMs

- What is the most authoritative source of information about `socket()`
  from `<sys/socket.h>`?
- What is the most authoritative source of information about the TCP and IP
  protocols?
  - IETF, rfc
- What is the most authoritative source of information about the C++
  programming language?
- What information can you find about using Markdown when structuring prompts 
  to LLMs?
- What is the difference between LLM and AI?
- Is it grammatically correct in English to say "a LLM" or "an LLM"? Why?