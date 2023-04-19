/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** window
*/

#include "game.h"

void create_button(buttons_t *button, char *text, int i, game_t *game);

static void create_size_buttons(game_t *game, char *size[])
{
    buttons_t **button = game->params->visu->windows->size;
    for (int i = 0; i < 2; i++) {
        button[i] = malloc(sizeof(buttons_t));
        button[i]->str = size[i];
        create_button(button[i], size[i], i, game);
        button[i]->pos = (sfVector2f){
            game->params->window_size.x / 10 + (i * 200),
                game->params->window_size.y / 3};
        button[i]->size = (sfVector2f){170, 50};
        sfRectangleShape_setSize(button[i]->rect, button[i]->size);
        sfRectangleShape_setPosition(button[i]->rect, button[i]->pos);
        sfText_setCharacterSize(button[i]->text, 20);
        sfText_setPosition(button[i]->text, (sfVector2f){button[i]->pos.x + 15,
                button[i]->pos.y + 14});
    }
    button[0]->callback = (void *)PARAMS_FLAGS[0].fonctions;
    button[1]->callback = (void *)PARAMS_FLAGS[1].fonctions;
}

static void create_resolution_buttons(game_t *game, char *resolution[])
{
    buttons_t **button = game->params->visu->windows->resolution;
    for (int i = 0; i < 3; i++) {
        button[i] = malloc(sizeof(buttons_t));
        button[i]->str = resolution[i];
        create_button(button[i], resolution[i], i, game);
        button[i]->pos = (sfVector2f){
            game->params->window_size.x / 10 + (i * 200),
                game->params->window_size.y / 2};
        button[i]->size = (sfVector2f){160, 50};
        sfRectangleShape_setSize(button[i]->rect, button[i]->size);
        sfRectangleShape_setPosition(button[i]->rect, button[i]->pos);
        sfText_setCharacterSize(button[i]->text, 20);
        sfText_setPosition(button[i]->text, (sfVector2f){button[i]->pos.x + 15,
                button[i]->pos.y + 14});
    }
    button[0]->callback = (void *)PARAMS_FLAGS[2].fonctions;
    button[1]->callback = (void *)PARAMS_FLAGS[3].fonctions;
    button[2]->callback = (void *)PARAMS_FLAGS[4].fonctions;
}

void create_window_button(game_t *game)
{
    game->params->visu->windows = malloc(sizeof(windows_t));
    game->params->visu->windows->size = malloc(sizeof(buttons_t *) * 2);
    game->params->visu->windows->resolution = malloc(sizeof(buttons_t *) * 3);
    char *size[] = {"Fullscren", "Windowed"};
    char *resolution[] = {"1920x1080", "1280x720", "800x600"};
    create_size_buttons(game, size);
    create_resolution_buttons(game, resolution);
}
