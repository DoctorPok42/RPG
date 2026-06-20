/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** get_wall
*/

#include <math.h>

#include "game.h"
#include "raycasting_functions.h"

static void search_wall(game_t *game, float i, float angle_temp)
{
    raycast_map_t *m = &game->raycasting->maps[game->raycasting->selected_map];
    ray_t *ray = game->raycasting->rays[(int)i];
    int cell = (int)game->params->mode.size.y / m->width;
    int d = 0;

    for (d = 0; cell > 0 && d < MAX_RAY_DEPTH; d++) {
        ray->x_detect = game->raycasting->player->position.x
            + cos(angle_temp * PI / 180) * d + 1;
        ray->y_detect = game->raycasting->player->position.y
            - sin(angle_temp * PI / 180) * d + 1;
        if (raycast_cell(m, ray->x_detect / cell, ray->y_detect / cell) != 0)
            break;
    }
    ray->distance = d;
}

static void do_maths(game_t *game, float i)
{
    ray_t *ray = game->raycasting->rays[(int)i];
    raycasting_player_t *p = game->raycasting->player;
    float fov = (float)game->raycasting->fov / 2;
    float distance = 0;

    distance = sqrt(pow(ray->x_detect - p->position.x, 2)
        + pow(ray->y_detect - p->position.y, 2)) / 3.5;
    ray->form_height = 50000 / (cos((fov - i / game->raycasting->resolution)
            * PI / 180) * distance);
    ray->position = (sfVector2f){i * ray->depth,
        ((game->params->mode.size.y - ray->form_height) / 2) + p->pitch};
}

void get_wall(game_t *game, float i)
{
    raycasting_t *r = game->raycasting;
    float angle_temp = r->player->direction + (float)r->fov / 2
        - i / r->resolution;

    r->rays[(int)i]->depth = (float)1920 / (r->fov * r->resolution);
    search_wall(game, i, angle_temp);
    do_maths(game, i);
    define_wall(game, i);
}
