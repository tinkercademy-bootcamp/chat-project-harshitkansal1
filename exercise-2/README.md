# Exercise 2

**Update this README with your answers to the questions below.**

## Sources of Information for Questions from Before

### Socket 
- https://man7.org/linux/man-pages/man2/socket.2.html - System call reference
  for creating communication endpoints
- Or type `man socket` in terminal
- https://man7.org/linux/man-pages/man7/socket.7.html - Socket interface 
  overview and protocol families
- Or type `man 7 socket` in terminal
- When would you want to use a `SOCK_RAW` stream?
  - They are used for accessing lower level protocols, for custom protocol implementations
### TCP and IP Protocols
- [IPv4](https://www.rfc-editor.org/info/rfc791) - Internet Protocol 
  specification defining packet structure and routing
- [IPv6](https://www.rfc-editor.org/info/rfc8200) - Next-generation Internet 
  Protocol with expanded address space
- [TCP](https://datatracker.ietf.org/doc/html/rfc9293) - Transmission Control 
  Protocol providing reliable, ordered data delivery
    
### C++
- [C++23 ISO standard draft](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/n4950.pdf) - 
  Working draft of the C++ language specification
- Is the above the official C++23 spec? 
  - No
- Where is the official C++23 spec?
  - The official C++23 spec can be purchased from the ISO website
- Why was this link chosen instead?
  - Because this is free of cost and very close to the official spec
- Is this a helpful reference for learning C++?
  - No, this is not a helpful reference for learning C++, since it is too technical.
- Can the various implementations of C++ compilers be different from the
  C++ standard?
  - Yes, various implementations of the C++ compilers differ in their amount of conformance to C++ standard, some might be incomplete, have additional features.
- What are the most widely used and most significant C++ compilers?
  - GCC, Clang, MSVC, Intel C++ compiler
- Where is the equivalent spec for C++26?
  - The official standard has not been released yet, but the in progress latex source materials can be found on github, https://github.com/cplusplus/draft
- Where do you find the spec for the HTTP protocol?
  - the spec for all the versions can be found on ietf website, the link for HTTP/3 is given here- https://datatracker.ietf.org/doc/html/rfc9114
- What about HTTPS? Is there a spec for that protocol?
  - No, because it essentially HHTP over TLS, there is a spec for both TLS and HTTP protocols.

## Introduction to C++ and Sockets Programming

- Read the code in `src/`
- Are there any bugs in this code? 
  - The code seems to have the same functionality as the code from exercise-1 and i didnt find any bugs.
- What can you do to identify if there are bugs in the code?
  - We can run and make unit tests for each of the functions, blackbox testing can be done, we can also use tools like gdb or IDE debugger for debugging.

## Refactoring: Extract Function

- What is different in this code compared to exercise-1?
  - all the code is abstracted into functions and those functions are called inside main loop
- Is this code better or worse than exercise-1?
  - This code is better since it improves the readability and make it easier to re-use and expand upon and find bugs in specific functions.
- What are the tradeoffs compared to exercise-1?
  - The tradeoffs are that the code is much more verbose, and also to track the execution of the code one has to jump between functions, which might make it harder.
- Are you able to spot any mistakes or inconsistencies in the changes?
  - No, I am not able to spot any mistakes or inconsistencies in the changes.
## Thinking About Performance

- Does writing code this way have any impact on performance?
  - For a simple program like this, i dont think so, since there are very less function calls and other parts of the code have much more latency and also compiler can optimize smaller functions to make them inlined.
- What do we mean when we say performance?
  - Performance can be measured in terms of how much space and time a program is taking.
- How do we measure performance in a program?
  - It can be measured by measuring the time taken by a program, see how much of the system's resources are utilized and to check against some industry benchmarks for performance.

## Play with Git

- There isn't necessarily a single correct answer for how to abstract the 
  code from exercise-1 into functions
- Try different ways to refactor the code from exercise-1 to make it more
  readable.
- Make sure to commit each change as small and self-contained commit
- This will make it easier to revert your code if you need to
- What is `git tag`? How is `git tag` different from `git branch`?
  - A git tag is an object refering a specific commit within the project, git branch is used to create a differnt line of work and you can add commits to it, git tag just refers to a particular commit, no commits can be added, you can just see how the code looked like at a particular tag.
- How can you use `git tag` and `git branch` to make programming easier and
  more fun?
  - tags can be used to mark major changes, or different versions or milestones achieved in the code, whereas git branch can be used for freely experimenting with code without having to worry about the existing code.
## Learn Basics of Debugging in Your IDE

- How do you enable debug mode in your IDE?
  - Select Start debugging from the run tab.
- In debug mode, how do you add a watch?
  - Go to left pane, and find the watch panel. Click on plus in the watch section and enter the variable name.
- In debug mode, how do you add a breakpoint?
  - to add a breakpoint, just click on the editor margin to the left of any line.
- In debug mode, how do you step through code?
  - press F10 to step over code and F11 to step into code.

### Memory Management and Debug Mode in Your IDE

- How do you see the memory layout of a `std::string` from your IDE debug mode?
  - Open command pallete and search for debug: open memory view and enter the address of the std::string variable.
- How do you see the memory layout of a struct from your IDE debug mode?
  - You can open the memory viewer at the variable's address by hovering over it in the variables pane and selecting the view memory option. The way for std::string can also work, this is an alternative.