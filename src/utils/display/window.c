/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** window
*/

#include "rpg.h"
#include "game.h"

void display_window(game_t *game)
{
    if (game->menu == 0)
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->window->rect[0], NULL);
    else if (game->menu >= 3) {
        sfRenderWindow_drawSprite(game->window->window,
            game->map->sprite, NULL);
    }
}
