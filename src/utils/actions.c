/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** close
*/

#include "game.h"

void go_back(game_t *game)
{
    game->menu /= 10;
}

void change_to_settings(game_t *game)
{
    game->params->tmp = 0;
    game->menu = 2;
}

void close_start_all(game_t *game)
{
    game->menu = 4;
}

void exit_start_all(game_t *game)
{
    sfMusic_stop(game->window->song->music);
    sfMusic_destroy(game->window->song->music);
    sfRenderWindow_close(game->window->window);
    free(game->window->song);
    free(game->perso);
    free(game->params);
}

void change_to_save(game_t *game)
{
    game->menu = 3;
}
