#include "shell.h"
/**
 * fetch_env_var - Busca una variable de entorno
 * @var_name: Nombre de la variable de entorno
 * Return: Valor de la variable o NULL si no se encuentra
 */
extern char **environ;

char *fetch_env_var(const char *var_name)
{
    int idx;
    size_t var_len = strlen(var_name);

    for (idx = 0; environ[idx]; idx++)
    {
        if (strncmp(environ[idx], var_name, var_len) == 0 && environ[idx][var_len] == '=')
        {
            return environ[idx] + var_len + 1;
        }
    }
    return NULL;
}

/**
 * locate_command_in_path - Localiza un comando en el directorio PATH
 * @cmd: Comando a buscar
 * Return: Ruta completa al comando si se encuentra, o NULL si no
 */
char *locate_command_in_path(char *cmd)
{
    char *env_path = fetch_env_var("PATH");
    char *path_dup, *dir, *cmd_path;
    size_t cmd_len, dir_len;

    if (!env_path || !cmd)
        return (NULL);

    path_dup = strdup(env_path);
    if (!path_dup)
        return (NULL);

    cmd_len = strlen(cmd);

    dir = strtok(path_dup, ":");
    while (dir)
    {
        dir_len = strlen(dir);
        cmd_path = malloc(dir_len + cmd_len + 2);  // espacio para '/' y '\0'
        if (!cmd_path)
        {
            free(path_dup);
            return (NULL);
        }

        snprintf(cmd_path, dir_len + cmd_len + 2, "%s/%s", dir, cmd);

        if (access(cmd_path, X_OK) == 0)  // Verifica si el comando es ejecutable
        {
            free(path_dup);
            return (cmd_path);
        }

        free(cmd_path);
        dir = strtok(NULL, ":");
    }

    free(path_dup);
    return (NULL);
}
