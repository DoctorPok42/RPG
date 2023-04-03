/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** events
*/

#include "lists.h"

void close_start_all(menu_t *menu);

void events(game_t *game, menu_t *menu, sfEvent event)
{
    while (sfRenderWindow_pollEvent(menu->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            close_start_all(menu);
        }

        if (event.type == sfEvtMouseWheelScrolled) {
            game->scale = (event.mouseWheelScroll.delta > 0) ?
                game->scale + 1 : game->scale - 1;
        }
    }
}
