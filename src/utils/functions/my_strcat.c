/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** 29
*/

#include <stdlib.h>
#include "my_str.h"

char *my_strcat(char *dest, char const *src)
{
    int size_one = my_strlen(dest);
    int size_two = my_strlen(src);
    char *tab = malloc(sizeof(char) * (size_one + size_two + 1));
    int i = 0;

    if (tab == NULL)
        return NULL;
    for (i = 0; i < size_one; i++)
        tab[i] = dest[i];
    for (i = 0; i < size_two; i++)
        tab[size_one + i] = src[i];
    tab[size_one + size_two] = '\0';
    return tab;
}
