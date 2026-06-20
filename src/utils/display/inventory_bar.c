/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory
*/

#include "game.h"
#include "display.h"
#include "menu.h"

static void set_item_color(sfRectangleShape *content, sfRectangleShape *cont,
    int selected)
{
    if (selected) {
        sfRectangleShape_setOutlineColor(content,
            sfColor_fromRGBA(1, 87, 155, 255));
        sfRectangleShape_setOutlineColor(cont,
            sfColor_fromRGBA(2, 119, 189, 255));
    } else {
        sfRectangleShape_setOutlineColor(content,
            sfColor_fromRGBA(96, 125, 139, 255));
        sfRectangleShape_setOutlineColor(cont,
            sfColor_fromRGBA(144, 164, 174, 255));
    }
}

void display_inventory(game_t *game)
{
    sfRectangleShape *container = NULL;
    sfRectangleShape *content = NULL;
    int i = 0;

    if (!menu_show_hud(game))
        return;
    for (i = 0; i < 3; i++) {
        container = game->inventory->items[i]->container;
        content = game->inventory->items[i]->content;
        set_item_color(content, container, game->inventory->item_selected == i);
        sfRenderWindow_drawRectangleShape(game->window->window,
            container, NULL);
        sfRenderWindow_drawRectangleShape(game->window->window, content, NULL);
    }
}
