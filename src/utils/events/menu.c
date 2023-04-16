/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu
*/

#include "game.h"

void event_menu(game_t *game)
{
    if (game->menu < 10) {
        game->menu = (game->menu * 10) + 6;
        return;
    } else if (game->menu % 10 == 6 || (game->menu / 10) % 10 != 6)
        game->menu /= 10;
}
