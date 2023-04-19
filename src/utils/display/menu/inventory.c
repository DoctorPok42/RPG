/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory
*/

#include "game.h"

void display_perso(game_t *game);

static void replace_bar(game_t *game, item_t *item, int i)
{
    item->pos =
        (sfVector2f){10, (i * 65 + game->params->window_size.y / 2 - 90)};
    sfRectangleShape_setPosition(item->container,
        (sfVector2f){item->pos.x - 5, item->pos.y - 5});
    sfRectangleShape_setPosition(item->content, item->pos);
}

static void display_bar(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        game->inventory->items[i]->pos =
            (sfVector2f){game->params->window_size.x / 2 + 300,
            (i * 65 + game->params->window_size.y / 2 - 90)};
        sfRectangleShape *container = game->inventory->items[i]->container;
        sfRectangleShape *content = game->inventory->items[i]->content;
        sfRectangleShape_setOutlineColor(content,
                sfColor_fromRGBA(96, 125, 139, 255));
        sfRectangleShape_setOutlineColor(container,
                sfColor_fromRGBA(144, 164, 174, 255));
        sfRectangleShape_setPosition(game->inventory->items[i]->container,
            (sfVector2f){game->inventory->items[i]->pos.x - 5,
            game->inventory->items[i]->pos.y - 5});
        sfRectangleShape_setPosition(game->inventory->items[i]->content,
            game->inventory->items[i]->pos);
        sfRenderWindow_drawRectangleShape(game->window->window,
            container, NULL);
        sfRenderWindow_drawRectangleShape(game->window->window, content, NULL);
        replace_bar(game, game->inventory->items[i], i);
    }
}

void display_inventory_menu(game_t *game)
{
    if ((game->menu / 10) % 10 != 6 || (game->menu % 10) != 0)
        return;

    game->perso->pos = (sfVector2f){game->params->window_size.x / 2 - 100,
        game->params->window_size.y / 2 - 100};
    sfSprite_setPosition(game->perso->sprite, game->perso->pos);
    sfSprite_setScale(game->perso->sprite, (sfVector2f){2, 2});
    sfRenderWindow_drawSprite(game->window->window, game->perso->sprite, NULL);
    sfSprite_setScale(game->perso->sprite, (sfVector2f){0.7, 0.7});
    display_bar(game);
    game->perso->pos = game->perso->pos_save;

    sfRenderWindow_drawText(game->window->window,
        game->game_menu->title[0], NULL);
}
