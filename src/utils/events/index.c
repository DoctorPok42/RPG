/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** index
*/

#include "rpg.h"
#include "game.h"

void exit_start_all(game_t *game);

void events_window(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
        &game->window->event)) {
        if (game->window->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfMusic_stop(game->window->song->music);
            sfMusic_destroy(game->window->song->music);
            sfRenderWindow_close(game->window->window);
        }
    }
}
