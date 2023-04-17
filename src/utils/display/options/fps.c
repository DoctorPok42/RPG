/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** fps
*/

#include "game.h"

int my_getnbr(char const *str);
void relase_button(buttons_t **button, int i, int max);

static int active_button(game_t *game, int i)
{
    game->params->visu->fps->button[i]->state = ACTIVE;
    relase_button(game->params->visu->fps->button, i, 4);
    return my_getnbr(game->params->visu->fps->button[i]->str);
}

static int check_button(game_t *game)
{
    switch (game->params->fps) {
        case 32:
            return 0;
        case 60:
            return 1;
        case 120:
            return 2;
        case 144:
            return 3;
        default:
            return 0;
    }
}

static void display_button(game_t *game, sfVector2i mpos)
{
    buttons_t **button = game->params->visu->fps->button;
    for (int i = 0; i < 4; i++) {
        sfVector2f pos = button[i]->pos;
        if (mpos.x >= pos.x && mpos.x <= pos.x + 150 && mpos.y >= pos.y &&
            mpos.y <= pos.y + 50) {
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 150});
            game->params->fps = (sfMouse_isButtonPressed(sfMouseLeft) ) ?
                active_button(game, i) : game->params->fps;
        } else
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 100});
        if (button[i]->state == ACTIVE)
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 200});
        sfRenderWindow_drawRectangleShape(game->window->window,
            button[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window,
            button[i]->text, NULL);
    }
}

void display_fps(game_t *game)
{
    if (game->menu != 2 && game->menu != 20)
        return;
    game->params->visu->fps->button[check_button(game)]->state = ACTIVE;
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);
    display_button(game, mpos);
}
