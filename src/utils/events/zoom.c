/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** zoom
*/

#include "game.h"
#include "events.h"
#include "input.h"

void zoom(game_t *game)
{
    sfVector2f pos = {0};

    if (!is_key_held(game, sfKeyLControl)
        || game->window->event.type != sfEvtMouseWheelScrolled)
        return;
    pos = sfView_getSize(game->window->view);
    if (game->window->event.mouseWheelScroll.delta > 0
        && pos.x < game->params->window_size.x / 1.08)
        sfView_zoom(game->window->view, 1.1);
    if (game->window->event.mouseWheelScroll.delta < 0)
        sfView_zoom(game->window->view, 0.9);
}
