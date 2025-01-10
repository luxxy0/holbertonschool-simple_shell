#include "shell.h"

int main(void)
{
	char *linea = NULL, *token, *completo = NULL, *PATH = _getenv("PATH");
	size_t tamanio = 0;
	ssize_t longitud = 0;
	char **banderas = NULL;
	int i, estado;
	pid_t hijo;

	while (1)
	{
		if (isatty(0))
			printf("shell$ ");

		longitud = getline(&linea, &tamanio, stdin);

		if (longitud == -1 || strcmp(linea, "exit\n") == 0)
			break;

		banderas = malloc(sizeof(char *) * 1024);

		if (!banderas)
		{
			perror("malloc");
			free(linea);
			exit(1);
		}

		token = strtok(linea, " \t\n");
		i = 0;

		while (token != NULL)
		{
			banderas[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		banderas[i] = NULL;

		completo = chequeo(banderas[0], PATH);

		if (completo == NULL)
		{
			printf("shell: No such file or directory\n");
			free(banderas);

			continue;
		}
		hijo = fork();

		if (hijo == 0)
		{
			if (execve(completo, banderas, environ) == -1)
			{
				perror("error de ejecucion");
				free(banderas);
				free(completo);
				exit(127);
			}

		}
		else if (hijo > 0)
		{
			wait(&estado);
		}
		else
		{
			perror("fork");
		}
		free(banderas);
		free(completo);
	}
	free(linea);
	return (0);
}	

