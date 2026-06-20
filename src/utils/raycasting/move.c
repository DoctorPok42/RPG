/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** move
*/

#include <math.h>

#include "game.h"
#include "raycasting_functions.h"
#include "input.h"

static int is_colliding(game_t *game, int x, int y)
{
    raycast_map_t *m = &game->raycasting->maps[game->raycasting->selected_map];
    int cx = (int)game->params->mode.size.y / m->width;
    int cy = (int)game->params->mode.size.y / m->height;

    if (cx <= 0 || cy <= 0)
        return 1;
    return raycast_cell(m, (x + 1) / cx, (y + 1) / cy) != 0;
}

static sfVector2f get_dir(game_t *game)
{
    raycasting_player_t *p = game->raycasting->player;
    float rad = p->direction * PI / 180;

    return (sfVector2f){cos(rad) * game->raycasting->speed,
        sin(rad) * game->raycasting->speed};
}

static void player_move_left_right(game_t *game)
{
    raycasting_player_t *p = game->raycasting->player;
    sfVector2f d = get_dir(game);

    if (is_key_held(game, sfKeyQ)
        && is_colliding(game, p->position.x - d.y, p->position.y - d.x) == 0) {
        p->position.x -= d.y;
        p->position.y -= d.x;
    }
    if (is_key_held(game, sfKeyD)
        && is_colliding(game, p->position.x + d.y, p->position.y + d.x) == 0) {
        p->position.x += d.y;
        p->position.y += d.x;
    }
}

static void player_move_forward_backward(game_t *game)
{
    raycasting_player_t *p = game->raycasting->player;
    sfVector2f d = get_dir(game);

    if (is_key_held(game, sfKeyZ)
        && is_colliding(game, p->position.x + d.x, p->position.y - d.y) == 0) {
        p->position.x += d.x;
        p->position.y -= d.y;
    }
    if (is_key_held(game, sfKeyS)
        && is_colliding(game, p->position.x - d.x, p->position.y + d.y) == 0) {
        p->position.x -= d.x;
        p->position.y += d.y;
    }
}

static void player_rotate(game_t *game)
{
    raycasting_t *r = game->raycasting;

    if (is_key_held(game, sfKeyLeft))
        r->player->direction += r->sensitivity;
    if (is_key_held(game, sfKeyRight))
        r->player->direction -= r->sensitivity;
    if (is_key_held(game, sfKeyUp))
        r->player->pitch += r->sensitivity * 5;
    if (is_key_held(game, sfKeyDown))
        r->player->pitch -= r->sensitivity * 5;
}

void move_raycasting_player(game_t *game)
{
    player_rotate(game);
    player_move_forward_backward(game);
    player_move_left_right(game);
    if (is_key_held(game, sfKeyE)) {
        game->is_raycasting = false;
        game->raycasting->player->position = (sfVector2f){500, 500};
    }
}
