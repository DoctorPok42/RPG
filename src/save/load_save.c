/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-remi.mazat
** File description:
** load_save
*/

#include <stdio.h>

#include "game.h"
#include "my_str.h"
#include "save_functions.h"

static void get_params(params_t *param, char **text, int i)
{
    param->fps = my_getnbr(text[i]);
    param->fullscreen = my_getnbr(text[i + 1]);
    param->mode.bitsPerPixel = my_getnbr(text[i + 2]);
    param->mode.size.y = my_getnbr(text[i + 3]);
    param->mode.size.x = my_getnbr(text[i + 4]);
    param->resolution.x = my_getnbr(text[i + 5]);
    param->resolution.y = my_getnbr(text[i + 6]);
    param->scale = my_getnbr(text[i + 7]);
    param->volume = my_getnbr(text[i + 8]);
    param->window_size.x = my_getnbr(text[i + 9]);
    param->window_size.y = my_getnbr(text[i + 10]);
}

static void get_keys(keys_t *key, char **text, int i)
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
}

static void get_perso(perso_t *perso, char **text, int i)
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
}

game_t *load_save(char *filepath, game_t *game)
{
    FILE *file = fopen(filepath, "r");
    char **text = NULL;

    if (file == NULL)
        return game;
    text = get_text(file);
    fclose(file);
    if (text == NULL || my_tablen(text) < SAVE_FIELDS) {
        free_tab(text);
        return game;
    }
    get_params(game->params, text, 0);
    get_keys(game->keys, text, 0);
    get_perso(game->perso, text, 0);
    free_tab(text);
    return game;
}
