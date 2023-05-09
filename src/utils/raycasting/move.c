/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** move
*/

#include <math.h>

#include "game.h"

static int is_colliding (game_t *game, int x, int y)
{
    int pos_in_map = (x + 1) / (game->params->mode.height /
    game->raycasting->maps[game->raycasting->selected_map].width)
    + (y + 1) / (game->params->mode.height /
    game->raycasting->maps[game->raycasting->selected_map].height) *
    game->raycasting->maps[game->raycasting->selected_map].width;

    if (game->raycasting->maps[game->raycasting->selected_map].
    map[pos_in_map] != 0)
        return 1;

    return 0;
}

static void player_move_left_right (game_t *game)
{
    float dir_x = cos(game->raycasting->player->direction * PI / 180) *
    game->raycasting->speed;
    float dir_y = sin(game->raycasting->player->direction * PI / 180) *
    game->raycasting->speed;

    if (sfKeyboard_isKeyPressed(sfKeyQ) && is_colliding(game, game->raycasting->
    player->position.x - dir_y, game->raycasting->player->position.y -
    dir_x) == 0) {
            game->raycasting->player->position.x -= dir_y;
            game->raycasting->player->position.y -= dir_x;
    }

    if (sfKeyboard_isKeyPressed(sfKeyD) && is_colliding(game, game->raycasting->
    player->position.x + dir_y, game->raycasting->player->position.y +
    dir_x) == 0) {
            game->raycasting->player->position.x += dir_y;
            game->raycasting->player->position.y += dir_x;
    }
}

static void player_move_forwar_backward (game_t *game)
{
    float dir_x = cos(game->raycasting->player->direction * PI / 180) *
    game->raycasting->speed;
    float dir_y = sin(game->raycasting->player->direction * PI / 180) *
    game->raycasting->speed;

    if (sfKeyboard_isKeyPressed(sfKeyZ) && is_colliding(game, game->raycasting->
    player->position.x + dir_x, game->raycasting->player->position.y -
    dir_y) == 0) {
            game->raycasting->player->position.x += dir_x;
            game->raycasting->player->position.y -= dir_y;
    }

    if (sfKeyboard_isKeyPressed(sfKeyS) && is_colliding(game, game->raycasting->
    player->position.x - dir_x, game->raycasting->player->position.y +
    dir_y) == 0) {
            game->raycasting->player->position.x -= dir_x;
            game->raycasting->player->position.y += dir_y;
    }
}

static void player_rotate (game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        game->raycasting->player->direction += game->raycasting->sensitivity;

    if (sfKeyboard_isKeyPressed(sfKeyRight))
        game->raycasting->player->direction -= game->raycasting->sensitivity;

    if (sfKeyboard_isKeyPressed(sfKeyUp))
        game->raycasting->player->pitch += game->raycasting->sensitivity * 5;

    if (sfKeyboard_isKeyPressed(sfKeyDown))
        game->raycasting->player->pitch -= game->raycasting->sensitivity * 5;
}

void move_raycasting_player (game_t *game)
{
    player_rotate(game);
    player_move_forwar_backward(game);
    player_move_left_right(game);

    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        game->is_raycasting = false;
        game->raycasting->player->position = (sfVector2f) {500, 500};
    }
}
