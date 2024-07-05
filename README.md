# Quick Questions

## 1. 
Since I don't know these terms, I can try to explain what I think they are by context. Probably code cohesion is how much two or more code modules are "connected": if they work well together or not. 

Code coupling could be the way they connect. How the interfaces between them are designed and if they are secure.

## 2.
Interruption and polling I/O are two ways to read an input or write one or various outputs. When we use polling, we are using a loop to check, in a determined amount of time, the state of an input or write the state of an output.

However, when we use an interruption, the code flow is literally interrupted. For example:
We have a binary input (1 or 0), and we use the interruption strategy to read it. In normal conditions, when the state of the input has not changed, the program is doing something else, like running the while(1) loop located in main. When this input changes the state from 0 to 1, the code jumps to the interruption routine "instantaneously" (always within the timing limitations of the system) and "asynchronously" (it is an interruption!). When it finishes running the interruption routine, it returns to the instruction it was before the interruption came over.

With this interruption strategy, I would use it to read some time-critical inputs like current spikes, for example.
I would use the polling method to write some LED blinking, which is only a system status flag (which is not important if we have a delay on it). 

## 3.
I've never used desing patterns.

## 4. 
Code quality techniques:
- Style and Formatting: Having a good format in the code helps with the readability of that code. So I've used clang-format to automate it. I have used clang-tidy to automate it. I like to have all variables with the type in their name:  `uint8_t u8_variableName`. I normally use camel Case for naming. Furthermore, I always try to make a difference between macros by writing them in capital letters.
- Doxygen documentation: This is a must for me. Documentation updates the quality of the code, since people who read the code can see the documentation in the code. Also, they can read this documentation formatted in an HTML file or a latex file. Finally, having documentation increases the readability and understanding of the code. 
- Use of the structures and typedefs: I like to use structures to increase the code's readability and reusability. For example, if we have an FSM with some control parameters, I like to use a typedef to define a struct to define those parameters. Also, if we have some code we want to reuse, we could add some API or interface to modify those parameters in the struct.

## 5. 
The stack is a FIFO pile, which controls the context of the program. Here is where function parameters are saved when the execution enters a function, or local variables are stored. 
   However, the heap is the memory in the RAM we can allocate, in run-time, some data to read later. We can do this with the `malloc` or `calloc` functions, for example. 

## 6. 
Little endian or big endian are two types of endianness. The endianness is which order MCU saves in its memory the bytes of a variable:
### Little endian: 
saves the bytes from the less significant byte to the most significant byte. 
Example variable: **0xAABBCCDD** 

| Memory position | Byte |
| :-------------: | :--: |
|       0x1       | 0xDD |
|       0x2       | 0xCC |
|       0x3       | 0xBB |
|       0x4       | 0xAA |

### Big Endian: 
saves the bytes from the most significant (MSB) byte to the least significant byte (LSB). 
Example variable: **0xAABBCCDD** 

| Memory position | Byte |
| :-------------: | :--: |
|       0x1       | 0xAA |
|       0x2       | 0xBB |
|       0x3       | 0xCC |
|       0x4       | 0xDD |
## 7. 
API is the acronym for Application Programming Interface. They are used to control and communicate between the blocks of code without modifying the internal code of those black box codes. They are a way to abstract from a block of code that does something.
## 8.
It depends on the project and the usage needed. In my way of seeing it, the dynamic memory usage has to be very well justified to be used because it is very easy to make errors like memory leakages. I think it is better to try to use size-defined buffers to have better control over the data.
## 9.
Firstly, I've never developed a multiprocessing environment, so I am not an expert in this field. But I think the biggest thread is that the processes were not well synchronized. For example, one process tries to read data from another, but that process has not calculated it. To solve this, I would apply some thread-safe RTOS to start, and I would try to apply some mutex gates or semaphores to solve it.

Another thread is that two processes try to use the same resource (like an ADC, for example). Then I would try to apply the same techniques as the last example, like mutex gates or semaphores, to block the usage of the resource.

Finally, a deathlock is a series of threads that have to be avoided by the good design of the software architecture. A deathlock is when a process waits for another to finish some calculations and the other waits for the first to finish its own calculations. So the system waits forever for the two processes.
## 10.
A callback function is a function that is called when an interruption routine is executed. It is a way to write code that will be executed when an interruption is called.
For example, I used it when I had an interruption from an ADC window, which has to break the run of a motor.
## 11.
In C, the volatile keyword is to tell the compiler not to optimize the variable defined next. I have used it when I had some variables that were sensitive to being there, and they might be read from another system in the memory of the device.
## 12.
 I don't know what SOLID in code is.
