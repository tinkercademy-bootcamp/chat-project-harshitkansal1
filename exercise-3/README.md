# Exercise 3

**Update this README with your answers to the questions below.**

## Re-using Code

- Read the code in `src/tcp_echo_client.cc`
- A new function `check_error()` has been created and `create_socket()` from 
  exercise-2 has been refactored to make use of it
- What are the benefits of writing code in this way?
  - it provides a common function for handling errors which all the other functions can use.
- Are there any costs to writing code like this?
  - In cases where we have to take some actions on the basis of the error, it will make the handler complex, hard to handle those cases.
- Apply `check_error` to all the code in `src/`

## Introduction to Compiler Explorer

- Try out the old `create_socket()` and the new `check_error()` and 
  `create_socket()` in [Compiler Explorer](https://godbolt.org) - Interactive 
  tool for exploring how C++ code compiles to assembly
- What is happening here?
  - In the new one there is there is a call to check_error in create_socket and for that there is a constructor for a std::string and there is a destructor for doing memory managament, older assembly code is much simpler and we just use a string literal and there are no constructors or destructors.
- Can you think of any different approaches to this problem?
  - We can pass the string as reference to the check_error functions or even better, pass a pointer to a char as in C-style strings since a string literal can be passed in to avoid the additional overhead of the constructor and destructor of the string being passed right now.
- How can you modify your Makefile to generate assembly code instead of
  compiled code?
  - By adding the -S flag in the compilation commands.
- **Note**: You can save the generated assembly from Compiler Explorer
- **Bonus**: Can you view assembly code using your IDE?
  - Yes, we can just open the assembly code file generated and view it in the IDE.
- **Bonus**: How do you see the assembly when you step through each line in
  debugging mode from your IDE?
  - We can use the disassembly view in VS code to see the assembly code while in debugging mode
- [x86 assembly reference](http://ref.x86asm.net/) - Comprehensive reference 
  for x86 assembly language instructions and syntax

## More About Memory Management

- Make sure you have `-fsanitize=address` in both your `CXX_FLAGS` and 
  `LD_FLAGS` in your Makefile
- What do `-fsanitize=address`, `CXX_FLAGS` and `LD_FLAGS` mean?
  - CXXFALGS is a make file variable which stores the flags to be used with the c++ compiler, LDFLAGS is a makefile variable which stores the flags to be used with the linker, -fanitize=address is a flag which can be used for detecting memory errors.
- With the new tool of the Compiler Explorer, and keeping in mind what you 
  have learned about how to use debug mode
- What happens when you look at a `std::string` using the above methods?
  - I wasnt able to look at memory layout of string from debug view, in compiler explorer i can see that the text is stored in sections like .LO1, online i found that there are fiels in a string like pointer to buffer, size, capacity.
- Where is the text in your `std::string`?
  - In the compiler explorer i can see the test in sections like .L01, after searching online i found that text is stored in a buffer in string itself for small strings and on the heap for larger strings.
- What is `std::optional`?
  - It is similar to options from some other languages, it can be wither none(null value) or some value, forces us to explicitly think about and handle the null value cases.
- How do you find out the memory layout of a `std::optional`?
  - using compiler explorer or debug view.
- Read https://en.cppreference.com/w/cpp/memory#Smart_pointers - Guide to 
  modern C++ memory management using smart pointers
- Which pointer types are the most important to know about?
  - unique_ptr, shared_ptr, weak_ptr
- Which smart pointer should you use by default if you can?
  - Unique_ptr
- Does changing your optimization level in `CXXFLAGS` from `-O0` to `-O3` have
  any impact on the answers to any of the above questions?
  - Only thing i could find was that std::strings might take less memory with the 03 optimization, rest of the things should stay the same.

## More Thinking About Performance

- After your experiments with Compiler Explorer, do you have any updates for
  your answers in exercise-2?
  - I think the performance for the newer code will be worse due to making a new string and then destroying the new string and also the aditional function call.

### Bonus: Do Not Watch Now 

- [More about Compiler Explorer](https://www.youtube.com/watch?v=bSkpMdDe4g4) - 
  Deep dive into compiler optimization and assembly analysis
  - Create a struct which contain many different data types
  - Look at the memory layout in the debugger
  - Create a `char` or `uint8_t` pointer to the beginning of the struct, 
    iterate to the end of the struct, printing out the value of each byte in 
    hexadecimal
  - Try accessing different parts of the struct and see in compiler explorer
    what the assembly looks like
  - What happens if you iterate the pointer to outside the bounds of your
    array?
  - Let's say your struct is called `Foo`
  - What is the difference between `std::vector<Foo>` and `std::vector<Foo*>`?
  - What are the tradeoffs between using `std::vector<Foo>` vs 
    `std::vector<Foo*>`? 
  - Give an example where `std::vector<Foo>` is a better choice than 
    `std::vector<Foo*>`
  - Give another example where the opposite is true
  - Can you create `std::vector<Foo&>`? 
  - Can you create `std::vector<std::optional<Foo>>`?
  - What happens if your struct contains another struct?
  - What is the difference between a struct and a class?