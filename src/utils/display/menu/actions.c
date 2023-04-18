/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** actions
*/

#include "game.h"

void change_to_inventory(game_t *game)
{
    game->menu = 560;
}

void change_to_character(game_t *game)
{
    game->menu = 561;
}
