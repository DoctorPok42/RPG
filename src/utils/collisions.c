/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collisions
*/

#include "game.h"

int is_colliding_horizontaly (game_t *game, sfVector2f pos, sfVector2f offset)
{
    sfColor color = sfImage_getPixel(game->map->colls_image,
    pos.x / 3 + game->map->rect.left, pos.y / 3 + game->map->rect.top);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(game->map->colls_image, (pos.x + offset.x) / 3 +
    game->map->rect.left, (pos.y + offset.y) / 3 + game->map->rect.top);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    return 0;
}

int is_colliding_verticaly (game_t *game, sfVector2f pos, sfVector2f offset)
{
    sfColor color = sfImage_getPixel(game->map->colls_image,
    pos.x / 3 + game->map->rect.left, (pos.y + offset.y) / 3 +
    game->map->rect.top);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(game->map->colls_image,
    (pos.x + offset.x) / 3 + game->map->rect.left, pos.y / 3 +
    game->map->rect.top);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    return 0;
}

int is_colliding(game_t *game, sfVector2f pos, sfVector2f offset)
{
    if (pos.x + offset.x < 0 || pos.y + offset.y < 0 || pos.x < 0 || pos.y < 0)
        return -1;

    if (is_colliding_horizontaly(game, pos, offset) == -1)
        return -1;
    if (is_colliding_verticaly(game, pos, offset) == -1)
        return -1;

    return 0;
}
