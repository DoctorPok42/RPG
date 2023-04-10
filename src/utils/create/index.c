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

void create_game(game_t *game)
{
    create_window(game);
    create_start_menu(game);
    create_map(game);
    create_perso(game);
    create_dialog(game);
}
