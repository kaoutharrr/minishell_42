# Minishell Project

## Introduction
The **Minishell** project is part of the **42 curriculum** designed to teach students about shell programming in C. The goal is to create a simplified shell that can execute commands, manage processes, and support basic features like input/output redirection and environment variable handling.

## Objectives
- Understand how a Unix shell works.
- Implement process creation and management.
- Handle signals and process termination correctly.
- Manage built-in commands and command-line parsing.

## Features
- Execute commands in a new process.
- Support for input and output redirection.
- Manage environment variables (set, unset, and display).
- Support for piping to connect commands.
- Handle signals like `Ctrl+C`.

## Setup and Compilation
To compile the project, run:
```bash
make
```
This will create the `minishell` executable.

## Usage
To run the shell, execute the compiled `minishell` file. You can enter commands at the prompt, and the shell will execute them and display the results.

## Built-in Commands
Minishell supports several built-in commands, including:
- `cd`: Change the current working directory.
- `exit`: Exit the shell.
- `env`: Display current environment variables.
- `set`: Set an environment variable.
- `unset`: Unset an environment variable.
- `export`: Export an environment variable to the shell environment.
- `echo`: Display a line of text or variable values.
- `pwd`: Print the current working directory.
- 
## Error Handling
The shell should handle errors gracefully, including:
- Command not found.
- Incorrect usage of built-in commands.
- Input/output redirection errors.
- Memory allocation failures.

## Conclusion
The **Minishell** project provides an opportunity to learn about shell programming and process management in C. By completing this project, you will gain a deeper understanding of how shells operate and how to manage commands effectively.
