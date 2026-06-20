/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** index
*/

#include "game.h"
#include "create.h"

void create_game(game_t *game)
{
    create_clients(game);
    create_window(game);
    create_start_menu(game);
    create_map(game);
    create_perso(game);
    create_dialog(game);
    create_options(game);
    create_save_menu(game);
    create_go_back(game);
    create_inventory(game);
    create_overlay(game);
    create_menu(game);
    create_mobs(game);
    create_raycasting(game);
    create_npc(game);
    create_win_loose(game);
}
