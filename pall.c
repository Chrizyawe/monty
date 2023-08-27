#include "monty.h"

/**
 * pall - a function that prints the stack
 * @top: the top of the stack
 * @count: useless parameter;
 * Return: void
 */
void pall(stack_t **top, unsigned int count)
{
	stack_t *ptr;
	(void)count;

	ptr = *top;
	if (ptr == NULL)
		return;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * push - a function that adds to a stack
 * @top: the top of the stack
 * @count: the line number
 * Return: void
 */
void push(stack_t **top, unsigned int count)
{
	int c, d = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			d++;
		for (; bus.arg[d] != '\0'; d++)
		{
			if (bus.arg[d] > 57 || bus.arg[d] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.fp);
			free(bus.file_content);
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.fp);
		free(bus.file_content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	c = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(top, c);
	else
		addqueue(top, c);
}
