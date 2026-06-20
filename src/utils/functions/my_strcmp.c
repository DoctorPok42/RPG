/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** 17
*/

#include "my_str.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] != '\0' && s1[i] == s2[i])
        i++;
    if (i == n)
        return 0;
    return s1[i] - s2[i];
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 84;
    while (s1[i] != '\0' && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}
