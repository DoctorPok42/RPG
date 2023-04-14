/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** fps
*/

#include "game.h"

void create_button(buttons_t *button, char *text, int i, game_t *game);

void create_fps(game_t *game)
{
    game->params->visu->fps = malloc(sizeof(fps_t));
    game->params->visu->fps->button = malloc(sizeof(buttons_t *) * 4);
    char *fps[] = {"32", "60", "120", "144"};

    for (int i = 0; i < 4; i++) {
        game->params->visu->fps->button[i] = malloc(sizeof(buttons_t));
        game->params->visu->fps->button[i]->str = fps[i];
        create_button(game->params->visu->fps->button[i], fps[i], i, game);
        game->params->visu->fps->button[i]->pos = (sfVector2f){
            game->params->window_size.x / 10 + (i * 200),
                game->params->window_size.y / 3};

        sfRectangleShape_setPosition(game->params->visu->fps->button[i]->rect,
            game->params->visu->fps->button[i]->pos);
        sfText_setCharacterSize(game->params->visu->fps->button[i]->text, 25);
        sfText_setPosition(game->params->visu->fps->button[i]->text,
            (sfVector2f){game->params->visu->fps->button[i]->pos.x + 15,
                game->params->visu->fps->button[i]->pos.y + 7});
    }
}
