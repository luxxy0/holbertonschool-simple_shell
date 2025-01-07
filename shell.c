#include "shell.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
    char *buffer = NULL;        // Renombrado de 'input' a 'buffer'
    size_t buffer_size = 0;     // Renombrado de 'len' a 'buffer_size'
    ssize_t bytes_read;         // Renombrado de 'read' a 'bytes_read'
    char **command_args;        // Renombrado de 'args' a 'command_args'

    int is_terminal = isatty(STDIN_FILENO);  // Renombrado de 'is_interactive' a 'is_terminal'

    while (1)
    {
        if (is_terminal)
            printf("#cisfun$ ");

        bytes_read = getline(&buffer, &buffer_size, stdin);
        if (bytes_read == -1)
        {
            if (is_terminal)
                printf("\n");
            break;
        }

        command_args = tokenize_input(buffer);
        if (!command_args || !command_args[0])
        {
            free(command_args);
            continue;
        }

        execute_command(command_args, buffer);
        free(command_args);
    }

    free(buffer);
    return (0);
}

