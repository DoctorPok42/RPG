/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** start_menu
*/

#include "game.h"

static void display_buttons(game_t *game, sfVector2i mpos)
{
    for (int i = 0; i < 4; i++) {
        sfVector2f pos = game->start[i]->pos;
        if (mpos.x >= pos.x && mpos.x <= pos.x + 225 && mpos.y >= pos.y &&
            mpos.y <= pos.y + 105) {
            game->start[i]->rect_text.left = 5 + 225;
            sfSprite_setTextureRect(game->start[i]->sprite,
                game->start[i]->rect_text);
                (sfMouse_isButtonPressed(sfMouseLeft)) ?
                game->start[i]->callback(game) : 0;
        } else {
            game->start[i]->rect_text.left = 5;
            sfSprite_setTextureRect(game->start[i]->sprite,
                game->start[i]->rect_text);
        }
        sfRenderWindow_drawSprite(game->window->window, game->start[i]->sprite,
            NULL);
    }
}

void display_start_menu(game_t *game)
{
    if (game->menu != 0)
        return;
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);
    display_buttons(game, mpos);
}
