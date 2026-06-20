/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** sort_walls
*/

#include "game.h"
#include "raycasting_functions.h"

static void swap_rays(game_t *game, int i, int j)
{
    ray_t *tmp = NULL;

    if (game->raycasting->rays[i]->distance
        <= game->raycasting->rays[j]->distance)
        return;
    tmp = game->raycasting->rays[i];
    game->raycasting->rays[i] = game->raycasting->rays[j];
    game->raycasting->rays[j] = tmp;
}

void sort_walls_by_distance(game_t *game)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < game->raycasting->nb_rays - 1; i++)
        for (j = 0; j < game->raycasting->nb_rays - 1; j++)
            swap_rays(game, i, j);
}
