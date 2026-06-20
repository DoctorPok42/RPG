/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** open_file
*/

#include <stdio.h>
#include <stdlib.h>

#include "my_str.h"
#include "save_functions.h"

char **get_text(FILE *file)
{
    char **text = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t n = 0;

    n = getline(&line, &len, file);
    while (n != -1) {
        if (n > 0 && line[n - 1] == '\n')
            line[n - 1] = '\0';
        text = add_str(text, line);
        n = getline(&line, &len, file);
    }
    free(line);
    return text;
}
