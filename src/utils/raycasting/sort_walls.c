/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** sort_walls
*/

#include "game.h"

void swap_rays (game_t *game, int i, int j)
{
    if (game->raycasting->rays[i]->distance >
    game->raycasting->rays[j]->distance) {
        ray_t *tmp = game->raycasting->rays[i];
        game->raycasting->rays[i] = game->raycasting->rays[j];
        game->raycasting->rays[j] = tmp;
    }
}

void sort_walls_by_distance (game_t *game)
{
    for (int i = 0; i < game->raycasting->nb_rays - 1; i += 1)
        for (int j = 0; j < game->raycasting->nb_rays - 1; j += 1)
            swap_rays(game, i, j);
}
