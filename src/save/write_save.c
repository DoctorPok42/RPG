/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** write_save
*/

#include "game.h"
#include<unistd.h>
#include "fcntl.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
int my_strlen(char const *str);
int my_put_nbr(int valeur, int fd);
int my_float(int prec, double n, int fd);
char **get_text(FILE *file);
int my_strncmp(char const *s1, char const *s2, int n);
int free_tab(char **tab);

void write_dialogs(dialog_t *dialog, int fd)
{
    FILE * file = fopen("assets/txt/dialog.txt", "r");
    char **text = NULL;
    text = get_text(file);
    int i = 0;
    while (my_strncmp(text[i], dialog->text[0], 2))
        i++;
    my_put_nbr(i, fd);
    write(fd, "\n", 1);
    free_tab(text);
}

void write_params(params_t *params, int fd)
{
    my_put_nbr(params->fullscreen, fd);
    write(fd, "\n", 1);
    my_put_nbr(params->mode.bitsPerPixel, fd);
    write(fd, "\n", 1);
    my_put_nbr(params->mode.height, fd);
    write(fd, "\n", 1);
    my_put_nbr(params->mode.width, fd);
    write(fd, "\n", 1);
    my_put_nbr(params->resolution.x, fd);
    write(fd, "\n", 1);
    my_put_nbr(params->resolution.y, fd);
    write(fd, "\n", 1);
    my_float(2, params->scale, fd);
    write(fd, "\n", 1);
    my_float(2, params->volume, fd);
    write(fd, "\n", 1);
    my_put_nbr(params->window_size.x, fd);
    write(fd, "\n", 1);
    my_put_nbr(params->window_size.y, fd);
}

void write_keys(keys_t *key, int fd)
{
    my_put_nbr((int)key->attack, fd);
    write(fd, "\n", 1);
    my_put_nbr((int)key->down, fd);
    write(fd, "\n", 1);
    my_put_nbr((int)key->escape, fd);
    write(fd, "\n", 1);
    my_put_nbr((int)key->interact, fd);
    write(fd, "\n", 1);
    my_put_nbr((int)key->inventory, fd);
    write(fd, "\n", 1);
    my_put_nbr((int)key->left, fd);
    write(fd, "\n", 1);
    my_put_nbr((int)key->pause, fd);
    write(fd, "\n", 1);
    my_put_nbr((int)key->right, fd);
    write(fd, "\n", 1);
    my_put_nbr((int)key->space, fd);
    write(fd, "\n", 1);
    my_put_nbr((int)key->up, fd);
    write(fd, "\n", 1);
}

void write_perso(perso_t *perso, int fd)
{
    my_put_nbr(perso->combat->attack, fd);
    write(fd, "\n", 1);
    my_put_nbr(perso->combat->defense, fd);
    write(fd, "\n", 1);
    my_put_nbr(perso->combat->level, fd);
    write(fd, "\n", 1);
    my_put_nbr(perso->combat->life, fd);
    write(fd, "\n", 1);
    my_put_nbr(perso->combat->speed, fd);
    write(fd, "\n", 1);
    my_put_nbr(perso->combat->strength, fd);
    write(fd, "\n", 1);
    my_put_nbr(perso->direction, fd);
    write(fd, "\n", 1);
    my_put_nbr(perso->move, fd);
    write(fd, "\n", 1);
    my_float(2, perso->pos.x, fd);
    write(fd, "\n", 1);
    my_float(2, perso->pos.y, fd);
    write(fd, "\n", 1);
}
