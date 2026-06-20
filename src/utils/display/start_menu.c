/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** start_menu
*/

#include "game.h"
#include "display.h"
#include "menu.h"

static void update_button(game_t *game, int i, const sfVector2i *mpos)
{
    sfVector2f pos = game->start[i]->pos;

    if (mpos->x >= pos.x && mpos->x <= pos.x + 225 && mpos->y >= pos.y
        && mpos->y <= pos.y + 105) {
        game->start[i]->rect_text.position.x = 5 + 225;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->start[i]->callback(game);
    } else
        game->start[i]->rect_text.position.x = 5;
    sfSprite_setTextureRect(game->start[i]->sprite,
        game->start[i]->rect_text);
}

static void display_buttons(game_t *game, const sfVector2i *mpos)
{
    int i = 0;

    for (i = 0; i < 4; i++) {
        update_button(game, i, mpos);
        sfRenderWindow_drawSprite(game->window->window,
            game->start[i]->sprite, NULL);
    }
}

void display_start_menu(game_t *game)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);

    if (!menu_is_start(game))
        return;
    display_buttons(game, &mpos);
}
