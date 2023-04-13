/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** my_strndup
*/

#include <stdlib.h>

char *my_strndup(char *str, int n)
{
    char *new_str = malloc(sizeof(char) * (n + 1));
    int i = 0;

    if (new_str == NULL)
        return NULL;
    for (i = 0; i < n; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return new_str;
}
