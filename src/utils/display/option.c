/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** option
*/

#include "game.h"

void display_music(game_t *game);
void display_fps(game_t *game);
void display_keyboard(game_t *game);
void display_window_buttons(game_t *game);

void relase_button(buttons_t **button, int i, int max)
{
    for (int j = 0; j < max; j++) {
        if (j != i)
            button[j]->state = RELEASE;
    }
}

static void active_button(game_t *game, int i)
{
    game->menu = game->params->visu->navbar->button[i]->state = ACTIVE;
    relase_button(game->params->visu->navbar->button, i, 5);
    game->menu = game->menu * 10 + i;
}

static void display_buttons(game_t *game, sfVector2i mpos)
{
    buttons_t **button = game->params->visu->navbar->button;
    for (int i = 0; i < 5; i++) {
        sfVector2f pos = button[i]->pos;
        if (mpos.x >= pos.x && mpos.x <= pos.x + 140 && mpos.y >= pos.y &&
            mpos.y <= pos.y + 50) {
            sfRectangleShape_setFillColor(button[i]->rect,
                (sfColor){25, 118, 210, 150});
                (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) ?
                    active_button(game, i) : 0;
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

void display_options(game_t *game)
{
    if (game->menu != 2 && game->menu / 10 != 2)
        return;
    if (game->menu == 2) {
        game->params->visu->navbar->button[0]->state = ACTIVE;
        game->menu = 20;
    }
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->params->visu->navbar->container, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->params->visu->navbar->content, NULL);
    display_buttons(game, mpos);
    display_music(game);
    display_fps(game);
    display_keyboard(game);
    display_window_buttons(game);
}
