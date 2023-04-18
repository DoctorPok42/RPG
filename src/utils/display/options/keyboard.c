/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** keyboard
*/

#include "game.h"

static void change_keaboard(game_t *game, int i)
{
    sfRenderWindow_waitEvent(game->window->window, &game->window->event);
    if (game->window->event.type == sfEvtKeyPressed) {
    }
}

static void display_button(game_t *game, sfVector2i mpos)
{
    buttons_t **button = game->params->visu->keyboard->button;
    for (int i = 0; i < 4; i++) {
        if (mpos.x >= button[i]->pos.x && mpos.x <= button[i]->pos.x + 150 &&
            mpos.y >= button[i]->pos.y && mpos.y <= button[i]->pos.y + 50) {
                sfRectangleShape_setFillColor(button[i]->rect, sfRed);
                sfText_setColor(button[i]->text, sfBlack);
                (sfMouse_isButtonPressed(sfMouseLeft)) ?
                    change_keaboard(game, i) : 0;
        } else {
            sfRectangleShape_setFillColor(button[i]->rect, sfBlack);
            sfText_setColor(button[i]->text, sfWhite);
        }
        sfRenderWindow_drawRectangleShape(game->window->window,
            button[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window, button[i]->text, NULL);
    }
}

void display_keyboard(game_t *game)
{
    if (game->menu != 22 && game->menu % 10 != 2)
        return;
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);
    display_button(game, mpos);
}
