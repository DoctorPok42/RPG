/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** character
*/

#include "game.h"

void display_charracter(game_t *game)
{
    if ((game->menu / 10) % 10 != 6 || (game->menu % 10) != 1)
        return;

    game->perso->pos = (sfVector2f){game->params->window_size.x / 2 - 100,
        game->params->window_size.y / 2 - 100};
    sfSprite_setPosition(game->perso->sprite, game->perso->pos);
    sfSprite_setScale(game->perso->sprite, (sfVector2f){2, 2});
    sfRenderWindow_drawSprite(game->window->window, game->perso->sprite, NULL);
    sfSprite_setScale(game->perso->sprite, (sfVector2f){0.7, 0.7});
    game->perso->pos = game->perso->pos_save;

    for (int i = 0; i < 6; i++) {
        sfRenderWindow_drawText(game->window->window,
            game->game_menu->character->name[i], NULL);
        sfRenderWindow_drawText(game->window->window,
            game->game_menu->character->value[i], NULL);
    }
}
