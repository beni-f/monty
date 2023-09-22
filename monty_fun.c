#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
int is_integer(char *str)
{
    if (!str || !isdigit(*str))
        return 0;
    return 1;
}
void read_file(char *filename)
{
    FILE *file;
    char *line = NULL;
    size_t len;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {NULL, NULL}
    };

    file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        char *opcode = strtok(line, " \n\t");
        unsigned int i;

        line_number++;

        if (!opcode || opcode[0] == '#')
            continue;

        for (i = 0; opcodes[i].opcode; i++)
        {
            if (strcmp(opcode, opcodes[i].opcode) == 0)
            {
                opcodes[i].f(&stack, line_number);
                break;
            }
        }

        if (!opcodes[i].opcode)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
}