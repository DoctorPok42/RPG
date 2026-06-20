/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** window
*/

#include "game.h"
#include "display.h"
#include "my_str.h"
#include "menu.h"

static void unselect_others(game_t *game, int i, int max, char *str)
{
    int j = 0;

    for (j = 0; j < max; j++) {
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
    windows_t *w = game->params->visu->windows;

    if (my_strcmp(str, "size") == 0 && w->size[i]->state != ACTIVE) {
        w->size[i]->callback(game);
        w->size[i]->state = ACTIVE;
        unselect_others(game, i, 2, str);
    }
    if (my_strcmp(str, "size") != 0 && w->resolution[i]->state != ACTIVE) {
        w->resolution[i]->callback(game);
        w->resolution[i]->state = ACTIVE;
        unselect_others(game, i, 3, str);
    }
}

static void draw_opt_button(game_t *game, int i, const sfVector2i *mpos,
    char *kind)
{
    windows_t *w = game->params->visu->windows;
    buttons_t *button = my_strcmp(kind, "size") == 0 ? w->size[i]
        : w->resolution[i];
    sfVector2f pos = button->pos;

    if (mpos->x >= pos.x && mpos->x <= pos.x + 170 && mpos->y >= pos.y
        && mpos->y <= pos.y + 50) {
        sfRectangleShape_setFillColor(button->rect,
            (sfColor){25, 118, 210, 150});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            active_size_button(game, i, kind);
    } else
        sfRectangleShape_setFillColor(button->rect,
            (sfColor){25, 118, 210, 100});
    if (button->state == ACTIVE)
        sfRectangleShape_setFillColor(button->rect,
            (sfColor){25, 118, 210, 200});
}

static void display_resolution_buttons(game_t *game, const sfVector2i *mpos)
{
    buttons_t **button = game->params->visu->windows->resolution;
    int i = 0;

    for (i = 0; i < 3; i++) {
        draw_opt_button(game, i, mpos, "resolution");
        sfRenderWindow_drawRectangleShape(game->window->window,
            button[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window, button[i]->text, NULL);
    }
}

static void display_size_buttons(game_t *game, const sfVector2i *mpos)
{
    buttons_t **button = game->params->visu->windows->size;
    int i = 0;

    for (i = 0; i < 2; i++) {
        draw_opt_button(game, i, mpos, "size");
        sfRenderWindow_drawRectangleShape(game->window->window,
            button[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window, button[i]->text, NULL);
    }
}

static void set_active_states(game_t *game)
{
    windows_t *w = game->params->visu->windows;
    sfVideoMode mode = game->params->mode;

    if (game->params->is_fullscreen == true)
        w->size[0]->state = ACTIVE;
    else
        w->size[1]->state = ACTIVE;
    if (mode.size.x == 1920 && mode.size.y == 1080)
        w->resolution[0]->state = ACTIVE;
    else if (mode.size.x == 1280 && mode.size.y == 720)
        w->resolution[1]->state = ACTIVE;
    else
        w->resolution[2]->state = ACTIVE;
}

void display_window_buttons(game_t *game)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);

    if (!menu_tab_window(game))
        return;
    set_active_states(game);
    display_size_buttons(game, &mpos);
    display_resolution_buttons(game, &mpos);
}
