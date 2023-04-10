/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** dialog
*/

#include "game.h"

static void create_text(game_t *game)
{
    game->dialogs->text = sfText_create();
    game->dialogs->font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    game->dialogs->pos = (sfVector2f){
        game->params->window_size.x / 5,
        game->params->window_size.y / 1.2};
    game->dialogs->clock = sfClock_create();
    game->dialogs->time = sfClock_getElapsedTime(game->dialogs->clock);
    game->dialogs->seconds = game->dialogs->time.microseconds / 1000000.0;
    game->dialogs->dialog = NULL;

    game->dialogs->dialog = malloc(sizeof(dialog_t));
    game->dialogs->dialog->text = "Hello World";
    game->dialogs->dialog->next = NULL;

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
    sfIntRect rect = {.left = 0, .top = 50, .width = 260, .height = 65};
    game->dialogs->sprite = sfSprite_create();
    sfSprite_setTexture(game->dialogs->sprite, game->dialogs->texture, sfTrue);
    sfSprite_setTextureRect(game->dialogs->sprite, rect);
    sfSprite_setPosition(game->dialogs->sprite, (sfVector2f){
        game->params->window_size.x / 2 -
            sfTexture_getSize(game->dialogs->texture).x * 5 / 2,
        game->params->window_size.y / 1.3
    });
    sfSprite_setScale(game->dialogs->sprite, (sfVector2f){5, 3});
}
