/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** raycasting_entities
*/

#include "game.h"
#include "create.h"

static entity_t *add_entity(char *texture_path, const sfVector2f *position,
    const sfIntRect *dimensions)
{
    entity_t *entity = malloc(sizeof(entity_t));

    if (entity == NULL)
        return NULL;
    entity->map = 0;
    entity->position = *position;
    entity->dimensions = *dimensions;
    entity->texture = sfTexture_createFromFile(texture_path, 0);
    if (entity->texture == NULL)
        return NULL;
    entity->sprite = sfSprite_create(entity->texture);
    if (entity->sprite == NULL)
        return NULL;
    return entity;
}

int create_entities(game_t *game)
{
    sfVector2f p0 = {500, 500};
    sfVector2f p1 = {800, 800};
    sfIntRect dim = {.position = {0, 0}, .size = {50, 50}};

    game->raycasting->entities = malloc(sizeof(entity_t *) * 5);
    if (game->raycasting->entities == NULL)
        return -1;
    game->raycasting->entities[0] = add_entity("./assets/imgs/elliot.png",
        &p0, &dim);
    if (game->raycasting->entities[0] == NULL)
        return -1;
    game->raycasting->entities[1] = add_entity("./assets/imgs/elliot.png",
        &p1, &dim);
    if (game->raycasting->entities[1] == NULL)
        return -1;
    game->raycasting->entities[2] = NULL;
    return 0;
}
