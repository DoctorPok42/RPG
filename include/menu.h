/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu
*/

/*
** game->menu is a stack of screens encoded in base 10: menu = menu * 10 + N
** pushes screen N, menu /= 10 pops. These helpers name the states and the
** predicates/transitions that were previously raw decimal arithmetic; the
** computations are kept identical to the original behaviour.
*/

#ifndef MENU_H_
    #define MENU_H_

    #include "game.h"

    #define MENU_START 0
    #define MENU_SETTINGS 20
    #define MENU_GAME 5
    #define MENU_WIN 42
    #define MENU_LOSE (-42)
    #define SCREEN_SAVE 3
    #define SCREEN_PLAY 4
    #define SCREEN_PAUSE 6
    #define MENU_PAUSE_INVENTORY 560
    #define MENU_PAUSE_CHARACTER 561
    #define MENU_PAUSE_QUEST 562
    #define MENU_PAUSE_SETTINGS 5630

void menu_pop(game_t *game);
void menu_push(game_t *game, int screen);
void menu_set_tab(game_t *game, int tab);

bool menu_is_start(game_t *game);
bool menu_is_dialog(game_t *game);
bool menu_is_save(game_t *game);
bool menu_in_overworld(game_t *game);
bool menu_show_hud(game_t *game);
bool menu_won(game_t *game);
bool menu_lost(game_t *game);

bool menu_pause_open(game_t *game);
bool menu_pause_active(game_t *game);
bool menu_in_pause_tab(game_t *game);
bool menu_tab_inventory(game_t *game);
bool menu_tab_character(game_t *game);
bool menu_tab_quest(game_t *game);

bool menu_in_settings(game_t *game);
bool menu_settings_open(game_t *game);
bool menu_tab_fps(game_t *game);
bool menu_tab_music(game_t *game);
bool menu_tab_keyboard(game_t *game);
bool menu_tab_window(game_t *game);

#endif /* !MENU_H_ */
