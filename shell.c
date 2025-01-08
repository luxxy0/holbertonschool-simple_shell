#include "shell.h"

int main(void)
{
	char *linea = NULL, *token, *completo = NULL, *PATH = _getenv("PATH");
	size_t tamanio = 0;
	ssize_t longitud = 0;
	char **banderas = malloc(sizeof(char *) * 1024);
	int i, estado;
	pid_t hijo;

	while (1)
	{
		if (isatty(0))
			printf("shell$ ");

		longitud = getline(&linea, &tamanio, stdin);

	if (longitud == -1 || strcmp(linea, "exit\n"))
		break;

		token = strtok(linea, " \t\n");
		i = 0;

		while (token != NULL)
		{
			banderas[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		banderas[i] = NULL;

		/*completo = chequeo(banderas[0], PATH);

		if (completo == NULL)
		{
			printf("shell: No such file or directory\n");
			free(banderas);
			free(linea);
			free(completo);
			continue; //ignora el codigo de abajo y vuelve a arriba
		}*/
		hijo = fork();

		if (hijo == 0)
		{
			if (execve(banderas[0], banderas, NULL) == -1)
			{
				perror("error de ejecucion");
				exit(127);
				free(banderas);
				free(linea);
				free(completo);
			}
			
		}
		else
		{
			wait(&estado);
		}
		free(banderas);
		free(linea);
		free(completo);
	}
	free(linea);
	return (0);
}	

