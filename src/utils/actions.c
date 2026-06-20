/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** close
*/

#include "game.h"
#include "display.h"
#include "menu.h"

void go_back(game_t *game)
{
    menu_pop(game);
    if (game->menu > 500)
        menu_pop(game);
    relase_button(game->params->visu->navbar->button, 0, 5);
}

void change_to_settings(game_t *game)
{
    game->params->tmp = 0;
    if (game->menu <= 563)
        game->menu = MENU_SETTINGS;
    else
        menu_set_tab(game, 1);
}

void close_start_all(game_t *game)
{
    menu_push(game, SCREEN_PLAY);
}

void exit_start_all(game_t *game)
{
    sfRenderWindow_close(game->window->window);
}

void change_to_save(game_t *game)
{
    menu_push(game, SCREEN_SAVE);
}
