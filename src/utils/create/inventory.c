/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory
*/

#include "game.h"

static void create_case(item_t *item, int i, game_t *game)
{
    item->container = sfRectangleShape_create();
    item->content = sfRectangleShape_create();
    sfRectangleShape_setSize(item->container, (sfVector2f){60, 60});
    sfRectangleShape_setOutlineColor(item->container,
        sfColor_fromRGBA(144, 164, 174, 255));
    sfRectangleShape_setOutlineThickness(item->container, 3);
    sfRectangleShape_setFillColor(item->container, sfTransparent);

    sfRectangleShape_setSize(item->content, (sfVector2f){50, 50});
    sfRectangleShape_setFillColor(item->content, sfTransparent);
    sfRectangleShape_setOutlineColor(item->content,
        sfColor_fromRGBA(96, 125, 139, 255));
    sfRectangleShape_setOutlineThickness(item->content, 5);

    item->pos =
        (sfVector2f){10, (i * 65 + game->params->window_size.y / 2 - 90)};
    sfRectangleShape_setPosition(item->container,
        (sfVector2f){item->pos.x - 5, item->pos.y - 5});
    sfRectangleShape_setPosition(item->content,
        item->pos);
}

void create_inventory(game_t *game)
{
    game->inventory = malloc(sizeof(inventory_t));
    game->inventory->items = malloc(sizeof(item_t *) * 3);
    game->inventory->item_selected = 0;

    for (int i = 0; i < 3; i++) {
        game->inventory->items[i] = malloc(sizeof(item_t));
        create_case(game->inventory->items[i], i, game);
    }
}
