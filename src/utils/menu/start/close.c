/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** close
*/

#include "lists.h"

void close_start_all(menu_t *menu)
{
    sfMusic_stop(menu->song->music);
    sfMusic_destroy(menu->song->music);
    sfRenderWindow_close(menu->window);
}
