/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** map_iso
*/

#include "game.h"

void display_iso_map(game_t *game)
{
    if (game->menu >= 5 && game->menu < 10) {
        sfRenderWindow_drawSprite(game->window->window,
            game->map->iso_sprite, NULL);
    }
}
