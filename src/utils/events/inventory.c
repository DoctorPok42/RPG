/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory
*/

#include "game.h"

static void change_item_by_key(game_t *game)
{
    if (game->window->event.type == sfEvtKeyPressed) {
        if (game->window->event.key.code == sfKeyNum1) {
            game->inventory->item_selected = 0;
        }
        if (game->window->event.key.code == sfKeyNum2) {
            game->inventory->item_selected = 1;
        }
        if (game->window->event.key.code == sfKeyNum3) {
            game->inventory->item_selected = 2;
        }
    }
}

void change_item(game_t *game)
{
    if (game->window->event.type == sfEvtMouseWheelScrolled &&
        sfKeyboard_isKeyPressed(sfKeyLControl) == sfFalse) {
        if (game->window->event.mouseWheelScroll.delta > 0) {
            game->inventory->item_selected--;
        }
        if (game->window->event.mouseWheelScroll.delta < 0) {
            game->inventory->item_selected++;
        }
        if (game->inventory->item_selected > 2) {
            game->inventory->item_selected = 0;
        }
        if (game->inventory->item_selected < 0) {
            game->inventory->item_selected = 2;
        }
    }
    change_item_by_key(game);
}
