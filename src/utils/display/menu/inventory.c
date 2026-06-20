/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory
*/

#include "game.h"
#include "display.h"
#include "menu.h"

static void replace_bar(game_t *game, item_t *item, int i)
{
    item->pos =
        (sfVector2f){10, (i * 65 + game->params->window_size.y / 2 - 90)};
    sfRectangleShape_setPosition(item->container,
        (sfVector2f){item->pos.x - 5, item->pos.y - 5});
    sfRectangleShape_setPosition(item->content, item->pos);
}

static void draw_item(game_t *game, int i)
{
    item_t *item = game->inventory->items[i];
    sfVector2u win = game->params->window_size;

    item->pos = (sfVector2f){win.x / 2 + 300, (i * 65 + win.y / 2 - 90)};
    sfRectangleShape_setOutlineColor(item->content,
        sfColor_fromRGBA(96, 125, 139, 255));
    sfRectangleShape_setOutlineColor(item->container,
        sfColor_fromRGBA(144, 164, 174, 255));
    sfRectangleShape_setPosition(item->container,
        (sfVector2f){item->pos.x - 5, item->pos.y - 5});
    sfRectangleShape_setPosition(item->content, item->pos);
    sfRenderWindow_drawRectangleShape(game->window->window,
        item->container, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window, item->content,
        NULL);
    replace_bar(game, item, i);
}

static void display_bar(game_t *game)
{
    int i = 0;

    for (i = 0; i < 3; i++)
        draw_item(game, i);
}

void display_inventory_menu(game_t *game)
{
    sfVector2u win = game->params->window_size;

    if (!menu_tab_inventory(game))
        return;
    game->perso->pos = (sfVector2f){win.x / 2 - 100, win.y / 2 - 100};
    sfSprite_setPosition(game->perso->sprite, game->perso->pos);
    sfSprite_setScale(game->perso->sprite, (sfVector2f){9, 9});
    sfRenderWindow_drawSprite(game->window->window, game->perso->sprite, NULL);
    sfSprite_setScale(game->perso->sprite, (sfVector2f){4, 4});
    display_bar(game);
    game->perso->pos = game->perso->pos_save;
    sfRenderWindow_drawText(game->window->window,
        game->game_menu->title[0], NULL);
}
