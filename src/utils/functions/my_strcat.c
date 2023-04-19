/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** 29
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int size_one = my_strlen(dest);
    int size_two = my_strlen(src);
    char *tab = malloc(sizeof(char) * (size_one + size_two) + 1);

    for (int i = 0; i < size_one; i++) {
        tab[i] = dest[i];
    }

    for (int j = 0; j < size_two; j++) {
        tab[size_one + j] = src[j];
    }

    tab[size_one + size_two] = '\0';

    return tab;
}
