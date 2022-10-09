#ifndef MONTY_H
#define MONTY_H

/*Standard Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct instance_s - data instance
 * @line: the readed line
 * @args: the arguments
 * @line_number: line number
 * @fp: the file
 * @filename: filename
 * Description: data instance, line, args
 */
typedef struct instance_s
{
	char *line;
	char **args;
	char *filename;
	int line_number;
	FILE *fp;
} data_t;

extern data_t data;  
extern stack_t *head_q;
extern stack_t *bottom_s;
extern int is_stack;

/* Function Prototypes */
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int get_op(stack_t **stack);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void push_op(stack_t **stack, unsigned int line_number);
void get_error(int err_code);
void free_data(void);
void print_all_op(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int get_tokens(void);
void print_top_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void swap_top2_op(stack_t **stack, unsigned int line_number);
int _isdigit(char *str);
void nop_op(stack_t **stack, unsigned int line_number);
void add_top2_op(stack_t **stack, unsigned int line_number);
void sub_top2_op(stack_t **stack, unsigned int line_number);
void div_top2_op(stack_t **stack, unsigned int line_number);
void mul_top2_op(stack_t **stack, unsigned int line_number);
void mod_top2_op(stack_t **stack, unsigned int line_number);
void pchar_op(stack_t **stack, unsigned int line_number);
void pstr_op(stack_t **stack, unsigned int line_number);
void rotl_op(stack_t **stack, unsigned int line_number);
void rotr_op(stack_t **stack, unsigned int line_number);
void stack_mode(stack_t **stack, unsigned int line_number);
void queue_mode(stack_t **stack, unsigned int line_number);

#endif /*MONTY_H*/
