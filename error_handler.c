#include "monty.h"

/*Error Messages*/
#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"

/**
 * error_set_one: error messages for set one
 * @error_code: error code
 */
void error_set_one(int error_code)
{
	switch (error_code)
	{
		case 1:
			fprintf(stderr, USAGE);
			break;
		case 2:
			fprintf(stderr, FILE_ERROR, data.filename);
			break;
		case 3:
			fprintf(stderr, UNKNOWN, data.line_number, data.args[0]);
			break;
		case 4:
			fprintf(stderr, MALLOC_FAIL);
			break;
		case 5:
			fprintf(stderr, PUSH_FAIL, data.line_number);
			break;
		case 6:
			fprintf(stderr, PINT_FAIL, data.line_number);
			break;
		case 7:
			fprintf(stderr, POP_FAIL, data.line_number);
			break;
		case 8:
			fprintf(stderr, SWAP_FAIL, data.line_number);
			break;
		default:
			break;
	}
	
	if (error_code != 1 && error_code != 2)
		free_data();
}

/**
 * error_set_two: errors messages for set two
 * @error_code: error code
 */
void error_set_two(int error_code)
{
	switch (error_code)
	{
		case 9:
			fprintf(stderr, ADD_FAIL, data.line_number);
			break;
		case 10:
			fprintf(stderr, SUB_FAIL, data.line_number);
			break;
		case 11:
			fprintf(stderr, DIV_FAIL, data.line_number);
			break;
		case 12:
			fprintf(stderr, DIV_ZERO, data.line_number);
			break;
		case 13:
			fprintf(stderr, MUL_FAIL, data.line_number);
			break;
		case 14:
			fprintf(stderr, MOD_FAIL, data.line_number);
			break;
		case 15:
			fprintf(stderr, PCHAR_FAIL, data.line_number);
			break;
		case 16:
			fprintf(stderr, PCHAR_RANGE, data.line_number);
			break;
		default:
			break;
	}
	free_data();
}

/**
 * get_error - gets the exact error message
 * according to the error code then prints it
 * @error_code: error code
 */
void get_error(int error_code)
{
	if (error_code >= 1 && error_code < 9)
		error_set_one(error_code);
	else
		error_set_two(error_code);

	exit(EXIT_FAILURE);
}
