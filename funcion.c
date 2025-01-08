#include "shell.h"
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
char *chequeo(char *comando, char *path)
{
	char *completo = malloc(sizeof(char *) * 1024);
	char *cpath = strdup(path);
	char *tokenizador;
	struct stat st;

	tokenizador = strtok(cpath, ":");
	
	while (token != NULL)
	{
		sprintf(completo, "%s")
	}

