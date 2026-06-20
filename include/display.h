/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** display
*/

#ifndef DISPLAY_H_
    #define DISPLAY_H_

    #include "game.h"

void display_all(game_t *game);
void display_window(game_t *game);
void display_start_menu(game_t *game);
void change_to_game(game_t *game);
void display_perso(game_t *game);
void change_map(game_t *game);
void display_dialog(game_t *game);
void display_options(game_t *game);
void display_save(game_t *game);
void display_inventory(game_t *game);
void display_inventory_menu(game_t *game);
void display_overlay(game_t *game);
void display_menu(game_t *game);
void display_iso_map(game_t *game);
void display_clients(game_t *game);
void display_mobs(game_t *game);
void display_npc(game_t *game);
void display_end(game_t *game);
void display_fps(game_t *game);
void display_music(game_t *game);
void display_keyboard(game_t *game);
void display_window_buttons(game_t *game);
void display_charracter(game_t *game);
void display_quest(game_t *game);
void display_go_back(game_t *game);
int diplay_text(game_t *game, char *str);
void relase_button(buttons_t **button, int i, int max);

#endif /* !DISPLAY_H_ */
