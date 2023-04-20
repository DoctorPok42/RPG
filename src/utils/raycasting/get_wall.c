/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** get_wall
*/

#include <math.h>

#include "game.h"

void define_wall (game_t *game, float i);

void search_wall (game_t *game, float i, float angle_temp)
{
    raycast_map_t map = game->raycasting->maps[game->raycasting->selected_map];
    int x_detect = 0;
    int y_detect = 0;
    int d_detect = 0;

    while (1) {
        x_detect = game->raycasting->player->position.x +
        cos(angle_temp * PI / 180) * d_detect + 1;
        y_detect = game->raycasting->player->position.y -
        sin(angle_temp * PI / 180) * d_detect + 1;

        if (map.map[x_detect / (game->params->mode.height / map.width) +
        y_detect / (game->params->mode.height / map.width) * map.width] != 0) {
            game->raycasting->rays[(int) i]->distance = d_detect;
            game->raycasting->rays[(int) i]->x_detect = x_detect;
            game->raycasting->rays[(int) i]->y_detect = y_detect;
            return;
        }
        d_detect += 1;
    }
}

void do_maths (game_t *game, float i)
{
    float distance = sqrt(pow(game->raycasting->rays[(int) i]->x_detect -
    game->raycasting->player->position.x, 2) + pow(game->raycasting->rays
    [(int) i]->y_detect - game->raycasting->player->position.y,2));
    distance /= 3.5;

    game->raycasting->rays[(int) i]->form_height = 50000 / (cos(((float)
    game->raycasting->fov / 2 - i / game->raycasting->resolution) * PI / 180) *
    distance);

    game->raycasting->rays[(int) i]->position = (sfVector2f) {i * game->
    raycasting->rays[(int) i]->depth, ((game->params->mode.height - game->
    raycasting->rays[(int) i]->form_height) / 2) + game->raycasting->
    player->pitch};
}

void get_wall (game_t *game, float i)
{
    float angle_temp = game->raycasting->player->direction +
    (float) game->raycasting->fov / 2 - i / game->raycasting->resolution;

    game->raycasting->rays[(int) i]->depth = (float) 1920 / (game->raycasting->
    fov * game->raycasting->resolution);

    search_wall(game, i, angle_temp);
    do_maths(game, i);
    define_wall(game, i);
}
