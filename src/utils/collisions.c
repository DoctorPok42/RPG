/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** collisions
*/

#include "game.h"
#include "collisions.h"

static int is_solid_pixel(const sfImage *img, int x, int y)
{
    sfVector2u size = sfImage_getSize(img);
    sfColor color;

    if (x < 0 || y < 0 || (unsigned)x >= size.x || (unsigned)y >= size.y)
        return 1;
    color = sfImage_getPixel(img, (sfVector2u){(unsigned)x, (unsigned)y});
    return color.r == 0 && color.g == 0 && color.b == 0;
}

static int is_colliding_horizontaly(game_t *game, const sfVector2f *pos,
    const sfVector2f *offset)
{
    sfImage *img = game->map->colls_image;
    int bx = (int)game->map->rect.position.x;
    int by = (int)game->map->rect.position.y;

    if (is_solid_pixel(img, pos->x / 3 + bx, pos->y / 3 + by))
        return -1;
    if (is_solid_pixel(img, (pos->x + offset->x) / 3 + bx,
            (pos->y + offset->y) / 3 + by))
        return -1;
    return 0;
}

static int is_colliding_verticaly(game_t *game, const sfVector2f *pos,
    const sfVector2f *offset)
{
    sfImage *img = game->map->colls_image;
    int bx = (int)game->map->rect.position.x;
    int by = (int)game->map->rect.position.y;

    if (is_solid_pixel(img, pos->x / 3 + bx, (pos->y + offset->y) / 3 + by))
        return -1;
    if (is_solid_pixel(img, (pos->x + offset->x) / 3 + bx, pos->y / 3 + by))
        return -1;
    return 0;
}

int is_colliding(game_t *game, const sfVector2f *pos, const sfVector2f *offset)
{
    if (is_colliding_horizontaly(game, pos, offset) == -1)
        return -1;
    if (is_colliding_verticaly(game, pos, offset) == -1)
        return -1;
    return 0;
}
