/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** keyboard
*/

#include "game.h"

static void change_keyboard(game_t *game)
{
    if (game->keys->switch_keys == 0) {
        game->keys->up = sfKeyZ;
        game->keys->down = sfKeyS;
        game->keys->left = sfKeyQ;
        game->keys->right = sfKeyD;
    } else {
        game->keys->up = sfKeyUp;
        game->keys->down = sfKeyDown;
        game->keys->left = sfKeyLeft;
        game->keys->right = sfKeyRight;
    }
    game->keys->switch_keys = (game->keys->switch_keys == 1) ? 0 : 1;
    sfSleep((sfTime){500000});
}

static void keep_active(game_t *game)
{
    if (game->keys->switch_keys == 0) {
        sfRectangleShape_setFillColor(game->params->visu->keyboard->button[0]
            ->rect, (sfColor){25, 118, 210, 200});
    } else {
        sfRectangleShape_setFillColor(game->params->visu->keyboard->button[1]
            ->rect, (sfColor){25, 118, 210, 200});
    }
}

static void display_button(game_t *game, sfVector2i mpos)
{
    buttons_t **button = game->params->visu->keyboard->button;
    for (int i = 0; i < 2; i++) {
        if (mpos.x >= button[i]->pos.x && mpos.x <= button[i]->pos.x + 150 &&
            mpos.y >= button[i]->pos.y && mpos.y <= button[i]->pos.y + 50) {
                sfRectangleShape_setFillColor(button[i]->rect,
                    (sfColor){25, 118, 210, 150});
                sfMouse_isButtonPressed(sfMouseLeft) ?
                change_keyboard(game) : 0;
        } else
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 100});
        keep_active(game);
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
