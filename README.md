# 42CC_GNL

## Description

The `get_next_line` project aims to create a C function capable of reading a line from a file descriptor, even if the line is terminated by a newline (`\n`) or (`EOF`).

## Features

- Read a line from a file descriptor.
- Handle newlines and end of file.
- Use a user-defined buffer size to optimize reads.

## Usage

To use the `get_next_line` function, include the files `get_next_line.c`, `get_next_line_utils.c` et `get_next_line.h` in your project. You can then call the `get_next_line` function.

Example usage:

```c
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Compilation

To compile the project, you can use `gcc` :

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32  get_next_line.c get_next_line_utils.c -o get_next_line
```
