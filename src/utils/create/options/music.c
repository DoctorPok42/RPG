/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** music
*/

#include "game.h"

void create_music(game_t *game)
{
    game->params->visu->music = malloc(sizeof(music_t));
    music_t *music = game->params->visu->music;
    sfVector2u size = game->params->window_size;
    music->container = sfRectangleShape_create();
    sfRectangleShape_setSize(music->container, (sfVector2f){500, 50});
    sfRectangleShape_setPosition(music->container,
        (sfVector2f){(size.x / 4.5) - 250, (size.y / 2) - 250});
    sfRectangleShape_setFillColor(music->container,
        (sfColor){62, 39, 35, 255});
    sfRectangleShape_setOutlineColor(music->container,
        (sfColor){46, 29, 26, 255});
    sfRectangleShape_setOutlineThickness(music->container, 5);
    music->pos = sfRectangleShape_getPosition(music->container);
    music->bar = sfRectangleShape_create();
    sfRectangleShape_setSize(music->bar,
        (sfVector2f){(game->params->volume * 4.83), 35});
    sfRectangleShape_setPosition(music->bar,
        (sfVector2f){(size.x / 4.4) - 250, (size.y / 2 - 250) + 8.5});
    sfRectangleShape_setFillColor(music->bar, (sfColor){106, 27, 154, 100});
    music->pos = sfRectangleShape_getPosition(music->bar);
}
