/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** tab_handling
*/
#include "game.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int my_strlen(char const *str);
int my_tablen(char **tab);

char *my_strdup(char *src)
{
    if (src == NULL)
        return NULL;
    char *str = NULL;
    int i = 0;
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        str[i] = src[i];
        i = i + 1;
    }
    str[i] = '\0';
    return str;
}

int free_tab(char **tab)
{
    if (tab == NULL)
        return 84;
    int i = 0;
    for (; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab[i]);
    free(tab);
    return 0;
}

char **tab_null(char *new_var)
{
    char **tab = malloc(sizeof(char *) * 2);
    tab[0] = my_strdup(new_var);
    tab[1] = NULL;
    return tab;
}

char **add_str(char **tab, char *new_var)
{
    int i = 0;
    if (tab == NULL)
        return tab_null(new_var);
    char **new_tab =
    malloc(sizeof(char *) * my_tablen(tab) + sizeof(char *) * 2);
    for (; tab[i] != NULL;i++) {
        new_tab[i] = my_strdup(tab[i]);
    }
    new_tab[i] = my_strdup(new_var);
    new_tab[i + 1] = NULL;
    free_tab(tab);
    return new_tab;
}
