/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** 17
*/

#include <stddef.h>
#include <stdbool.h>

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count;
    count = 0;
    while ((s1[count] != '\0' || s2[count] != '\0') && count < n - 1) {
        if (s1[count] != s2[count]) {
            return (s1[count] - s2[count]);
        }
        count += 1;
    }
    return (s1[count] - s2[count]);
}

int my_strcmp(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return 84;

    if (my_strlen(s1) - my_strlen(s2) != 0)
        return 1;

    bool not_same = false;
    for (int i = 0; s1[i] != '\0';) {
        for (int j = 0; s2[j] != '\0'; j++) {
            (s1[i] != s2[j] ? not_same = true : 0);
            i++;
        }
    }
    if (not_same) {
        return 1;
    } else {
        return 0;
    }
}
