/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** keyboard
*/

#include "game.h"
#include "display.h"
#include "menu.h"

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
    game->keys->switch_keys = game->keys->switch_keys == 1 ? 0 : 1;
    sfSleep((sfTime){500000});
}

static void keep_active(game_t *game)
{
    buttons_t **button = game->params->visu->keyboard->button;

    if (game->keys->switch_keys == 0)
        sfRectangleShape_setFillColor(button[0]->rect,
            (sfColor){25, 118, 210, 200});
    else
        sfRectangleShape_setFillColor(button[1]->rect,
            (sfColor){25, 118, 210, 200});
}

static void draw_key_button(game_t *game, int i, const sfVector2i *mpos)
{
    buttons_t **button = game->params->visu->keyboard->button;

    if (mpos->x >= button[i]->pos.x && mpos->x <= button[i]->pos.x + 150
        && mpos->y >= button[i]->pos.y && mpos->y <= button[i]->pos.y + 50) {
        sfRectangleShape_setFillColor(button[i]->rect,
            (sfColor){25, 118, 210, 150});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            change_keyboard(game);
    } else
        sfRectangleShape_setFillColor(button[i]->rect,
            (sfColor){25, 118, 210, 100});
    keep_active(game);
}

static void display_button(game_t *game, const sfVector2i *mpos)
{
    buttons_t **button = game->params->visu->keyboard->button;
    int i = 0;

    for (i = 0; i < 2; i++) {
        draw_key_button(game, i, mpos);
        sfRenderWindow_drawRectangleShape(game->window->window,
            button[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window, button[i]->text, NULL);
    }
}

void display_keyboard(game_t *game)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);

    if (!menu_tab_keyboard(game))
        return;
    display_button(game, &mpos);
}
