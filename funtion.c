#include "main.h"

/**
 * execute_ls - Ejecuta el comando `ls` para listar el contenido de un directorio
 * @params: Argumentos del comando `ls` (se pasa como array de cadenas)
 */
void execute_ls(char **params)
{
    pid_t child_pid;
    int exit_status;

    child_pid = fork();
    if (child_pid == 0)
    {
        if (execve("/bin/ls", params, NULL) == -1)
        {
            perror("Error ejecutando ls");
            exit(EXIT_FAILURE);
        }
    }
    else if (child_pid > 0)
    {
        wait(&exit_status);
    }
    else
    {
        perror("Error al crear el proceso para ls");
    }
}

/**
 * change_directory - Cambia el directorio de trabajo con el comando `cd`
 * @params: Argumentos del comando `cd` donde `params[1]` es el directorio al que cambiar
 */
void change_directory(char **params)
{
    if (params[1] == NULL)
    {
        fprintf(stderr, "Shell_Error: falta argumento para cd\n");
    }
    else if (chdir(params[1]) != 0)
    {
        perror("Error al cambiar de directorio");
    }
}

/**
 * exit_shell - Sale de la shell
 * @params: Argumentos del comando `exit` (aunque no se usan en este caso)
 */
void exit_shell(char **params)
{
    (void)params;
    printf("Saliendo del programa...\n");
    exit(0);
}

/**
 * print_current_directory - Muestra el directorio de trabajo actual
 * @params: Argumentos del comando `pwd` (no se usan en este caso)
 */
void print_current_directory(char **params)
{
    char current_dir[1024];

    (void)params;

    if (getcwd(current_dir, sizeof(current_dir)) != NULL)
    {
        printf("%s\n", current_dir);
    }
    else
    {
        perror("pwd");
    }
}

/**
 * clear_terminal - Limpia la terminal
 * @params: Argumentos de la línea de comando (no se utilizan en este caso)
 */
void clear_terminal(char **params)
{
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0)
    {
        execvp("/bin/clear", params);
        perror("Error ejecutando clear");
        exit(EXIT_FAILURE);
    }
    else if (child_pid > 0)
    {
        wait(NULL);
    }
    else
    {
        perror("Error al crear el proceso");
    }
}

