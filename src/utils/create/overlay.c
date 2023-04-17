/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** overlay
*/

#include "game.h"

void create_strength(game_t *game)
{
    game->overlay->life->content = sfRectangleShape_create();
    sfRectangleShape_setSize(game->overlay->life->content,
        (sfVector2f){23, 165});
    sfRectangleShape_setFillColor(game->overlay->life->content,
        sfColor_fromRGBA(0, 184, 212, 255));
    sfRectangleShape_setPosition(game->overlay->life->content,
        (sfVector2f){game->params->window_size.x - 52, 91});
}

void create_overlay(game_t *game)
{
    game->overlay = malloc(sizeof(overlay_t));
    game->overlay->life = malloc(sizeof(life_t));
    game->overlay->life->container = sfRectangleShape_create();

    sfRectangleShape_setSize(game->overlay->life->container,
        (sfVector2f){29, 184});
    sfRectangleShape_setFillColor(game->overlay->life->container,
        sfColor_fromRGBA(0, 200, 83, 255));
    sfRectangleShape_setPosition(game->overlay->life->container,
        (sfVector2f){game->params->window_size.x - 110, 73});

    game->overlay->life->texture =
        sfTexture_createFromFile("assets/imgs/life.png", NULL);
    game->overlay->life->sprite = sfSprite_create();
    sfSprite_setTexture(game->overlay->life->sprite,
        game->overlay->life->texture, sfTrue);
    sfSprite_setPosition(game->overlay->life->sprite,
        (sfVector2f){game->params->window_size.x - 120, 30});

    create_strength(game);
}
