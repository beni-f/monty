#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * push_stack - pushes an element to the stack
 * @stack: pointer to the stack
 * @n: the number to be pushed in the stack
 */
int is_integer(char *str)
{
    if (!str || !isdigit(*str))
        return 0;
    return 1;
}
void push_stack(stack_t **stack, int n)
{
    stack_t *newnode;
    newnode = malloc(sizeof(stack));
    newnode->n = n;
    newnode->prev = 0;
    newnode->next = *stack;
    if (*stack)
    {
        (*stack)->prev = newnode;
    }
    *stack = newnode;
}
/**
 * _pall - prints all elements in the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
/**
 * _push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, "\n");
    int n;
    if (arg == NULL || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    n = atoi(arg);
    push_stack(stack, n);
}
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack)
    {
        printf("%d\n", (*stack)->n);
    }
    else{
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
}
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    }

    *stack = (*stack)->next;
    free(temp);
}
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}