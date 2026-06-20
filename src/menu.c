/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu
*/

#include "game.h"
#include "menu.h"

void menu_pop(game_t *game)
{
    game->menu /= 10;
}

void menu_push(game_t *game, int screen)
{
    game->menu = game->menu * 10 + screen;
}

void menu_set_tab(game_t *game, int tab)
{
    game->menu = game->menu / 10 * 10 + tab;
}

bool menu_is_start(game_t *game)
{
    return game->menu == 0;
}

bool menu_is_dialog(game_t *game)
{
    return game->menu == 4;
}

bool menu_is_save(game_t *game)
{
    return game->menu == 3;
}

bool menu_in_overworld(game_t *game)
{
    return game->menu >= 5 && game->menu < 10;
}

bool menu_show_hud(game_t *game)
{
    return game->menu >= 5 && game->menu <= 6;
}

bool menu_won(game_t *game)
{
    return game->is_finished == 1 && game->menu == 42;
}

bool menu_lost(game_t *game)
{
    return game->is_finished == 1 && game->menu == -42;
}

bool menu_pause_open(game_t *game)
{
    return game->menu % 10 == 6;
}

bool menu_pause_active(game_t *game)
{
    return (game->menu % 10 == 6 || (game->menu / 10) % 10 == 6)
        && game->menu < 563;
}

bool menu_in_pause_tab(game_t *game)
{
    return (game->menu / 10) % 10 == 6;
}

bool menu_tab_inventory(game_t *game)
{
    return (game->menu / 10) % 10 == 6 && game->menu % 10 == 0;
}

bool menu_tab_character(game_t *game)
{
    return (game->menu / 10) % 10 == 6 && game->menu % 10 == 1;
}

bool menu_tab_quest(game_t *game)
{
    return (game->menu / 10) % 10 == 6 && game->menu % 10 == 2;
}

bool menu_in_settings(game_t *game)
{
    return game->menu == 2 || game->menu / 10 == 2
        || (game->menu / 10) % 10 == 3;
}

bool menu_settings_open(game_t *game)
{
    return game->menu == 2 || game->menu / 10 == 2 || game->menu % 10 == 2;
}

bool menu_tab_fps(game_t *game)
{
    return game->menu == 2 || game->menu == 25 || game->menu % 10 == 0;
}

bool menu_tab_music(game_t *game)
{
    return game->menu == 21 || game->menu % 10 == 1;
}

bool menu_tab_keyboard(game_t *game)
{
    return game->menu == 22 || game->menu % 10 == 2;
}

bool menu_tab_window(game_t *game)
{
    return game->menu == 24 || game->menu % 10 == 4;
}
