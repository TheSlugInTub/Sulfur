I made the project initially in C, but C gets me mad so I reset the project in C++.
Yaps about why I made the compiler and rants about C++ and reflection.
Yaps about compilers.
Yaps about lexing.
I made a lexer which lexes tokens. [Rewrite]
There will be 4 basic variable types, int, char, float and double much like in C.
Yaps about the lexer.
I then started work on the parser which converts the tokens into a data structure called an abstract syntax tree.
Yaps about ASTs.
I only finished the ast for the exit statement though, I'll make more once I have assembly output ready, and exit looks like this linux assembly, we move 60 into rax, which is the exit instruction, we move the exit code into rdi and then we do a syscall to let the system know we want to execute the instruction in rax.
I then made int declarations, declarations dont have any effect on the assembly just like in C, they only tell the compiler about the variable, and this variable gets added to a vector of variables.
Then I made int definitions which DO have an effect on the assembly, the way variables work is that the compiler moves 0 into rax, pushes it onto the stack and then modifies that value to be whatever you defined it as.
Then I added floating point values, in assembly, floats need to be put on the xmm registers, and you need to manually move them in to memory. So in the assembly, we subtract 16 bytes from rsp to make space for the float and to align the stack to 16 bytes because that's mandated before we do any syscall,
then we define a float value in the .data section, I just made a little counter in the code so we can keep making new floats with unique identifiers. And we move this float into the xmm0 register, and move it to the stack.
Then I added char variables. Chars are used to represent a single character and they're just one byte long, this was pretty easy because I just had to copy the code for int definitions and replace int with char.
Also with the assembly output, I don't need to push rax for chars, since they're only one byte and rax is an 8 byte register, so doing that would be quite wasteful, so I just subtracted 1 from rsp and moved the char directly to memory.
