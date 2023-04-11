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
    pos.x / 3 + game->map->rect.left, pos.y / 3 + game->map->rect.top);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(game->map->colls_image, (pos.x + 35) / 3 +
    game->map->rect.left, (pos.y + 40) / 3 + game->map->rect.top);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(game->map->colls_image,
    pos.x / 3 + game->map->rect.left, (pos.y + 50) / 3 + game->map->rect.top);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(game->map->colls_image,
    (pos.x + 45) / 3 + game->map->rect.left, pos.y / 3 + game->map->rect.top);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;
    return 0;
}
