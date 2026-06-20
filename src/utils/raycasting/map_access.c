/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** map_access
*/

#include "game.h"
#include "raycasting_functions.h"

int raycast_cell(const raycast_map_t *map, int col, int row)
{
    if (col < 0 || row < 0 || col >= map->width || row >= map->height)
        return 1;
    return map->map[col + row * map->width];
}
