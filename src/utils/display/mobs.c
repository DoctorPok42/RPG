/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include "game.h"

void manage_mobs (game_t *game);

void display_mobs (game_t *game)
{
    if (game->menu < 5 || game->menu > 6)
        return;

    manage_mobs(game);

    for (int i = 0; game->mobs[i] != NULL; i++) {
        if (game->mobs[i]->is_alive == sfFalse)
            continue;
        sfRenderWindow_drawSprite(game->window->window,
        game->mobs[i]->sprite, NULL);
    }
}
