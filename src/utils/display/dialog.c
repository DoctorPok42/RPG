/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** dialog
*/

#include <string.h>
#include "game.h"

static int diplay_text(game_t *game)
{
    int len = strlen(game->dialogs->dialog->text);
    char *str = malloc(sizeof(char) * len);
    sfClock* clock = sfClock_create();
    sfTime elapsed_time = sfTime_Zero;
    for (int i = 0; i <= len; i++) {
        if (sfKeyboard_isKeyPressed(game->keys->interact) == sfTrue)
            return 1;
        str = strndup(game->dialogs->dialog->text, i);
        sfText_setString(game->dialogs->text, str);
        sfRenderWindow_drawText(game->window->window,
            game->dialogs->text, NULL);
        sfRenderWindow_display(game->window->window);
        elapsed_time = sfClock_getElapsedTime(clock);
        while (sfTime_asMilliseconds(elapsed_time) < 150) {
            elapsed_time = sfClock_getElapsedTime(clock);
        }
        sfClock_restart(clock);
    }
    sfClock_destroy(clock); free(str);
    return 0;
}

void display_dialog(game_t *game)
{
    if (game->menu != 2)
        return;
    sfRenderWindow_drawSprite(game->window->window,
        game->dialogs->sprite, NULL);
    if (diplay_text(game) != 1)
        sfSleep(sfSeconds(2));
    game->menu = 3;
}
