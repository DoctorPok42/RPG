/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** actions
*/

#include "game.h"
#include "menu.h"

void change_to_inventory(game_t *game)
{
    game->menu = MENU_PAUSE_INVENTORY;
}

void change_to_character(game_t *game)
{
    game->menu = MENU_PAUSE_CHARACTER;
}

void change_to_quest(game_t *game)
{
    game->menu = MENU_PAUSE_QUEST;
}

void change_to_option(game_t *game)
{
    game->menu = MENU_PAUSE_SETTINGS;
}
