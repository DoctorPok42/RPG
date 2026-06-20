/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** dialog
*/

#include "game.h"
#include "display.h"
#include "menu.h"
#include "input.h"

static int poll_dialog(game_t *game)
{
    int status = 0;

    while (sfRenderWindow_pollEvent(game->window->window,
            &game->window->event)) {
        input_handle_event(game);
        if (game->window->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window->window);
        if (game->window->event.type == sfEvtKeyPressed)
            status = 1;
    }
    return status;
}

int diplay_text(game_t *game, char *str)
{
    int status = 0;

    sfRenderWindow_drawSprite(game->window->window,
        game->dialogs->sprite, NULL);
    sfText_setString(game->dialogs->text, str);
    sfRenderWindow_drawText(game->window->window,
        game->dialogs->text, NULL);
    sfRenderWindow_display(game->window->window);
    while (sfRenderWindow_isOpen(game->window->window) && status == 0)
        status = poll_dialog(game);
    return 0;
}

void display_dialog(game_t *game)
{
    if (!menu_is_dialog(game))
        return;
    diplay_text(game, game->dialogs->dialog_text[0]);
    game->menu = MENU_GAME;
}
