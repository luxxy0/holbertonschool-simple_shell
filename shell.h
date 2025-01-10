#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/stat.h>

extern char **environ;
char *_getenv(const char *name);
char *chequeo(char *comando, char *PATH);

/*char......*/
#endif
