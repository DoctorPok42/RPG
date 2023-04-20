/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-remi.mazat
** File description:
** load_save
*/

#include "game.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char **get_text(FILE *file);
int free_tab(char **tab);

params_t *get_params(params_t *param, char **text, int i)
{
    param->fps = my_getnbr(text[i]);
    param->fullscreen = my_getnbr(text[i + 1]);
    param->mode.bitsPerPixel = my_getnbr(text[i + 2]);
    param->mode.height = my_getnbr(text[i + 3]);
    param->mode.width = my_getnbr(text[i + 4]);
    param->resolution.x = my_getnbr(text[i + 5]);
    param->resolution.y = my_getnbr(text[i + 6]);
    param->scale = my_getnbr(text[i + 7]);
    param->volume = my_getnbr(text[i + 8]);
    param->window_size.x = my_getnbr(text[i + 9]);
    param->window_size.y = my_getnbr(text[i + 10]);
    return param;
}

keys_t *get_keys(keys_t *key, char **text, int i)
{
    key->attack = (sfKeyCode)my_getnbr(text[i + 11]);
    key->down = (sfKeyCode)my_getnbr(text[i + 12]);
    key->escape = (sfKeyCode)my_getnbr(text[i + 13]);
    key->interact = (sfKeyCode)my_getnbr(text[i + 14]);
    key->inventory = (sfKeyCode)my_getnbr(text[i + 15]);
    key->left = (sfKeyCode)my_getnbr(text[i + 16]);
    key->pause = (sfKeyCode)my_getnbr(text[i + 17]);
    key->right = (sfKeyCode)my_getnbr(text[i + 18]);
    key->space = (sfKeyCode)my_getnbr(text[i + 19]);
    key->up = (sfKeyCode)my_getnbr(text[i + 20]);
    return key;
}

perso_t *get_perso(perso_t *perso, char **text, int i)
{
    perso->combat->attack = my_getnbr(text[i + 21]);
    perso->combat->defense = my_getnbr(text[i + 22]);
    perso->combat->level = my_getnbr(text[i + 23]);
    perso->combat->life = my_getnbr(text[i + 24]);
    perso->combat->speed = my_getnbr(text[i + 25]);
    perso->combat->strength = my_getnbr(text[i + 26]);
    perso->direction = my_getnbr(text[i + 27]);
    perso->move = my_getnbr(text[i + 28]);
    perso->pos.x = my_getnbr(text[i + 29]);
    perso->pos.y = my_getnbr(text[i + 30]);
    return perso;
}

game_t *load_save(char *filepath, game_t *game)
{
    FILE * file = fopen(filepath, "r");
    char **text = NULL;
    text = get_text(file);
    int i = 0;
    int index_dialog = my_getnbr(text[0]);
    for (int i = 0; i < index_dialog; i++) {
        game->dialogs->dialog = game->dialogs->dialog->next;
    }
    while (my_strcmp(text[i], "params") != 0)
        i++;
    i++;
    game->params = get_params(game->params, text, i);
    game->keys = get_keys(game->keys, text, i);
    game->perso = get_perso(game->perso, text, i);
    free_tab(text);
    fclose(file);
    return game;
}
