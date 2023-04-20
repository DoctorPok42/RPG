/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** close
*/

#include "game.h"


void relase_button(buttons_t **button, int i, int max);

void go_back(game_t *game)
{
    game->menu /= 10;
    if (game->menu > 500)
        game->menu /= 10;
    relase_button(game->params->visu->navbar->button, 0, 5);
}

void change_to_settings(game_t *game)
{
    game->params->tmp = 0;
    if (game->menu <= 563) {
        game->menu = 20;
    } else {
        game->menu = game->menu / 10 * 10 + 1;
    }
}

void close_start_all(game_t *game)
{
    game->menu = game->menu * 10 + 4;
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
    game->menu = game->menu * 10 + 3;
}
