/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** actions
*/

#include "game.h"

void change_to_inventory(game_t *game)
{
    if (game->menu / 10 == 6 && game->menu == 56)
        return;
    else
        game->menu *= 10;
}
