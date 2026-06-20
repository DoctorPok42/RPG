/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** raycasting
*/

#include <math.h>

#include "game.h"
#include "raycasting_functions.h"
#include "input.h"

static void draw_entity(game_t *game, entity_t *entity)
{
    raycasting_t *rc = game->raycasting;
    sfVector2f origin = {(float)960 / 2, (float)300};
    sfVector2f pos = {0};
    sfVector2f scale = {0};

    calculate_entity_form(game, entity);
    pos = (sfVector2f){entity->angle * entity->depth,
        ((game->params->mode.size.y - entity->form_height) / 2)
        + rc->player->pitch};
    scale = (sfVector2f){entity->depth * rc->resolution
        / ((float)entity->distance / 100) / 40, entity->form_height / 33 / 18};
    sfSprite_setPosition(entity->sprite, pos);
    sfSprite_setOrigin(entity->sprite, origin);
    sfSprite_setScale(entity->sprite, scale);
    sfRenderWindow_drawSprite(game->window->window, entity->sprite, NULL);
}

static void display_wall(game_t *game, int i)
{
    raycasting_t *rc = game->raycasting;
    int sprite_id = rc->rays[i]->sprite - 1;

    if (sprite_id < 0)
        return;
    sfRectangleShape_setTexture(rc->wall_shape, rc->textures[sprite_id], 0);
    sfRectangleShape_setPosition(rc->wall_shape, rc->rays[i]->position);
    sfRectangleShape_setTextureRect(rc->wall_shape, rc->rays[i]->texture_rect);
    sfRectangleShape_setFillColor(rc->wall_shape, rc->rays[i]->color);
    sfRectangleShape_setSize(rc->wall_shape, rc->rays[i]->size);
    sfRenderWindow_drawRectangleShape(game->window->window, rc->wall_shape,
        NULL);
}

static bool entity_visible(raycasting_t *rc, int i, int x, float dist)
{
    if (rc->rays[i]->distance <= dist)
        return false;
    if (rc->rays[i + 1]->distance >= dist && rc->rays[i + 2] != NULL)
        return false;
    return rc->entities[x]->map == rc->selected_map;
}

static void display_scene(game_t *game, int i)
{
    raycasting_t *rc = game->raycasting;
    float dist = 0;
    int x = 0;

    display_wall(game, i);
    for (x = 0; rc->entities[x] != NULL; x++) {
        dist = sqrt(pow(rc->entities[x]->position.x - rc->player->position.x, 2)
            + pow(rc->entities[x]->position.y - rc->player->position.y, 2));
        if (entity_visible(rc, i, x, dist))
            draw_entity(game, rc->entities[x]);
    }
}

int raycasting(game_t *game)
{
    int i = 0;

    while (sfRenderWindow_pollEvent(game->window->window,
            &game->window->event)) {
        input_handle_event(game);
        if (game->window->event.type == sfEvtClosed)
            exit_start_all(game);
    }
    sfRenderWindow_clear(game->window->window, sfBlack);
    move_raycasting_player(game);
    for (i = 0; i < game->raycasting->nb_rays; i++)
        get_wall(game, i);
    sort_walls_by_distance(game);
    for (i = 0; game->raycasting->rays[i + 1] != NULL; i++)
        display_scene(game, i);
    sfRenderWindow_display(game->window->window);
    return 0;
}
