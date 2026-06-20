/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** end
*/

#include "game.h"
#include "display.h"
#include "menu.h"

void display_end(game_t *game)
{
    if (menu_won(game)) {
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->win->container, NULL);
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->win->content, NULL);
        sfRenderWindow_drawText(game->window->window, game->win->text, NULL);
    }
    if (menu_lost(game)) {
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->loose->container, NULL);
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->loose->content, NULL);
        sfRenderWindow_drawText(game->window->window, game->loose->text, NULL);
    }
}
