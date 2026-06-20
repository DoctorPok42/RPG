/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** window
*/

#include "game.h"
#include "display.h"
#include "menu.h"

static int show_map(int menu)
{
    if (menu < 10 || menu % 10 == 6 || menu / 10 % 10 == 6)
        return 1;
    return menu == 42 || menu == -42;
}

void display_window(game_t *game)
{
    if (menu_is_start(game))
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->window->rect[0], NULL);
    else if (game->menu >= 5 && show_map(game->menu))
        sfRenderWindow_drawSprite(game->window->window,
            game->map->sprite, NULL);
}
