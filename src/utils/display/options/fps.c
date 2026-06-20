/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** fps
*/

#include "game.h"
#include "display.h"
#include "my_str.h"
#include "menu.h"

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

static void draw_fps_button(game_t *game, int i, const sfVector2i *mpos)
{
    buttons_t **button = game->params->visu->fps->button;
    sfVector2f pos = button[i]->pos;

    if (mpos->x >= pos.x && mpos->x <= pos.x + 150 && mpos->y >= pos.y
        && mpos->y <= pos.y + 50) {
        sfRectangleShape_setFillColor(button[i]->rect,
            (sfColor){25, 118, 210, 150});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            game->params->fps = active_button(game, i);
    } else
        sfRectangleShape_setFillColor(button[i]->rect,
            (sfColor){25, 118, 210, 100});
    if (button[i]->state == ACTIVE)
        sfRectangleShape_setFillColor(button[i]->rect,
            (sfColor){25, 118, 210, 200});
}

static void display_button(game_t *game, const sfVector2i *mpos)
{
    buttons_t **button = game->params->visu->fps->button;
    int i = 0;

    for (i = 0; i < 4; i++) {
        draw_fps_button(game, i, mpos);
        sfRenderWindow_drawRectangleShape(game->window->window,
            button[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window, button[i]->text, NULL);
    }
}

void display_fps(game_t *game)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);

    if (!menu_tab_fps(game))
        return;
    game->params->visu->fps->button[check_button(game)]->state = ACTIVE;
    display_button(game, &mpos);
}
