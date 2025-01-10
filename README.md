Simple Shell Project

Description

This project is a basic implementation of a UNIX command line interpreter (shell) designed to process and execute user commands. Its core functionality includes:

Running internal and external commands seamlessly.

Breaking down input strings into tokens for easier processing.

Locating executable commands by searching through system PATH directories.

Supporting fundamental commands like exit and fetching environment variables.

The shell operates by continuously listening for user input, parsing the commands, and executing them via system calls such as fork, execve, and wait. It remains active until the user decides to terminate it.

Features

Interactive Prompt: Displays shell$ to signal readiness for user commands.

Command Handling: Capable of running both built-in shell commands and external programs.

PATH Integration: Dynamically locates and executes commands found in the system's PATH environment variable.

Built-in Functionality:

exit: Allows the user to close the shell gracefully.

Access and utilization of environment variables.

Robust Error Management: Provides meaningful responses to invalid commands or end-of-file signals (Ctrl+D).

Files

File

Description

shell.h

Header file with function declarations and necessary includes.

shell.c

Main function and the shell loop.

function.c

Implements functions for environment variable handling and path checks.

path.c

Searches for commands in the PATH and verifies executables.

Compilation

To compile the project, use the following command:

gcc -Wall -Werror -Wextra -pedantic *.c -o shell

Usage

To run the shell, execute:

./shell

Example Usage:

shell$ ls
AUTHORS  README.md  function.c  path.c  shell.c  shell.h

shell$ env
PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
HOME=/home/user
...

shell$ exit

Flowchart

Below is the high-level workflow of the shell:

Display the prompt.

Read the user input.

Tokenize the input into commands and arguments.

Check if the command is executable (using PATH).

Execute the command via execve.

Wait for the child process to finish.

Repeat until the user exits.

Authors

Luciana Diaz

Juan Ignacio Daste
