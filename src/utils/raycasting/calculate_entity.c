/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** draw_entity
*/

#include <math.h>

#include "game.h"
#include "raycasting_functions.h"

static float get_entity_angle(game_t *game, entity_t *entity)
{
    raycasting_player_t *p = game->raycasting->player;
    sfVector2f diff = {entity->position.x - p->position.x,
        entity->position.y - p->position.y};
    float angle = atan2(diff.y, diff.x) * 180 / PI;
    float angle_perso = (int)p->direction % 360;

    if (angle_perso < 0)
        angle_perso += 360;
    angle = ((-angle - angle_perso) + 30 - 60) * -1;
    while (angle > 360)
        angle -= 360;
    if (angle < -20 || angle > 80)
        return -20000;
    return angle * game->raycasting->resolution;
}

static double get_entity_distance(game_t *game, entity_t *entity)
{
    raycasting_player_t *p = game->raycasting->player;

    return sqrt(pow(entity->position.x - p->position.x, 2)
        + pow(entity->position.y - p->position.y, 2));
}

static void project_entity(game_t *game, entity_t *entity, float angle_temp)
{
    raycasting_t *rc = game->raycasting;
    int x_detect = rc->player->position.x
        + cos(angle_temp * PI / 180) * entity->distance + 1;
    int y_detect = rc->player->position.y
        - sin(angle_temp * PI / 180) * entity->distance + 1;
    float distance = sqrt(pow(x_detect - rc->player->position.x, 2)
        + pow(y_detect - rc->player->position.y, 2));
    float fov_angle = ((float)rc->fov / 2
        - entity->angle / rc->resolution) * PI / 180;

    entity->form_height = 50000 / (cos(fov_angle) * distance);
    entity->depth = (float)1920 / (rc->fov * rc->resolution);
}

void calculate_entity_form(game_t *game, entity_t *entity)
{
    raycasting_t *rc = game->raycasting;
    float angle_temp = 0;

    entity->angle = get_entity_angle(game, entity);
    if (entity->angle == -20000)
        return;
    entity->distance = get_entity_distance(game, entity);
    angle_temp = rc->player->direction + (float)rc->fov / 2
        - entity->angle / rc->resolution;
    project_entity(game, entity, angle_temp);
}
