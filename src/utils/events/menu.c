/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu
*/

#include "game.h"
#include "events.h"
#include "menu.h"

void event_menu(game_t *game)
{
    if (game->menu < 5)
        exit_start_all(game);
    if (menu_in_overworld(game)) {
        menu_push(game, SCREEN_PAUSE);
        return;
    }
    if (menu_pause_open(game) || menu_in_pause_tab(game))
        menu_pop(game);
}
