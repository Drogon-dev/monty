# 0x19. C - Stacks, Queues - LIFO, FIFO

## Description

This ALX project is a custom ByteCode interpreter, coded in C.
Compilation:
```gcc -Wall -Werror -Wextra -pedantic *.c -o monty```
Usage:
```./monty byte_file.m```

The program reads from the file "byte_file.m" that contains one instruction per line.
It then calls the right function to modify a stack according to the instruction.
It prints custom error messages if the instruction is wrong.

## Table of contents

File | Description
---- | -----------
[main.c](./main.c) | entry point of the program
[monty.h](./monty.h) | main header file
[bf](./bf) | Advanced tasks: Brainf*ck programs
