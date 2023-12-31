#include "monty.h"

/**
 * pint - function that prints the top of a stack
 * @top:  top of the stack
 * @count: line number
 * Return: void
 */

void pint(stack_t **top, unsigned int count)
{
	if (*top == NULL || top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.fp);
		free(bus.file_content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
