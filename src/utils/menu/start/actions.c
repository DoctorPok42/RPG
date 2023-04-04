/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** close
*/

#include "lists.h"

void change_to_settings(menu_t *menu)
{
    menu->current = 2;
}

void close_start_all(menu_t *menu)
{
    sfMusic_stop(menu->song->music);
    sfMusic_destroy(menu->song->music);
    sfRenderWindow_close(menu->window);
    menu->close = 1;
}
