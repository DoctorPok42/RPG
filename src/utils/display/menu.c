/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu
*/

#include "game.h"
#include "display.h"
#include "menu.h"

static void active_button(game_t *game, int i)
{
    game->game_menu->sidebar->buttons[i]->state = ACTIVE;
    relase_button(game->game_menu->sidebar->buttons, i, 4);
    game->game_menu->sidebar->buttons[i]->callback(game);
    sfSleep((sfTime){105000});
}

static void update_button(game_t *game, int i, const sfVector2i *mpos)
{
    buttons_t **button = game->game_menu->sidebar->buttons;
    sfVector2f pos = button[i]->pos;

    if (mpos->x >= pos.x && mpos->x <= pos.x + 200 && mpos->y >= pos.y
        && mpos->y <= pos.y + 50) {
        sfRectangleShape_setFillColor(button[i]->rect,
            sfColor_fromRGBA(85, 61, 51, 255));
        if (sfMouse_isButtonPressed(sfMouseLeft) == true)
            active_button(game, i);
    } else
        sfRectangleShape_setFillColor(button[i]->rect,
            sfColor_fromRGBA(46, 29, 26, 255));
    if (button[i]->state == ACTIVE)
        sfRectangleShape_setFillColor(button[i]->rect,
            sfColor_fromRGBA(85, 61, 51, 255));
}

static void display_buttons(game_t *game, const sfVector2i *mpos)
{
    buttons_t **button = game->game_menu->sidebar->buttons;
    int i = 0;

    for (i = 0; i < 5; i++) {
        update_button(game, i, mpos);
        sfRenderWindow_drawRectangleShape(game->window->window,
            button[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window, button[i]->text, NULL);
    }
}

static void draw_menu_bg(game_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->game_menu->container, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->game_menu->content, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->game_menu->sidebar->container, NULL);
}

void display_menu(game_t *game)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);

    if (!menu_pause_active(game)) {
        game->params->tmp = 0;
        return;
    }
    if (menu_pause_open(game))
        relase_button(game->game_menu->sidebar->buttons, 5, 4);
    draw_menu_bg(game);
    if (game->params->tmp == 0) {
        game->perso->pos_save = game->perso->pos;
        game->params->tmp = 1;
    }
    display_buttons(game, &mpos);
    display_inventory_menu(game);
    display_charracter(game);
    display_quest(game);
}
