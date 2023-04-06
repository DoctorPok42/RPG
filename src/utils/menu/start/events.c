/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** events
*/

#include "lists.h"

void exit_start_all(menu_t *menu);

void events_start(game_t *game, menu_t *menu, sfEvent event)
{
    while (sfRenderWindow_pollEvent(menu->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            exit_start_all(menu);
        }

        if (event.type == sfEvtMouseWheelScrolled) {
            game->scale = (event.mouseWheelScroll.delta > 0) ?
                game->scale + 1 : game->scale - 1;
        }
    }
}
