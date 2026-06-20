/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** map_iso
*/

#include "game.h"
#include "menu.h"

void display_iso_map(game_t *game)
{
    if (menu_in_overworld(game)) {
        sfRenderWindow_drawSprite(game->window->window,
            game->map->iso_sprite, NULL);
    }
}
