/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collisions
*/

#include "game.h"

int is_colliding(game_t *game, sfVector2f pos)
{
    sfColor color = sfImage_getPixel(game->map->colls_image,
    pos.x / 2.25, pos.y / 2.08);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(game->map->colls_image,
    (pos.x + 35) / 2.25, (pos.y + 40) / 2.08);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(game->map->colls_image,
    pos.x / 2.25, (pos.y + 40) / 2.08);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(game->map->colls_image,
    (pos.x + 35) / 2.25, pos.y / 2.08);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;
    return 0;
}
