/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** save
*/

#include "game.h"

void display_go_back(game_t *game);

void display_save(game_t *game)
{
    if (game->menu != 3)
        return;
    display_go_back(game);
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window->window);
    sfRenderWindow_drawText(game->window->window,
        game->save->view->title, NULL);
    for (int i = 0; i < 3; i++) {
        sfVector2f pos =
            sfRectangleShape_getPosition(game->save->view->rect[i]);
        if (mpos.x >= pos.x && mpos.x <= pos.x + 500 &&
            mpos.y >= pos.y && mpos.y <= pos.y + 600) {
            sfRectangleShape_setOutlineThickness(game->save->view->rect[i],15);
        } else {
            sfRectangleShape_setOutlineThickness(game->save->view->rect[i], 8);
        }
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->save->view->rect[i], NULL);
        sfRenderWindow_drawText(game->window->window,
            game->save->view->name[i], NULL);
    }
}
