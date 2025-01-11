# Simple Shell Project

## Description

This project implements a simple shell written in the C programming language. It is a basic UNIX command line interpreter that processes and executes user commands. The shell includes functionality for:

- Running internal and external commands.
- Tokenizing input into commands and arguments.
- Searching for commands in the system PATH.
- Supporting essential built-in commands like `exit` and environment variable access.

The shell uses system calls such as `fork`, `execve`, and `wait` to manage process creation and command execution. It operates interactively until the user terminates it.

---

## Features

- **Prompt:** Displays `shell$` to indicate readiness for user input.
- **Command Execution:** Executes both built-in commands and external programs.
- **PATH Integration:** Dynamically resolves commands by searching through directories in the system's PATH.
- **Built-in Commands:**
  - `exit`: Exits the shell program.
  - Access and display environment variables using the `env` command.
- **Error Handling:** Detects invalid commands and handles end-of-file (Ctrl+D) gracefully.
- **Modular Design:** Separate source files for core components, ensuring maintainability and readability.

---

## File Descriptions

| File         | Description                                                             |
| ------------ | ----------------------------------------------------------------------- |
| `shell.h`    | Header file containing global declarations and library includes.        |
| `shell.c`    | Main entry point, prompt handling, and input processing.                |
| `path.c`     | Functions to locate commands in the PATH and validate executables.      |
| `function.c` | Implements functions for environment variable handling and tokenization.|

---

## Code Workflow

1. **Display Prompt:** The shell displays `shell$` for user input.
2. **Read Input:** It captures the user's command line input.
3. **Parse Commands:** The input is split into tokens (commands and arguments).
4. **Locate Command:** The program searches the system PATH for executable commands.
5. **Execute Command:** Commands are run using `execve` within a forked process.
6. **Wait for Completion:** The shell waits for the child process to finish.
7. **Repeat or Exit:** The shell loops until the user exits.

---

## Compilation

To compile the project, ensure you have a C compiler (e.g., GCC) installed. Use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o shell

## Usage

Para ejecutar el shell, compila el programa y ejecútalo con el siguiente comando:

```bash
./shell

