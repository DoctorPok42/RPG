/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** window
*/

#include "game.h"

int my_strcmp(char const *s1, char const *s2);

static void relase_button(game_t *game, int i, int max, char *str)
{
    for (int j = 0; j < max; j++) {
        if (j == i)
            continue;
        if (my_strcmp(str, "size") == 0)
            game->params->visu->windows->size[j]->state = RELEASE;
        else
            game->params->visu->windows->resolution[j]->state = RELEASE;
    }
}

static void active_size_button(game_t *game, int i, char *str)
{
    if (my_strcmp(str, "size") == 0) {
        if (game->params->visu->windows->size[i]->state == ACTIVE)
            return;
        game->params->visu->windows->size[i]->callback(game);
        game->params->visu->windows->size[i]->state = ACTIVE;
        relase_button(game, i, 2, str);
    } else {
        if (game->params->visu->windows->resolution[i]->state == ACTIVE)
            return;
        game->params->visu->windows->resolution[i]->callback(game);
        game->params->visu->windows->resolution[i]->state = ACTIVE;
        relase_button(game, i, 3, str);
    }
}

static void display_resolution_buttons(game_t *game, sfVector2i mpos)
{
    buttons_t **button = game->params->visu->windows->resolution;
    for (int i = 0; i < 3; i++) {
        sfVector2f pos = game->params->visu->windows->resolution[i]->pos;
        if (mpos.x >= pos.x && mpos.x <= pos.x + 170 &&
            mpos.y >= pos.y && mpos.y <= pos.y + 50) {
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 150});
            (sfMouse_isButtonPressed(sfMouseLeft)) ?
                active_size_button(game, i, "resolution") : 0;
        } else
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 100});
        if (button[i]->state == ACTIVE)
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 200});
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->params->visu->windows->resolution[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window,
            game->params->visu->windows->resolution[i]->text, NULL);
    }
}

static void display_size_buttons(game_t *game, sfVector2i mpos)
{
    buttons_t **button = game->params->visu->windows->size;
    for (int i = 0; i < 2; i++) {
        sfVector2f pos = game->params->visu->windows->size[i]->pos;
        if (mpos.x >= pos.x && mpos.x <= pos.x + 170 &&
            mpos.y >= pos.y && mpos.y <= pos.y + 50) {
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 150});
            (sfMouse_isButtonPressed(sfMouseLeft)) ?
                active_size_button(game, i, "size") : 0;
        } else
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 100});
        if (button[i]->state == ACTIVE)
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 200});
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->params->visu->windows->size[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window,
            game->params->visu->windows->size[i]->text, NULL);
    }
}

void display_window_buttons(game_t *game)
{
    if (game->menu != 24 && game->menu % 10 != 4)
        return;
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);
    if (game->params->is_fullscreen == true) {
        game->params->visu->windows->size[0]->state = ACTIVE;
    } else {
        game->params->visu->windows->size[1]->state = ACTIVE;
    }

    if (game->params->mode.width == 1920 && game->params->mode.height == 1080) {
        game->params->visu->windows->resolution[0]->state = ACTIVE;
    } else if (game->params->mode.width == 1280 &&
        game->params->mode.height == 720) {
        game->params->visu->windows->resolution[1]->state = ACTIVE;
    } else {
        game->params->visu->windows->resolution[2]->state = ACTIVE;
    }

    display_size_buttons(game, mpos);
    display_resolution_buttons(game, mpos);
}
