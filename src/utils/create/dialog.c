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
    game->dialogs->dialog_text = my_str_to_word_array(buffer, '#');
}

static void create_text(game_t *game)
{
    game->dialogs->text = sfText_create();
    game->dialogs->font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    game->dialogs->pos = (sfVector2f){
        game->params->window_size.x / 3,
        game->params->window_size.y / 1.43};
    game->dialogs->clock = sfClock_create();
    game->dialogs->time = sfClock_getElapsedTime(game->dialogs->clock);
    game->dialogs->seconds = game->dialogs->time.microseconds / 1000000.0;
    game->dialogs->dialog_text = NULL;

    put_dialog(game);

    sfText_setFont(game->dialogs->text, game->dialogs->font);
    sfText_setCharacterSize(game->dialogs->text, 15);
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
            sfTexture_getSize(game->dialogs->texture).x * 4 / 2,
        game->params->window_size.y / 1.5
    });
    sfSprite_setScale(game->dialogs->sprite, (sfVector2f){4, 5});
}
