/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** zoom
*/

#include "game.h"

void zoom(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLControl) &&
        game->window->event.type == sfEvtMouseWheelScrolled) {
        sfVector2f pos = sfView_getSize(game->window->view);
        if (game->window->event.mouseWheelScroll.delta > 0 &&
            pos.x < game->params->window_size.x / 1.08) {
            sfView_zoom(game->window->view, 1.1);
        }
        if (game->window->event.mouseWheelScroll.delta < 0) {
            sfView_zoom(game->window->view, 0.9);
        }
    }
}
