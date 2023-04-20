/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** dialog
*/

#include <string.h>
#include "game.h"

int my_tablen(char **tab);
int my_strlen(char *str);
char *my_strndup(char *str, int n);

sfClock* clock;
sfTime elapsed_time;

int diplay_text(game_t *game, char *str)
{
    int status = 0;
    sfRenderWindow_drawSprite(game->window->window,
            game->dialogs->sprite, NULL);
    sfText_setString(game->dialogs->text, str);
    sfRenderWindow_drawText(game->window->window,
            game->dialogs->text, NULL);
    sfRenderWindow_display(game->window->window);
    while (sfRenderWindow_isOpen(game->window->window)) {
        if (status == 1)
            break;
        while (sfRenderWindow_pollEvent(game->window->window,
                &game->window->event)) {
            (game->window->event.type == sfEvtClosed) ?
                sfRenderWindow_close(game->window->window) : 0;
            status = (game->window->event.type == sfEvtKeyPressed) ?
                1 : 0;
        }
    }
    return 0;
}

void display_dialog(game_t *game)
{
    if (game->menu != 4)
        return;

    diplay_text(game, game->dialogs->dialog_text[0]);

    game->menu = 5;
}
