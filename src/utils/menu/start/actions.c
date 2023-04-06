/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** close
*/

#include "lists.h"

void go_back(menu_t *menu)
{
    menu->close = 0;
    menu->current = 0;
}

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

void exit_start_all(menu_t *menu)
{
    sfMusic_stop(menu->song->music);
    sfMusic_destroy(menu->song->music);
    sfRenderWindow_close(menu->window);
    menu->close = 2;
}
