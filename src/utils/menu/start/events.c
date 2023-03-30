/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** events
*/

#include "lists.h"

void close_start_all(menu_t *menu);

void events(menu_t *menu, sfEvent event)
{
    while (sfRenderWindow_pollEvent(menu->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            close_start_all(menu);
        }
    }
}
