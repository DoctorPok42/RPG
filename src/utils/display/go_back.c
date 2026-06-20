/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** go_back
*/

#include "game.h"
#include "display.h"

void display_go_back(game_t *game)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);
    sfVector2f pos = game->go_back->pos;

    if (mpos.x >= pos.x && mpos.x <= pos.x + 102 && mpos.y >= pos.y
        && mpos.y <= pos.y + 105) {
        game->go_back->rect_text.position.x = 110;
        sfSprite_setTextureRect(game->go_back->sprite,
            game->go_back->rect_text);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->go_back->callback(game);
    } else {
        game->go_back->rect_text.position.x = 8;
        sfSprite_setTextureRect(game->go_back->sprite,
            game->go_back->rect_text);
    }
    sfRenderWindow_drawSprite(game->window->window, game->go_back->sprite,
        NULL);
}
