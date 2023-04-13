/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** dialog
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "game.h"

char **my_str_to_word_array(char *str, char separator);

static void put_dialog(game_t *game)
{
    struct stat st;
    if (stat("assets/txt/dialog.txt", &st) == -1) return;
    int fd = open("assets/txt/dialog.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size); buffer[st.st_size] = '\0';
    char **tab = my_str_to_word_array(buffer, '\n');
    int place = 0;
    dialog_t *tmp = game->dialogs->dialog;
    for (int i = 0; i < 21; i++) {
        if (tab[i][0] == '#') {
            tmp->text[place] = NULL;
            tmp->next = malloc(sizeof(dialog_t));
            tmp = tmp->next; place = 0;
        }
        if (place == 0)
            tmp->text = malloc(sizeof(char *) * 10);
        tmp->text[place] = tab[i];
        place++;
    }
    tmp->next = NULL; close(fd);
}

static void create_text(game_t *game)
{
    game->dialogs->text = sfText_create();
    game->dialogs->font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    game->dialogs->pos = (sfVector2f){
        game->params->window_size.x / 10,
        game->params->window_size.y / 1.2};
    game->dialogs->clock = sfClock_create();
    game->dialogs->time = sfClock_getElapsedTime(game->dialogs->clock);
    game->dialogs->seconds = game->dialogs->time.microseconds / 1000000.0;
    game->dialogs->dialog = NULL;

    game->dialogs->dialog = malloc(sizeof(dialog_t));
    put_dialog(game);

    sfText_setFont(game->dialogs->text, game->dialogs->font);
    sfText_setCharacterSize(game->dialogs->text, 30);
    sfText_setPosition(game->dialogs->text, game->dialogs->pos);
    sfText_setColor(game->dialogs->text, sfWhite);
}

void create_dialog(game_t *game)
{
    game->dialogs = malloc(sizeof(dialog_box_t));
    create_text(game);
    game->dialogs->texture = sfTexture_createFromFile("assets/imgs/dialog.png",
        NULL);
    sfIntRect rect = {.left = 0, .top = 0, .width = 260, .height = 60};
    game->dialogs->sprite = sfSprite_create();
    sfSprite_setTexture(game->dialogs->sprite, game->dialogs->texture, sfTrue);
    sfSprite_setTextureRect(game->dialogs->sprite, rect);
    sfSprite_setPosition(game->dialogs->sprite, (sfVector2f){
        game->params->window_size.x / 2 -
            sfTexture_getSize(game->dialogs->texture).x * 7 / 2,
        game->params->window_size.y / 1.3
    });
    sfSprite_setScale(game->dialogs->sprite, (sfVector2f){7, 3});
}
