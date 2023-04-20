/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** draw_entity
*/

#include <math.h>

#include "game.h"
#include "raycasting.h"

float get_entity_angle (game_t *game, entity_t *entity)
{
    sfVector2f diff = {entity->position.x - game->raycasting->player->
    position.x, entity->position.y - game->raycasting->player->position.y};

    float angle = atan2(diff.y, diff.x) * 180 / PI;
    float angle_perso = game->raycasting->player->direction;
    angle_perso = (int) angle_perso % 360;
    if (angle_perso < 0) {
        angle_perso += 360;
    }
    angle = -angle - angle_perso;
    angle = angle + 30;
    angle = (angle - 60) * -1;

    for (;angle > 360; angle -= 360);
    if (angle < -20 || angle > 80)
        return - 20000;

    angle = angle * game->raycasting->resolution;

    return angle;
}

double get_entity_distance (game_t *game, entity_t *entity)
{
    return sqrt(pow(entity->position.x - game->raycasting->player->
    position.x, 2) + pow(entity->position.y - game->raycasting->player->
    position.y, 2));
}

void calculate_entity_form (game_t *game, entity_t *entity)
{
    entity->angle = get_entity_angle(game, entity);
    if (entity->angle == -20000)
        return;
    entity->distance = get_entity_distance(game, entity);

    float angle_temp = game->raycasting->player->direction
    + (float) game->raycasting->fov / 2 - entity->angle /
    game->raycasting->resolution;

    int x_detect = game->raycasting->player->position.x +
    cos(angle_temp * PI / 180)  *entity->distance + 1;
    int y_detect = game->raycasting->player->position.y -
    sin(angle_temp * PI / 180) * entity->distance + 1;
    float distance = sqrt(pow(x_detect - game->raycasting->player->position.x,
    2) + pow(y_detect - game->raycasting->player->position.y, 2));
    entity->form_height = 50000 / (cos(((float) game->raycasting->fov / 2 -
    entity->angle / game->raycasting->resolution) * PI / 180) * distance);

    entity->depth = (float) 1920 / (game->raycasting->fov * game->raycasting->
    resolution);
}
