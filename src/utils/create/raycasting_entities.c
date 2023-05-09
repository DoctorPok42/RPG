/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** raycasting_entities
*/

#include "game.h"

entity_t *add_entity (char *texture_path, sfVector2f position,
sfIntRect dimensions, int map_id)
{
    entity_t *entity = malloc(sizeof(entity_t));
    if (entity == NULL)
        return NULL;

    entity->map = 0;
    entity->position = position;
    entity->dimensions = dimensions;

    entity->sprite = sfSprite_create();
    if (entity->sprite == NULL)
        return NULL;

    entity->texture = sfTexture_createFromFile(texture_path, 0);
    if (entity->texture == NULL)
        return NULL;

    sfSprite_setTexture(entity->sprite, entity->texture, 0);

    return entity;
}

int create_entities (game_t *game)
{
    game->raycasting->entities = malloc(sizeof(entity_t *) * 5);
    if (game->raycasting->entities == NULL)
        return -1;

    game->raycasting->entities[0] = add_entity("./assets/imgs/elliot.png",
    (sfVector2f) {500, 500}, (sfIntRect) {0, 0, 50, 50}, 0);
    if (game->raycasting->entities[0] == NULL)
        return -1;

    game->raycasting->entities[1] = add_entity("./assets/imgs/elliot.png",
    (sfVector2f) {800, 800}, (sfIntRect) {0, 0, 50, 50}, 0);
    if (game->raycasting->entities[1] == NULL)
        return -1;

    game->raycasting->entities[2] = NULL;

    return 0;
}
