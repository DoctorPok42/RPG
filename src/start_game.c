/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** start_game
*/

#include "game.h"

void create_game(game_t *game);
void events_window(game_t *game);
void display_all(game_t *game);
int raycasting (game_t *game);

static void init_game(game_t *game)
{
    game->params = malloc(sizeof(params_t));
    game->params->volume = 100;
    game->params->fps = 60;
    game->params->fullscreen = 0;
    game->params->resolution = (sfVector2u){1920, 1080};
    game->params->window_size = (sfVector2u){1920, 1080};
    game->params->mode = (sfVideoMode){1920, 1080, 32};
    game->keys = malloc(sizeof(keys_t));
    game->keys->up = sfKeyUp; game->keys->down = sfKeyDown;
    game->keys->left = sfKeyLeft; game->keys->right = sfKeyRight;
    game->keys->escape = sfKeyEscape;
    game->keys->space = sfKeySpace;
    game->keys->interact = sfKeyE;
    game->keys->inventory = sfKeyI;
    game->keys->pause = sfKeyP;
    game->keys->attack = sfKeyA;
    game->clock = malloc(sizeof(clocks_t));
    game->clock->clock = sfClock_create();
    game->perso = malloc(sizeof(perso_t));
    game->perso->clock = sfClock_create();
}

int start_game(game_t *game)
{
    init_game(game);
    create_game(game);

    while (sfRenderWindow_isOpen(game->window->window)) {
        if (game->is_raycasting == false) {
            events_window(game);
            display_all(game);
        } else
            raycasting(game);
    }

    if (game->network != NULL)
        sfTcpSocket_disconnect(game->network->server);

    return (0);
}
