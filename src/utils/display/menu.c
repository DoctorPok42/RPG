/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu
*/

#include "game.h"

void relase_button(buttons_t **button, int i, int max);
void display_inventory_menu(game_t *game);
void display_charracter(game_t *game);
void display_quest(game_t *game);

static void active_button(game_t *game, int i)
{
    game->game_menu->sidebar->buttons[i]->state = ACTIVE;
    relase_button(game->game_menu->sidebar->buttons, i, 4);
    game->game_menu->sidebar->buttons[i]->callback(game);
    sfSleep((sfTime){105000});
}

static void display_buttons(game_t *game, sfVector2i mpos)
{
    buttons_t **button = game->game_menu->sidebar->buttons;
    for (int i = 0; i < 5; i++) {
        sfVector2f pos = button[i]->pos;
        if (mpos.x >= pos.x && mpos.x <= pos.x + 200 && mpos.y >= pos.y &&
            mpos.y <= pos.y + 50) {
            sfRectangleShape_setFillColor(button[i]->rect,
                sfColor_fromRGBA(85, 61, 51, 255));
                (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) ?
                    active_button(game, i) : 0;
        } else
            sfRectangleShape_setFillColor(button[i]->rect,
                sfColor_fromRGBA(46, 29, 26, 255));
        if (button[i]->state == ACTIVE)
            sfRectangleShape_setFillColor(button[i]->rect,
                sfColor_fromRGBA(85, 61, 51, 255));
        sfRenderWindow_drawRectangleShape(game->window->window,
            button[i]->rect, NULL);
        sfRenderWindow_drawText(game->window->window,
            button[i]->text, NULL);
    }
}

void display_menu(game_t *game)
{
    if ((game->menu % 10 != 6 && ((game->menu / 10) % 10 != 6)) ||
        game->menu >= 563) {
            game->params->tmp = 0; return;
        }
    if (game->menu % 10 == 6)
        relase_button(game->game_menu->sidebar->buttons, 5, 4);
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->game_menu->container, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->game_menu->content, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->game_menu->sidebar->container, NULL);
    if (game->params->tmp == 0) {
        game->perso->pos_save = game->perso->pos;
        game->params->tmp = 1;
    }
    display_buttons(game, mpos);
    display_inventory_menu(game);
    display_charracter(game); display_quest(game);
}
