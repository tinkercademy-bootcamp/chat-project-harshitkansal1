# Exercise 5

**Update this README with your answers to the questions below.**

## Comparing File Changes

- What's an easy way to identify the changes in source code from one exercise
  to another?
  - First we weill look at the directory structure to see if it is changed, then e can use the diff command from the command line, can also use the vimdiff command, there is inbuilt support in vs code also for seeing file changes.

## Using Classes

- Here is one way to separate out the code into multiple files
- Is this the best way to do it? 
  - Since there are multiple ways to do it, it is hard to define one way as best, it depends on the coding style and preferences of the people working in the project.
- What are the advantages and disadvantages?
  - The advantage seems to be that the code is broken down into a easy to understand format, utils.h containing any utlitites so be used by any files, server-main-the file to start server, server-client-the file to start client and the net folder contains chat-sockets.cc and h which contains functions realted to creating sockets. I don't see any apparent disadvantage.
## Introduction to Namespace

- There are different ways namespace is being used in this exercise
- Which way is better? What are the advantages and disadvantages?
  - Some ways i noticed was by explicitly writing the entire namespace in front of function, or to use the using namespace directive, or to alias some namespace like tt::chat to a variable like ttc and use that instead of tt::chat, advantages of writing the entire namespace is that it is more clear and explicit, but is it more verbose. The using directive is suitable for small functions but in case of larger peices of code, it might lead to name conflicts, by aliasing a part of the namespace or the entire namespace to a variable seems to be a combination of both to some extent.

## Abstracting Code into Classes

- Abstract the client and server logic into a `Client` and `Server` class
- **Note**: You don't have to use the code in this exercise as a starting point
- You can use the code you wrote from previous exercises instead
- How should you divide the code into files?
  - It might be useful to make a header file for client and server to contain the class declarations.
- What namespace and directory structure should you use? Why?
  - Making a tt::chat::client namespace for the client similar to server seems like the right thing to do, also it helps to make a folder for client and server with their respective code and header files. This is because it helps maintain consistency and organises the code in a good way.
## Programming Sense of Taste

- How do you judge what makes a particular choice of namespace and directory
  structure? 
  - I think it should the namespace and directory structure should be grouped in the same way, it should be easy to navigate the structure in looking for a peice of code, the grouping and the naming should be logical.
- How do you judge what makes a good naming convention or programming style?
  - A good naming convection or a programming style should be easy for another developer to look at the code and understand, it should be consistent, unambigous, descriptive. It should be easy to debug or refactor.

## "Senses" in Programming

- Have you ever heard of programmers referring to "code smells"? How can code
  smell?
  I have not heard of code smells. But when i looked it up i found out that it is used to refer to traces in programs which show weakness in design, they are not bugs but indicate code might have problems in the future. Some examples are duplicate code, code which depends on some other code.
- What does it mean to have a sense of taste in programming? How can code
  taste?
  - I think for code to taste good means that it is clean, elegant and easy to read and modify.
- Is there an analogue for every sense?
  - I think there can be an analogue for every sense in code to some extent.
- What other code senses can you think of?
  - sense of touch can be related to how easy it is to change the code and interact with the code, sense of sight can be realted to how easy it is to look at the code.
- How many senses do humans have?
  - 5 senses- touch, smell, taste, sight, hearing
- When would you want to see something before you touch it?
  - to know if it is safe to touch the thing and it would not do us any harm.
- When would you want to touch something before you see it?