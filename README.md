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
```
---

## Usage

Para ejecutar el shell, compila el programa y ejecútalo con el siguiente comando:

```bash
./shell
```
---

## Example Session

```bash
shell$ ls
README.md  shell.c  shell.h  path.c  function.c

shell$ env
PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
HOME=/home/user
...

shell$ exit
```
---

## Functions

### `char *_getenv(const char *name)`
Searches for an environment variable by name and returns its value.

- **Parameters:**
  - `name`: The name of the environment variable to search for.
- **Returns:**
  - The value of the environment variable or `NULL` if not found.

---

### `char *chequeo(char *comando, char *PATH)`
Checks if a command exists in the PATH and returns its full path if found.

- **Parameters:**
  - `comando`: The command to check.
  - `PATH`: The system PATH to search through.
- **Returns:**
  - The full path of the command if found, or `NULL` if not found.

---

### `char *fetch_env_var(const char *var_name)`
Fetches the value of an environment variable.

- **Parameters:**
  - `var_name`: The name of the environment variable.
- **Returns:**
  - The value of the environment variable or `NULL`.

---

### `char *locate_command_in_path(char *cmd)`
Finds the executable command in the PATH and verifies if it's valid.

- **Parameters:**
  - `cmd`: The command to locate.
- **Returns:**
  - The full path of the executable command or `NULL` if not found.

---

## Flowchart

The process flow for the shell is as follows:

1. Display the prompt (`shell$`).
2. Read user input.
3. Tokenize input into arguments.
4. Check if the command exists in the `PATH`.
5. Execute the command in a child process.
6. Handle errors (invalid commands or system calls).
7. Wait for process completion.
8. Loop back to the prompt until `exit` is called.

### Visual Representation

```plaintext
+---------------------------+
| Display prompt (shell$)   |
+------------+--------------+
             |
             v
+---------------------------+
| Read user input           |
+------------+--------------+
             |
             v
+---------------------------+
| Tokenize input            |
+------------+--------------+
             |
             v
+---------------------------+
| Check command in PATH     |
+------------+--------------+
             |
   +---------+---------+
   |                   |
   v                   v
+----------------+   +----------------+
| Command exists |   | Command invalid|
| Execute        |   | Show error msg |
+-------+--------+   +----------------+
        |
        v
+---------------------------+
| Wait for process completion|
+------------+--------------+
             |
             v
+---------------------------+
| Loop back to prompt       |
| until exit is called      |
+---------------------------+
```
---

## Authors

- **Luciana Diaz**  
- **Juan Ignacio Daste**

