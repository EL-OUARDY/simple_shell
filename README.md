# ALX — Custom `Simple Shell` Project in C Language

## Project Overview
This is a simple shell project developed as part of **ALX software engineering program**. The goal of this project is to create a basic shell that mimics the functionality of a Linux shell.


## Requirements
### Output
Unless specified otherwise, your program must have the exact same output as ``sh`` (``/bin/sh``) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your ``argv[0]`` (See below)\
Example of error with ``sh``:

```bash
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

Same error with your program hsh:

```bash
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
### Testing
Your shell should work like this in interactive mode:
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Allowed functions and system calls
``access`` / 
``chdir`` / 
``close`` / 
``closedir`` / 
``execve`` / 
``exit`` / 
``_exit`` / 
``fflush`` / 
``fork`` / 
``free`` / 
``getcwd`` / 
``getline`` / 
``getpid`` / 
``isatty`` / 
``kill`` / 
``malloc`` / 
``open`` / 
``opendir`` / 
``perror`` / 
``read`` / 
``readdir`` / 
``signal`` / 
``stat`` / 
``lstat`` / 
``fstat`` / 
``strtok`` / 
``wait`` / 
``waitpid`` / 
``wait3`` / 
``wait4`` / 
``write`` / 

## Compilation
Program will be compiled this way:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Steps to Implement
1. Create a loop to continuously accept user commands.
2. Parse the user input to identify the command and its arguments.
3. Execute the command with **execve()** in a child process created using **fork()**.
4. Handle non fullpath command \
5. Process built-in commands such as exit, cd, env ...etc \
``... MORE STEPS WILL BE ADDED AS WE PROGRESS IN THE PROJECT``

## Project File Structure:
1. `shell.h` — header file that contains all used functions and custom struct types.
1. `main.c` — contains the primary function of our shell, serving as the program's entry point and featuring the foundational code for our shell's operation.
1. `command.c` — function to perform operations on the shell command.
1. `arguments.c` —  functions for handling and parsing command-line arguments passed to our custom shell.
1. `builtin.c` — contains functions to handle builtin commands.
1. `strings.c` — this file encompasses all the functions to deal with strings.
1. `lists.c` — contains all function to manipulate linked lists.
1. `environment.c` — functions for manage and interact with the environment variables, including setting, getting, or modifying environment settings.
1. `errors.c` — handle error messages.
1. `cleanup.c` —  includes functions responsible for cleaning up resources, ensuring proper termination and avoiding memory leaks.
1. `_getline.c` —  custom implementation of the built-in **getline** function.
1. `_strtok.c` —  personalized version of the native **strtok** string tokenization function.


## Team Members:
**Hamza Dazia** — [*https://github.com/HamzaDazai*](https://github.com/HamzaDazai) \
**Ouadia EL-Ouardy** — [*https://github.com/EL-OUARDY*](https://github.com/EL-OUARDY)


