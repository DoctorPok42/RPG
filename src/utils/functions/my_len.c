/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** 06
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int my_tablen(char **tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        i = i + 1;
    }
    return i;
}
