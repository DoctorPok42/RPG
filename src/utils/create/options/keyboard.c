/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** keys
*/

#include "game.h"

void create_button(buttons_t *button, char *text, int i, game_t *game);

void create_keyboard(game_t *game)
{
    game->params->visu->keyboard = malloc(sizeof(keyboard_t));
    game->params->visu->keyboard->button = malloc(sizeof(buttons_t *) * 2);
    char *keys[] = {"Arrow Keys", "ZQSD"};
    buttons_t **button = game->params->visu->keyboard->button;
    for (int i = 0; i < 2; i++) {
        button[i] = malloc(sizeof(buttons_t));
        button[i]->str = keys[i];
        create_button(button[i], keys[i], i, game);
        button[i]->pos = (sfVector2f){
            game->params->window_size.x / 10 + (i * 200),
            game->params->window_size.y / 3};
        sfRectangleShape_setPosition(button[i]->rect, button[i]->pos);
        sfText_setPosition(button[i]->text, (sfVector2f){button[i]->pos.x + 15,
                button[i]->pos.y + 15});
    }
}
