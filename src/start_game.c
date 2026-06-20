/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** start_game
*/

#include "game.h"
#include "create.h"
#include "display.h"
#include "events.h"
#include "raycasting_functions.h"
#include "config.h"

static bool init_keys(game_t *game)
{
    game->keys = malloc(sizeof(keys_t));
    if (game->keys == NULL)
        return false;
    game->keys->up = sfKeyUp;
    game->keys->down = sfKeyDown;
    game->keys->left = sfKeyLeft;
    game->keys->right = sfKeyRight;
    game->keys->escape = sfKeyEscape;
    game->keys->space = sfKeySpace;
    game->keys->interact = sfKeyE;
    game->keys->inventory = sfKeyI;
    game->keys->pause = sfKeyP;
    game->keys->attack = sfKeyA;
    return true;
}

static bool init_game(game_t *game)
{
    if (init_keys(game) == false)
        return false;
    game->clock = malloc(sizeof(clocks_t));
    if (game->clock == NULL)
        return false;
    game->clock->clock = sfClock_create();
    game->perso = malloc(sizeof(perso_t));
    if (game->perso == NULL)
        return false;
    game->perso->clock = sfClock_create();
    return true;
}

static bool init_params(game_t *game)
{
    game->params = malloc(sizeof(params_t));
    if (game->params == NULL)
        return false;
    game->params[0] = (params_t){0};
    game->params->volume = DEFAULT_VOLUME;
    game->params->fps = DEFAULT_FPS;
    game->params->fullscreen = 0;
    game->params->resolution = (sfVector2u){DEFAULT_WIDTH, DEFAULT_HEIGHT};
    game->params->window_size = (sfVector2u){DEFAULT_WIDTH, DEFAULT_HEIGHT};
    game->params->mode = (sfVideoMode){
        .size = {DEFAULT_WIDTH, DEFAULT_HEIGHT}, .bitsPerPixel = DEFAULT_BPP};
    return true;
}

int start_game(game_t *game)
{
    if (init_game(game) == false || init_params(game) == false)
        return EPITECH_ERROR;
    create_game(game);
    while (sfRenderWindow_isOpen(game->window->window)) {
        if (game->is_raycasting == false) {
            events_window(game);
            display_all(game);
        } else
            raycasting(game);
    }
    return EPITECH_SUCCESS;
}
