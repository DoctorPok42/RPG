/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** option
*/

#include "game.h"
#include "display.h"
#include "menu.h"

void relase_button(buttons_t **button, int i, int max)
{
    int j = 0;

    for (j = 0; j < max; j++)
        if (j != i)
            button[j]->state = RELEASE;
}

static void active_button(game_t *game, int i)
{
    game->params->visu->navbar->button[i]->state = ACTIVE;
    relase_button(game->params->visu->navbar->button, i, 5);
    menu_set_tab(game, i);
    sfSleep((sfTime){100000});
}

static void display_button_bg(game_t *game, int i, const sfVector2i *mpos)
{
    buttons_t **button = game->params->visu->navbar->button;
    sfVector2f pos = button[i]->pos;

    if (mpos->x >= pos.x && mpos->x <= pos.x + 140 && mpos->y >= pos.y
        && mpos->y <= pos.y + 50) {
        sfRectangleShape_setFillColor(button[i]->rect,
            (sfColor){25, 118, 210, 150});
        if (sfMouse_isButtonPressed(sfMouseLeft) == true)
            active_button(game, i);
    } else
        sfRectangleShape_setFillColor(button[i]->rect,
            (sfColor){25, 118, 210, 100});
    if (button[i]->state == ACTIVE)
        sfRectangleShape_setFillColor(button[i]->rect,
            (sfColor){25, 118, 210, 200});
}

static void display_buttons(game_t *game, const sfVector2i *mpos)
{
    buttons_t **button = game->params->visu->navbar->button;
    int i = 0;

    for (i = 0; i < 5; i++) {
        display_button_bg(game, i, mpos);
        sfRenderWindow_drawRectangleShape(game->window->window,
            button[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window, button[i]->text, NULL);
    }
}

static void draw_navbar_bg(game_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->params->visu->navbar->container, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->params->visu->navbar->content, NULL);
}

static void draw_panels(game_t *game)
{
    display_music(game);
    display_fps(game);
    display_keyboard(game);
    display_window_buttons(game);
}

void display_options(game_t *game)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);

    if (!menu_in_settings(game))
        return;
    if (menu_settings_open(game))
        game->params->visu->navbar->button[0]->state = ACTIVE;
    game->go_back->pos = (sfVector2f){20, 100};
    sfSprite_setPosition(game->go_back->sprite, game->go_back->pos);
    draw_navbar_bg(game);
    display_go_back(game);
    display_buttons(game, &mpos);
    draw_panels(game);
    game->go_back->pos = (sfVector2f){100, 100};
    sfSprite_setPosition(game->go_back->sprite, game->go_back->pos);
}
