#include "shell.h"
/**
 * _getenv - Busca variables de entorno.
 * @name: Nombre de la variable de entorno a buscar.
 * chequeo - Verifica si el comando existe en el sistema o en el PATH.
 * Return: asas
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *token;

	while (environ[i])
	{
		token = strtok(environ[i], "=");

		if (strcmp(token, name) == 0)
		{
			return (strtok(NULL, "="));
		}
		i++;
	}
	return (NULL);
}
/**
 * chequeo - Chequea que el comando exista.
 * @comando: Verifica si el comando existe en el sistema.
 * @path: Variable.
 * Return: asassa
 */
char *chequeo(char *comando, char *path)
{
	char *completo = malloc(sizeof(char) * 1024);
	char *cpath = strdup(path);
	char *tokenizador;
	struct stat st;

	if (comando[0] == '/' || comando[0] == '.')
	{
		if (stat(comando, &st) == 0)
		{
			free(cpath)
			free(completo);
		return (strdup(comando));
		}
		free(cpath);
		free(completo);
		return (NULL);
	}

	tokenizador = strtok(cpath, ":");

	while (tokenizador != NULL)
	{
		sprintf(completo, "%s/%s", tokenizador, comando);

		if (stat(completo, &st) == 0)
		{
			free(cpath);
				return (completo);
		}
		tokenizador = strtok(NULL, ":");
	}
	free(cpath);
	free(completo);

	return (NULL);
}
