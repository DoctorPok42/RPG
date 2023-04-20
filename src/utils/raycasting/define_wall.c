/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** define_wall
*/

#include <math.h>

#include "game.h"

int check_wall_orientation (game_t *game, float i)
{
    raycast_map_t map = game->raycasting->maps[game->raycasting->selected_map];
    int x_detect = game->raycasting->rays[(int) i]->x_detect;
    int y_detect = game->raycasting->rays[(int) i]->y_detect;

    if ((map.map[(x_detect + 1) / (game->params->mode.height / map.width) +
    y_detect / (game->params->mode.height / map.height) * map.width] == 0 || map
    .map[(x_detect - 1) / (game->params->mode.height / map.width) + y_detect /
    (game->params->mode.height / map.height) * map.width] == 0) && (map.map[(
    x_detect) / (game->params->mode.height / map.width) + (y_detect + 1) / (game
    ->params->mode.height / map.height) * map.width] != 0 && map.map[(x_detect)
    / (game->params->mode.height / map.width) + (y_detect - 1) / (game->params->
    mode.height / map.height) * map.width] != 0))
        return 1;

    else if ((map.map[(x_detect + 1) / (game->params->mode.height / map.width)
    + y_detect / (game->params->mode.height / map.height) * map.width] != 0 ||
    map.map[(x_detect - 1) / (game->params->mode.width / map.width) + y_detect /
    (game->params->mode.height / map.height) * map.width] != 0))
        return 2;
    return 0;
}

void define_wall_x (game_t *game, float i)
{
    raycast_map_t map = game->raycasting->maps[game->raycasting->selected_map];
    int x_detect = game->raycasting->rays[(int) i]->x_detect;
    int y_detect = game->raycasting->rays[(int) i]->y_detect;

    int test1 = map.map[(x_detect + 1) / (game->params->mode.height / map.width)
    + y_detect / (game->params->mode.height / map.height) * map.width];
    int test2 = map.map[(x_detect - 1) / (game->params->mode.height / map.width)
    + y_detect / (game->params->mode.height / map.height) * map.width];

    if (test1 != 0)
        game->raycasting->rays[(int) i]->sprite = test1;
    else
        game->raycasting->rays[(int) i]->sprite = test2;

    game->raycasting->rays[(int) i]->texture_rect = (sfIntRect) {x_detect %
    (game->params->mode.height / map.width) * 250 /
    (game->params->mode.height / map.width), 0, 1, 250};

    game->raycasting->rays[(int) i]->brightness = 255;
}

void define_wall_y (game_t *game, float i)
{
    raycast_map_t map = game->raycasting->maps[game->raycasting->selected_map];
    int x_detect = game->raycasting->rays[(int) i]->x_detect;
    int y_detect = game->raycasting->rays[(int) i]->y_detect;

    game->raycasting->rays[(int) i]->sprite = map.map[(x_detect) /
    (game->params->mode.height / map.width) + (y_detect - 1) /
    (game->params->mode.height / map.height) * map.width];

    game->raycasting->rays[(int) i]->texture_rect = (sfIntRect) {y_detect %
    (game->params->mode.height / map.height) * 250 /
    (game->params->mode.height / map.height), 0, 1, 250};

    game->raycasting->rays[(int) i]->brightness = 200;
}

void define_wall (game_t *game, float i)
{
    raycast_map_t map = game->raycasting->maps[game->raycasting->selected_map];
    int x_detect = game->raycasting->rays[(int) i]->x_detect;
    int y_detect = game->raycasting->rays[(int) i]->y_detect;

    int wall_orientation = check_wall_orientation(game, i);

    if (wall_orientation == 1)
        define_wall_y(game, i);
    else if (wall_orientation == 2)
        define_wall_x(game, i);

    game->raycasting->rays[(int) i]->size = (sfVector2f) {game->raycasting->rays
    [(int) i]->depth, game->raycasting->rays[(int) i]->form_height};

    game->raycasting->rays[(int) i]->color = (sfColor) {game->raycasting->rays
    [(int) i]->brightness, game->raycasting->rays[(int)i]->brightness,
    game->raycasting->rays[(int) i]->brightness, 255};
}
