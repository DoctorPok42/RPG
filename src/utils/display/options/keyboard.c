/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** keyboard
*/

#include "game.h"

static void change_keyboard(game_t *game)
{
    if (game->keys->swith_keys == 1) {
        game->keys->up = sfKeyUp;
        game->keys->down = sfKeyDown;
        game->keys->left = sfKeyLeft;
        game->keys->right = sfKeyRight;
    } else {
        game->keys->up = sfKeyZ;
        game->keys->down = sfKeyS;
        game->keys->left = sfKeyQ;
        game->keys->right = sfKeyD;
    }
    game->keys->swith_keys = (game->keys->swith_keys == 1) ? 0 : 1;
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
                    change_keyboard(game) : 0;
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
    if (game->menu != 22)
        return;
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);
    display_button(game, mpos);
}
