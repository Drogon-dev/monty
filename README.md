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
[get_tokens.c](./get_tokens.c) | Splits user input into tokens
[operations_handler.c](./operations_handler.c) | Handles finding and calling of required operations
[operations.c](./operations.c) | contains some operation functions
[operations2.c](./operations2.c) | contains some operation functions
[operations3.c](./operations3.c) | contains some operation functions
[helpers_func.c](./helpers_func.c) | contains some helping functions
[error_handler.c](./error_handler.c) | Handles finding and calling the required error messages
[memory_manager.c](./memory_managerr.c) | Handles memory management so as to avoid memory leak
[mode_handler.c](./mode_handler.c) | Handles switching of mode from Stack (default) to Queues and vice versa
[bf](./bf) | Advanced tasks: Brainf*ck programs
