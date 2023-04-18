/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** open_file
*/
#include "game.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
char **add_str(char **tab, char *new_var);

char **get_line(char *line, ssize_t linesize, char **text, char *new_line)
{
    if (line[linesize -1] == '\n') {
        line[linesize - 1] = '\0';
        text = add_str(text, line);
    } else {
        new_line = malloc(linesize + 1);
        for (int j = 0; j < linesize; j++) {
            new_line[j] = line[j];
        }
        new_line[linesize] = '\0';
        text = add_str(text, new_line);
    }
    return text;
}

char **get_text(FILE *file)
{
    char **text = NULL;
    char *line = NULL;
    size_t len = 0;
    char *new_line = NULL;
    ssize_t linesize = 0;
    while ((linesize = getline(&line, &len, file)) != -1) {
        text = get_line(line, linesize, text, new_line);
    }
    return text;
}
