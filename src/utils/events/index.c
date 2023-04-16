/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** index
*/

#include "game.h"

void exit_start_all(game_t *game);
void zoom(game_t *game);
void change_item(game_t *game);
void event_menu(game_t *game);

void events_window(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
        &game->window->event)) {
        if (game->window->event.type == sfEvtKeyPressed &&
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            event_menu(game);
        }

        zoom(game);
        change_item(game);
    }
}
