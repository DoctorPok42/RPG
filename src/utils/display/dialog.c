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

static int print_caract(game_t *game, int i, char *str)
{
    int len_word = my_strlen(game->dialogs->dialog->text[i]);
    for (int j = 0; j <= len_word; j++) {
        if (sfKeyboard_isKeyPressed(game->keys->interact) == sfTrue &&
            game->dialogs->dialog->text[i + 1] != NULL) {
            i++; j = 0; sfClock_restart(clock);
        } if (sfKeyboard_isKeyPressed(game->keys->interact) ==
            sfTrue && game->dialogs->dialog->text[i + 1] == NULL) {
            sfClock_destroy(clock); free(str); return 1;
        } str = my_strndup(game->dialogs->dialog->text[i], j);
        sfText_setString(game->dialogs->text, str);
        sfRenderWindow_drawText(game->window->window,
            game->dialogs->text, NULL);
        sfRenderWindow_display(game->window->window);
        elapsed_time = sfClock_getElapsedTime(clock);
        while (sfTime_asMilliseconds(elapsed_time) < 50)
            elapsed_time = sfClock_getElapsedTime(clock);
        sfRenderWindow_clear(game->window->window, sfBlack);
        sfRenderWindow_drawSprite(game->window->window,
            game->dialogs->sprite, NULL); sfClock_restart(clock);
    } return 0;
}

static int diplay_text(game_t *game)
{
    int len = my_tablen(game->dialogs->dialog->text);
    char *str = malloc(sizeof(char) * len);
    clock = sfClock_create();
    elapsed_time = sfTime_Zero;
    for (int i = 0; game->dialogs->dialog->text[i] != NULL; i++) {
        if (print_caract(game, i, str) == 1)
            return 1;
        sfSleep(sfSeconds(1));
    }
    sfClock_destroy(clock); free(str);
    return 0;
}

void display_dialog(game_t *game)
{
    if (game->menu != 4)
        return;
    sfRenderWindow_drawSprite(game->window->window,
        game->dialogs->sprite, NULL);
    if (diplay_text(game) != 1)
        sfSleep(sfSeconds(1));
    game->menu = 5;
}
