/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** character
*/

#include "game.h"
#include "display.h"
#include "menu.h"

void display_charracter(game_t *game)
{
    sfVector2u win = game->params->window_size;
    int i = 0;

    if (!menu_tab_character(game))
        return;
    game->perso->pos = (sfVector2f){win.x / 2 - 100, win.y / 2 - 100};
    sfSprite_setPosition(game->perso->sprite, game->perso->pos);
    sfSprite_setScale(game->perso->sprite, (sfVector2f){9, 9});
    sfRenderWindow_drawSprite(game->window->window, game->perso->sprite, NULL);
    sfSprite_setScale(game->perso->sprite, (sfVector2f){4, 4});
    game->perso->pos = game->perso->pos_save;
    for (i = 0; i < 6; i++) {
        sfRenderWindow_drawText(game->window->window,
            game->game_menu->character->name[i], NULL);
        sfRenderWindow_drawText(game->window->window,
            game->game_menu->character->value[i], NULL);
    }
    sfRenderWindow_drawText(game->window->window,
        game->game_menu->title[1], NULL);
}
