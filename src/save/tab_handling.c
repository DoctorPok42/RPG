/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** tab_handling
*/

#include <stdlib.h>

#include "my_str.h"
#include "save_functions.h"

static char *my_strdup(char *src)
{
    char *str = NULL;
    int i = 0;

    if (src == NULL)
        return NULL;
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return NULL;
    for (i = 0; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}

static char **tab_null(char *new_var)
{
    char **tab = malloc(sizeof(char *) * 2);

    if (tab == NULL)
        return NULL;
    tab[0] = my_strdup(new_var);
    tab[1] = NULL;
    return tab;
}

int free_tab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return 84;
    for (i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
    return 0;
}

char **add_str(char **tab, char *new_var)
{
    char **new_tab = NULL;
    int len = 0;
    int i = 0;

    if (tab == NULL)
        return tab_null(new_var);
    len = my_tablen(tab);
    new_tab = malloc(sizeof(char *) * (len + 2));
    if (new_tab == NULL)
        return tab;
    for (i = 0; i < len; i++)
        new_tab[i] = my_strdup(tab[i]);
    new_tab[len] = my_strdup(new_var);
    new_tab[len + 1] = NULL;
    free_tab(tab);
    return new_tab;
}
