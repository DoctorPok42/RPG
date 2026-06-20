/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** create
*/

#ifndef CREATE_H_
    #define CREATE_H_

    #include "game.h"

void create_game(game_t *game);
void create_clients(game_t *game);
void create_window(game_t *game);
void create_start_menu(game_t *game);
void create_map(game_t *game);
void create_perso(game_t *game);
void create_dialog(game_t *game);
void create_options(game_t *game);
void create_save_menu(game_t *game);
void create_go_back(game_t *game);
void create_inventory(game_t *game);
void create_overlay(game_t *game);
void create_menu(game_t *game);
void create_mobs(game_t *game);
void create_npc(game_t *game);
void create_win_loose(game_t *game);
void create_button(buttons_t *button, char *text, int i, game_t *game);
void create_character(game_t *game);
void create_fps(game_t *game);
void create_keyboard(game_t *game);
void create_music(game_t *game);
void create_navbar(game_t *game);
void create_quest(game_t *game);
void create_sidebar(game_t *game);
void create_window_button(game_t *game);
int create_raycasting(game_t *game);
int create_entities(game_t *game);

#endif /* !CREATE_H_ */
