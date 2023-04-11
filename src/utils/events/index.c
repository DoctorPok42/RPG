/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** index
*/

#include "game.h"

void exit_start_all(game_t *game);

void events_window(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
        &game->window->event)) {
        if (game->window->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            exit_start_all(game);
        }
    }
}
