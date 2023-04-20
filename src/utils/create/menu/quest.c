/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** quest
*/

#include "game.h"

void create_achievement(game_t *game, quest_t *quest)
{
    quest->font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    quest->achievement = sfText_create();
    sfText_setString(quest->achievement, "0-3");
    sfText_setFont(quest->achievement,quest->font);
    sfText_setCharacterSize(quest->achievement, 30);
    sfText_setColor(quest->achievement, sfWhite);
    sfText_setPosition(quest->achievement,
        (sfVector2f){(game->params->window_size.x / 2) + 425,
        (game->params->window_size.y / 2) - 25 + 8.5});
    quest->nb_achievement = 0;
    quest->nb_achievement_second = 0;
    quest->content = sfRectangleShape_create();
    sfRectangleShape_setSize(quest->content, (sfVector2f){100, 50});
    sfRectangleShape_setPosition(quest->content,
        (sfVector2f){(game->params->window_size.x / 2) + 410,
        (game->params->window_size.y / 2) - 25});
    sfRectangleShape_setFillColor(quest->content, sfTransparent);
    sfRectangleShape_setOutlineColor(quest->content,
        sfColor_fromRGBA(46, 29, 26, 255));
    sfRectangleShape_setOutlineThickness(quest->content, 5);
}

void create_bar(quest_t *quest, sfVector2u size)
{
    quest->bar = sfRectangleShape_create();
    sfRectangleShape_setSize(quest->bar,
        (sfVector2f){0, 25});
    sfRectangleShape_setPosition(quest->bar,
        (sfVector2f){(size.x / 2.08) - 200, (size.y / 2 - 25 + 5.5)});
    sfRectangleShape_setFillColor(quest->bar, (sfColor){170, 0, 255, 100});
    quest->pos = sfRectangleShape_getPosition(quest->bar);
}

void create_quest(game_t *game)
{
    game->game_menu->quest = malloc(sizeof(quest_t));
    quest_t *quest = game->game_menu->quest;

    sfVector2u size = game->params->window_size;
    quest->container = sfRectangleShape_create();
    sfRectangleShape_setSize(quest->container, (sfVector2f){600, 50});
    sfRectangleShape_setPosition(quest->container,
        (sfVector2f){(size.x / 2.1) - 200, (size.y / 2) - 25});
    sfRectangleShape_setFillColor(quest->container,
        (sfColor){62, 39, 35, 255});
    sfRectangleShape_setOutlineColor(quest->container,
        (sfColor){46, 29, 26, 255});
    sfRectangleShape_setOutlineThickness(quest->container, 5);
    quest->pos = sfRectangleShape_getPosition(quest->container);

    quest->size = sfRectangleShape_getSize(quest->container);

    create_bar(quest, size);
    create_achievement(game, quest);
}
