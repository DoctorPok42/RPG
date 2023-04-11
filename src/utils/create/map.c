/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** game
*/

#include "game.h"

void create_map(game_t *game)
{
    game->map = malloc(sizeof(map_t));
    game->map->rectangle = sfRectangleShape_create();

    game->map->rect = (sfIntRect){.left = 0, .top = 0,
        .width = game->params->window_size.x / 3,
        .height = game->params->window_size.y / 3
    };

    game->map->texture = sfTexture_createFromFile("assets/imgs/map.png", NULL);
    game->map->sprite = sfSprite_create();

    sfSprite_setTexture(game->map->sprite, game->map->texture, sfTrue);
    sfSprite_setTextureRect(game->map->sprite, game->map->rect);
    sfSprite_setPosition(game->map->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(game->map->sprite, (sfVector2f){3, 3});

    game->map->colls_image =
        sfImage_createFromFile("assets/imgs/map_colls.png");
}