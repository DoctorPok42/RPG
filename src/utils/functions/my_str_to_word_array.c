/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** task04
*/

#include <stdlib.h>
#include <stdbool.h>

#include "my_str.h"

static bool check(char const c, char const separator)
{
    return c == separator || c == '\t' || c == '\n' || c == '\0';
}

static int count_word(char const *str, char const separator)
{
    int nb_words = 1;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (check(str[i], separator) && !check(str[i + 1], separator))
            nb_words += 1;
    return nb_words;
}

static int word_len(char const *str, int j, char const separator)
{
    int size = 0;

    while (str[j + size] != separator && str[j + size] != '\0')
        size++;
    return size;
}

static char **put_in_tab(char **tab, char const *str, char const separator)
{
    int nb_words = count_word(str, separator);
    int j = 0;
    int size = 0;
    int i = 0;
    int k = 0;

    for (i = 0; i < nb_words; i++) {
        size = word_len(str, j, separator);
        tab[i] = malloc(sizeof(char) * (size + 1));
        if (tab[i] == NULL)
            return tab;
        for (k = 0; k < size; k++)
            tab[i][k] = str[j + k];
        tab[i][size] = '\0';
        j += size;
        while (str[j] == separator || str[j] == '\t')
            j++;
    }
    return tab;
}

char **my_str_to_word_array(char *str, char const separator)
{
    int nb_words = count_word(str, separator);
    char **tab = malloc(sizeof(char *) * (nb_words + 1));

    if (tab == NULL)
        return NULL;
    tab[nb_words] = NULL;
    return put_in_tab(tab, str, separator);
}
