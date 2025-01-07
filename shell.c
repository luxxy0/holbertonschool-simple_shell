#include "shell.h"
/**
 * main - Shell program entry point
 * Return: 0
 */
int main(void)
{
    char *line = NULL;          // Línea de entrada del usuario
    size_t line_length = 0;     // Longitud de la línea leída
    ssize_t nread;              // Número de caracteres leídos
    char **tokens;              // Tokens que contienen el comando y sus argumentos

    int interactive_mode = isatty(STDIN_FILENO);  // Determina si estamos en modo interactivo

    while (1)
    {
        if (interactive_mode)
            write(STDOUT_FILENO, "#cisfun$ ", 9); // Prompt si estamos en modo interactivo

        nread = getline(&line, &line_length, stdin);
        if (nread == -1)
        {
            if (interactive_mode)
                write(STDOUT_FILENO, "\n", 1); // Nueva línea al salir en modo interactivo
            break;
        }

        tokens = split_input(line); // Función que divide la entrada en tokens
        if (tokens == NULL || tokens[0] == NULL)
        {
            free(tokens);  // Liberamos si no hay comando
            continue;       // Continuamos a la siguiente iteración
        }

        run_command(tokens, line); // Ejecutar el comando con sus argumentos
        free(tokens); // Liberamos la memoria de los tokens
    }

    free(line); // Liberamos la memoria de la línea de entrada
    return (0); // Finaliza correctamente
}

