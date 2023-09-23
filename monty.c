#include "monty.h"
int main(int argc, char *argv[])
{
    stack_t *stack;

	stack = NULL;
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    read_file(argv[1], &stack);

    return EXIT_SUCCESS;
}