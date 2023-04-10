/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** close
*/

#include "game.h"

void go_back(game_t *game)
{
    game->window->close = 0;
}

void change_to_settings(game_t *game)
{
    game->params->tmp = 0;
    game->window->close = 0;
}

void close_start_all(game_t *game)
{
    game->menu = 1;
}

void exit_start_all(game_t *game)
{
    sfMusic_stop(game->window->song->music);
    sfMusic_destroy(game->window->song->music);
    sfRenderWindow_close(game->window->window);
    sfRenderWindow_destroy(game->window->window);
    game->window->close = 1;
}
