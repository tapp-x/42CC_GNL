# 42CC_GNL

## Description

Le projet `get_next_line` a pour objectif de créer une fonction en C capable de lire une ligne à partir d'un descripteur de fichier, même si la ligne est terminée par un retour à la ligne (`\n`) ou par la fin du fichier (`EOF`). Cette fonction est utile pour lire des fichiers texte ligne par ligne.

## Fonctionnalités

- Lire une ligne à partir d'un descripteur de fichier.
- Gérer les retours à la ligne et la fin de fichier.
- Utiliser une taille de buffer définie par l'utilisateur pour optimiser les lectures.

## Utilisation

Pour utiliser la fonction `get_next_line`, incluez les fichiers `get_next_line.c`, `get_next_line_utils.c` et `get_next_line.h` dans votre projet. Vous pouvez ensuite appeler la fonction `get_next_line` en lui passant un descripteur de fichier.

Exemple d'utilisation :

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

Pour compiler le projet, vous pouvez utiliser `gcc` :

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32  get_next_line.c get_next_line_utils.c -o get_next_line
```