/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** define_wall
*/

#include "game.h"
#include "raycasting_functions.h"

static int neighbors_orientation(const raycast_map_t *m, int cx, int cy,
    ray_t *r)
{
    int left = raycast_cell(m, (r->x_detect - 1) / cx, r->y_detect / cy);
    int right = raycast_cell(m, (r->x_detect + 1) / cx, r->y_detect / cy);
    int up = raycast_cell(m, r->x_detect / cx, (r->y_detect - 1) / cy);
    int down = raycast_cell(m, r->x_detect / cx, (r->y_detect + 1) / cy);

    if ((left == 0 || right == 0) && up != 0 && down != 0)
        return 1;
    if (left != 0 || right != 0)
        return 2;
    return 0;
}

static int wall_orientation(game_t *game, float i)
{
    raycast_map_t *m = &game->raycasting->maps[game->raycasting->selected_map];
    ray_t *r = game->raycasting->rays[(int)i];
    int cx = (int)game->params->mode.size.y / m->width;
    int cy = (int)game->params->mode.size.y / m->height;

    if (cx <= 0 || cy <= 0)
        return 0;
    return neighbors_orientation(m, cx, cy, r);
}

static void define_wall_x(game_t *game, float i)
{
    raycast_map_t *m = &game->raycasting->maps[game->raycasting->selected_map];
    ray_t *r = game->raycasting->rays[(int)i];
    int cx = (int)game->params->mode.size.y / m->width;
    int cy = (int)game->params->mode.size.y / m->height;
    int test = 0;

    if (cx <= 0 || cy <= 0)
        return;
    test = raycast_cell(m, (r->x_detect + 1) / cx, r->y_detect / cy);
    r->sprite = test != 0 ? test
        : raycast_cell(m, (r->x_detect - 1) / cx, r->y_detect / cy);
    r->texture_rect = (sfIntRect){
        .position = {r->x_detect % cx * 250 / cx, 0}, .size = {1, 250}};
    r->brightness = 255;
}

static void define_wall_y(game_t *game, float i)
{
    raycast_map_t *m = &game->raycasting->maps[game->raycasting->selected_map];
    ray_t *r = game->raycasting->rays[(int)i];
    int cx = (int)game->params->mode.size.y / m->width;
    int cy = (int)game->params->mode.size.y / m->height;

    if (cx <= 0 || cy <= 0)
        return;
    r->sprite = raycast_cell(m, r->x_detect / cx, (r->y_detect - 1) / cy);
    r->texture_rect = (sfIntRect){
        .position = {r->y_detect % cy * 250 / cy, 0}, .size = {1, 250}};
    r->brightness = 200;
}

void define_wall(game_t *game, float i)
{
    ray_t *r = game->raycasting->rays[(int)i];
    int orientation = wall_orientation(game, i);

    if (orientation == 1)
        define_wall_y(game, i);
    else if (orientation == 2)
        define_wall_x(game, i);
    r->size = (sfVector2f){r->depth, r->form_height};
    r->color = (sfColor){r->brightness, r->brightness, r->brightness, 255};
}
