/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** dialog
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "game.h"
#include "create.h"
#include "my_str.h"

static void put_dialog(game_t *game)
{
    struct stat st;
    int fd = 0;
    char *buffer = NULL;

    if (stat("assets/txt/dialog.txt", &st) == -1)
        return;
    fd = open("assets/txt/dialog.txt", O_RDONLY);
    if (fd == -1)
        return;
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    if (buffer == NULL || read(fd, buffer, st.st_size) == -1) {
        free(buffer);
        close(fd);
        return;
    }
    buffer[st.st_size] = '\0';
    close(fd);
    game->dialogs->dialog_text = my_str_to_word_array(buffer, '#');
    free(buffer);
}

static void create_text(game_t *game)
{
    game->dialogs->font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    game->dialogs->text = sfText_create(game->dialogs->font);
    game->dialogs->pos = (sfVector2f){game->params->window_size.x / 3,
        game->params->window_size.y / 1.43};
    game->dialogs->clock = sfClock_create();
    game->dialogs->time = sfClock_getElapsedTime(game->dialogs->clock);
    game->dialogs->seconds = game->dialogs->time.microseconds / 1000000.0;
    game->dialogs->dialog_text = NULL;
    put_dialog(game);
    sfText_setFont(game->dialogs->text, game->dialogs->font);
    sfText_setCharacterSize(game->dialogs->text, 15);
    sfText_setPosition(game->dialogs->text, game->dialogs->pos);
    sfText_setFillColor(game->dialogs->text, sfWhite);
}

void create_dialog(game_t *game)
{
    sfIntRect rect = {.position = {0, 0}, .size = {260, 60}};
    sfVector2f pos = {0};

    game->dialogs = malloc(sizeof(dialog_box_t));
    create_text(game);
    game->dialogs->texture = sfTexture_createFromFile("assets/imgs/dialog.png",
        NULL);
    game->dialogs->sprite = sfSprite_create(game->dialogs->texture);
    sfSprite_setTexture(game->dialogs->sprite, game->dialogs->texture, true);
    sfSprite_setTextureRect(game->dialogs->sprite, rect);
    pos.x = game->params->window_size.x / 2
        - sfTexture_getSize(game->dialogs->texture).x * 4 / 2;
    pos.y = game->params->window_size.y / 1.5;
    sfSprite_setPosition(game->dialogs->sprite, pos);
    sfSprite_setScale(game->dialogs->sprite, (sfVector2f){4, 5});
}
