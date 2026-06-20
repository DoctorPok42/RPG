/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** fps
*/

#include "game.h"
#include "create.h"

static void setup_fps_button(game_t *game, int i, char *label)
{
    buttons_t *b = game->params->visu->fps->button[i];

    b->str = label;
    create_button(b, label, i, game);
    b->pos = (sfVector2f){game->params->window_size.x / 10 + (i * 200),
        game->params->window_size.y / 3};
    sfRectangleShape_setPosition(b->rect, b->pos);
    sfText_setCharacterSize(b->text, 25);
    sfText_setPosition(b->text, (sfVector2f){b->pos.x + 15, b->pos.y + 7});
}

void create_fps(game_t *game)
{
    char *fps[4] = {"32", "60", "120", "144"};
    int i = 0;

    game->params->visu->fps = malloc(sizeof(fps_t));
    game->params->visu->fps->button = malloc(sizeof(buttons_t *) * 4);
    for (i = 0; i < 4; i++) {
        game->params->visu->fps->button[i] = malloc(sizeof(buttons_t));
        setup_fps_button(game, i, fps[i]);
    }
}
