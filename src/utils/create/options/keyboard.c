/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** keys
*/

#include "game.h"
#include "create.h"

static void setup_key_button(game_t *game, int i, char *label)
{
    buttons_t **button = game->params->visu->keyboard->button;

    button[i]->str = label;
    create_button(button[i], label, i, game);
    button[i]->pos = (sfVector2f){game->params->window_size.x / 10 + (i * 200),
        game->params->window_size.y / 3};
    sfRectangleShape_setPosition(button[i]->rect, button[i]->pos);
    sfText_setPosition(button[i]->text,
        (sfVector2f){button[i]->pos.x + 15, button[i]->pos.y + 15});
}

void create_keyboard(game_t *game)
{
    char *keys[2] = {"Arrow Keys", "ZQSD"};
    int i = 0;

    game->params->visu->keyboard = malloc(sizeof(keyboard_t));
    game->params->visu->keyboard->button = malloc(sizeof(buttons_t *) * 2);
    for (i = 0; i < 2; i++) {
        game->params->visu->keyboard->button[i] = malloc(sizeof(buttons_t));
        setup_key_button(game, i, keys[i]);
    }
}
