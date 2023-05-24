README.md
0x16 SIMPLE SHELL

Simple Shell Project

The objective of this project is to write a simple Unix Command Interpreter.

A Unix Command Interpreter is also known as a shell which allows users to interact with the Operating System by typying
in commands which are translated into language the Operating System can understand and execute.

The project was completed using
-Betty linter 
-C Language
-Shell

General Requirements
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)
Write a README with the description of your project
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.

Compilation
The shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

List of allowed functions and system calls
- The below functions and system calls are used for purposes such as file manipulation, process management, memory allocation, and I/O operations. 
-Each function has its own specific behavior and usage, which can be further explored through their respective man pages.

access (man 2 access)- Checks the accessibility of a file.
chdir (man 2 chdir)- Changes the current working directory.
close (man 2 close)- Closes a file descriptor.
closedir (man 3 closedir)- Closes a directory stream.
execve (man 2 execve)- Executes a program
exit (man 3 exit)- Terminates the current process.
_exit (man 2 _exit)- Terminates the current process(without cleanup)
fflush (man 3 fflush)- Flushes a stream.
fork (man 2 fork)- Creates a new process by duplicating the existing process.
free (man 3 free)- Deallocates memory previously allocated by malloc, calloc or realloc
getcwd (man 3 getcwd)- Retrieves the current working directory
getline (man 3 getline)- Reads an entire line from a stream.
getpid (man 2 getpid)- Retrieves the process ID of the calling process.
isatty (man 3 isatty)- Checks if a file descriptor refers to a terminal.
kill (man 2 kill)- Sends a signal to process.
malloc (man 3 malloc)- Allocates memory dynamically
open (man 2 open)- Opens a file or creates one if it does not exist.
opendir (man 3 opendir)- Opens a directory stream.
perror (man 3 perror)- Prints a system error message
read (man 2 read)- Reads data from a file descriptor
readdir (man 3 readdir)- Reads a directory entry.
signal (man 2 signal)- Sets a signal handler for a specific signal
stat (__xstat) (man 2 stat)- Retrievs Information about a file.
lstat (__lxstat) (man 2 lstat)- Retrieves information about a symbolic link or file.
fstat (__fxstat) (man 2 fstat)- Retrieves information about an open file.
strtok (man 3 strtok)- Tokenizes a string into smaller parts.
wait (man 2 wait)- Suspends the calling process until one of its child processes terminates
waitpid (man 2 waitpid)- Suspends the calling process until a specific child processes terminates
wait3 (man 2 wait3)- Suspends the calling process until one of its child processes terminates with additional options.
wait4 (man 2 wait4)- Suspends the calling process until a specific child processes terminates with additional options.
write (man 2 write)- Writes data to a file Descriptor.

File Descriptors
1. Authors
	a) Bryan G Mbira- brian.mbira@gmail.com
	b) Peninah M Muyela- muyelap@gmail.com    
2. shell.h - The header file used in the project
-The shell.h file is a header file that is part of our project's shell implementation. 
It contains function prototypes, constants, and data structures related to the shell's functionality.

Contents of shell.h

-Definitions for constants such as buffer sizes, command types, and conversion flags.
-Structure definitions for linked lists used for strings and passing information between functions.
-Prototypes for built-in commands and utility functions used in the shell.
-Declarations for functions responsible for handling input, executing commands, managing environment variables, history, and aliases.
-Helper functions for string manipulation, memory management, error handling, and more.

More Information

All files are formatted and checked using betty.

References
https://linux.die.net/man/
