/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory
*/

#include "game.h"

void display_inventory(game_t *game)
{
    if (game->menu < 5 || game->menu > 6)
        return;
    for (int i = 0; i < 3; i++) {
        sfRectangleShape *container = game->inventory->items[i]->container;
        sfRectangleShape *content = game->inventory->items[i]->content;
        if (game->inventory->item_selected == i) {
            sfRectangleShape_setOutlineColor(content,
                sfColor_fromRGBA(1, 87, 155, 255));
            sfRectangleShape_setOutlineColor(container,
                sfColor_fromRGBA(2, 119, 189, 255));
        } else {
            sfRectangleShape_setOutlineColor(content,
                sfColor_fromRGBA(96, 125, 139, 255));
            sfRectangleShape_setOutlineColor(container,
                sfColor_fromRGBA(144, 164, 174, 255));
        }
        sfRenderWindow_drawRectangleShape(game->window->window,
            container, NULL);
        sfRenderWindow_drawRectangleShape(game->window->window, content, NULL);
    }
}
