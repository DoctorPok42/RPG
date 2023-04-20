/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** raycasting
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>

#include "game.h"

void move_raycasting_player (game_t *game);
void get_wall (game_t *game, float i);
void sort_walls_by_distance (game_t *game);
void calculate_entity_form (game_t *game, entity_t *entity);

void draw_entity (game_t *game, entity_t *entity)
{
    calculate_entity_form(game, entity);

    sfSprite_setPosition(entity->sprite, (sfVector2f) {entity->angle * entity->
    depth, ((game->params->mode.height - entity->form_height) / 2) + game->
    raycasting->player->pitch});

    sfSprite_setOrigin(entity->sprite, (sfVector2f) {(float) 960 / 2,
    (float) 300});

    sfSprite_setScale(entity->sprite, (sfVector2f) {entity->depth *
    game->raycasting->resolution / ((float) entity->distance / 100) / 40,
    entity->form_height / 33 / 18});

    sfRenderWindow_drawSprite(game->window->window, entity->sprite, NULL);
}

void display_wall (game_t *game, int i)
{
    int sprite_id = game->raycasting->rays[i]->sprite - 1;

    sfRectangleShape_setTexture(game->raycasting->wall_shape,
    game->raycasting->textures[sprite_id], 0);

    sfRectangleShape_setPosition(game->raycasting->wall_shape,
    game->raycasting->rays[i]->position);

    sfRectangleShape_setTextureRect(game->raycasting->wall_shape,
    game->raycasting->rays[i]->texture_rect);

    sfRectangleShape_setFillColor(game->raycasting->wall_shape,
    game->raycasting->rays[i]->color);

    sfRectangleShape_setSize(game->raycasting->wall_shape,
    game->raycasting->rays[i]->size);

    sfRenderWindow_drawRectangleShape(game->window->window,
    game->raycasting->wall_shape, NULL);
}

void display_scene (game_t *game, int i)
{
    display_wall(game, i);
    for (int x = 0; game->raycasting->entities[x] != NULL; x++) {
        float distance_to_player =
        sqrt(pow(game->raycasting->entities[x]->position.x -
        game->raycasting->player->position.x, 2)
        + pow(game->raycasting->entities[x]->position.y -
        game->raycasting->player->position.y, 2));

        if (game->raycasting->rays[i]->distance > distance_to_player
        && (game->raycasting->rays[i + 1]->distance < distance_to_player ||
        game->raycasting->rays[i + 2] == NULL)
        && game->raycasting->entities[x]->map == game->raycasting->selected_map)
            draw_entity(game, game->raycasting->entities[x]);
    }
}

int raycasting (game_t *game)
{
    sfRenderWindow_clear(game->window->window, sfBlack);

    float diff = sqrt(pow(game->raycasting->player->position.x - 100, 2) +
    pow(game->raycasting->player->position.y - 100, 2));

    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        game->is_raycasting = false;
        game->raycasting->player->position = (sfVector2f) {500, 500};
    }
    move_raycasting_player(game);
    for (int i = 0; i < game->raycasting->nb_rays; i++)
        get_wall(game, i);

    sort_walls_by_distance(game);

    for (int i = 0; game->raycasting->rays[i + 1] != NULL; i++)
        display_scene(game, i);

    sfRenderWindow_display(game->window->window);
    return 0;
}
