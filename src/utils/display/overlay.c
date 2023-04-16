/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** overlay
*/

#include "game.h"

static void display_strength(game_t *game)
{
    sfRectangleShape_setSize(game->overlay->life->content,
        (sfVector2f){24, (165 * game->perso->combat->strength / 100) * -1});

    sfRectangleShape_setPosition(game->overlay->life->content,
        (sfVector2f){game->params->window_size.x - 52, 91 + 165});

    sfRenderWindow_drawRectangleShape(game->window->window,
        game->overlay->life->content, NULL);
}

static void change_life_color(game_t *game)
{
    if (game->perso->combat->life > 50)
        sfRectangleShape_setFillColor(game->overlay->life->container,
            sfColor_fromRGBA(0, 200, 83, 255));
    else if (game->perso->combat->life > 25)
        sfRectangleShape_setFillColor(game->overlay->life->container,
            sfColor_fromRGBA(255, 255, 0, 255));
    else
        sfRectangleShape_setFillColor(game->overlay->life->container,
            sfColor_fromRGBA(255, 0, 0, 255));
}

void display_overlay(game_t *game)
{
    if (game->menu < 5)
        return;

    sfRenderWindow_drawSprite(game->window->window,
        game->overlay->life->sprite, NULL);
    sfRectangleShape_setSize(game->overlay->life->container,
        (sfVector2f){27, (184 * game->perso->combat->life / 100) * -1});

    sfRectangleShape_setPosition(game->overlay->life->container,
        (sfVector2f){game->params->window_size.x - 110, 73 + 184});

    change_life_color(game);

    sfRenderWindow_drawRectangleShape(game->window->window,
        game->overlay->life->container, NULL);

    display_strength(game);
}
