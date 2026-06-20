/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** write_save
*/

#include <unistd.h>

#include "game.h"
#include "my_str.h"
#include "save_functions.h"

static void write_int(int value, int fd)
{
    my_put_nbr(value, fd);
    write(fd, "\n", 1);
}

void write_params(params_t *params, int fd)
{
    write_int(params->fullscreen, fd);
    write_int(params->mode.bitsPerPixel, fd);
    write_int(params->mode.size.y, fd);
    write_int(params->mode.size.x, fd);
    write_int(params->resolution.x, fd);
    write_int(params->resolution.y, fd);
    my_float(2, params->scale, fd);
    write(fd, "\n", 1);
    my_float(2, params->volume, fd);
    write(fd, "\n", 1);
    write_int(params->window_size.x, fd);
    write_int(params->window_size.y, fd);
}

void write_keys(keys_t *key, int fd)
{
    write_int((int)key->attack, fd);
    write_int((int)key->down, fd);
    write_int((int)key->escape, fd);
    write_int((int)key->interact, fd);
    write_int((int)key->inventory, fd);
    write_int((int)key->left, fd);
    write_int((int)key->pause, fd);
    write_int((int)key->right, fd);
    write_int((int)key->space, fd);
    write_int((int)key->up, fd);
}

void write_perso(perso_t *perso, int fd)
{
    write_int(perso->combat->attack, fd);
    write_int(perso->combat->defense, fd);
    write_int(perso->combat->level, fd);
    write_int(perso->combat->life, fd);
    write_int(perso->combat->speed, fd);
    write_int(perso->combat->strength, fd);
    write_int(perso->direction, fd);
    write_int(perso->move, fd);
    my_float(2, perso->pos.x, fd);
    write(fd, "\n", 1);
    my_float(2, perso->pos.y, fd);
    write(fd, "\n", 1);
}
