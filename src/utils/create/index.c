/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** index
*/

#include "game.h"

void create_map(game_t *game);
void create_perso(game_t *game);
void create_window(game_t *game);
void create_start_menu(game_t *game);
void create_dialog(game_t *game);
void create_options(game_t *game);
void create_save_menu(game_t *game);
void create_go_back(game_t *game);
void create_inventory(game_t *game);
void create_overlay(game_t *game);
void create_menu(game_t *game);
void create_clients(game_t *game);
void create_mobs (game_t *game);
int create_raycasting (game_t *game);
void create_npc(game_t *game);
void create_win_loose(game_t *game);

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
