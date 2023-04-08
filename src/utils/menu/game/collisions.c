/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collisions
*/

#include "lists.h"

int is_colliding(menu_t *menu, sfVector2f pos)
{
    sfColor color = sfImage_getPixel(menu->colls_image,
    pos.x / 2.25, pos.y / 2.08);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(menu->colls_image,
    (pos.x + 35) / 2.25, (pos.y + 40) / 2.08);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(menu->colls_image,
    pos.x / 2.25, (pos.y + 40) / 2.08);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;

    color = sfImage_getPixel(menu->colls_image,
    (pos.x + 35) / 2.25, pos.y / 2.08);
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return -1;
    return 0;
}
