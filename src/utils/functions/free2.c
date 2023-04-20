/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** free2
*/
#include "game.h"

void free_navbar(game_t *game)
{
    for (int i = 0; i < 4; i++) {
        sfRectangleShape_destroy(game->params->visu->navbar->button[i]->rect);
        sfText_destroy(game->params->visu->navbar->button[i]->text);
        sfFont_destroy(game->params->visu->navbar->button[i]->font);
        free(game->params->visu->navbar->button[i]);
    }
    sfRectangleShape_destroy(game->params->visu->navbar->container);
    sfRectangleShape_destroy(game->params->visu->navbar->content);
    free(game->params->visu->navbar);
}
void free_params2(game_t *game)
{
    for (int i = 0; i < 4; i++) {
        sfRectangleShape_destroy(game->params->visu->fps->button[i]->rect);
        sfText_destroy(game->params->visu->fps->button[i]->text);
        sfFont_destroy(game->params->visu->fps->button[i]->font);
        free(game->params->visu->fps->button[i]);
    }
    free(game->params->visu->fps->button);
    free(game->params->visu->fps);
    sfRectangleShape_destroy(game->params->visu->music->container);
    sfRectangleShape_destroy(game->params->visu->music->bar);
    free(game->params->visu->music);
    free(game->params->visu->keyboard);
    for (int i = 0; i < 4; i++) {
        sfRectangleShape_destroy(game->params->visu->keyboard->button[i]->rect);
        sfText_destroy(game->params->visu->keyboard->button[i]->text);
        sfFont_destroy(game->params->visu->keyboard->button[i]->font);
        free(game->params->visu->keyboard->button[i]);
    }
}
void free_params(game_t * game)
{
    free_navbar(game);
    free_params2(game);
    for (int i = 0; i < 2; i++) {
        sfRectangleShape_destroy(game->params->visu->windows->size[i]->rect);
        sfText_destroy(game->params->visu->windows->size[i]->text);
        sfFont_destroy(game->params->visu->windows->size[i]->font);
        free(game->params->visu->windows->size[i]);
    }
    free(game->params->visu->windows->size);
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_destroy(game->params->visu->windows->resolution[i]->rect);
        sfText_destroy(game->params->visu->windows->resolution[i]->text);
        sfFont_destroy(game->params->visu->windows->resolution[i]->font);
        free(game->params->visu->windows->resolution[i]);
    }
    free(game->params->visu->windows->resolution);
    free(game->params->visu->windows);
    free(game->params);
}

void free_save(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_destroy(game->save->view->rect[i]);
        sfFont_destroy(sfText_getFont(game->save->view->name[i]));
        sfText_destroy(game->save->view->name[i]);
        sfTexture_destroy(game->save->view->texture[i]);
    }
    sfFont_destroy(sfText_getFont(game->save->view->title));
    free(game->save->view->rect);
    free(game->save->view->name);
    free(game->save->view->texture);
    free(game->save->view->title);
    free(game->save->view);
    free(game->save);
}

void free_game_menu2(game_t *game)
{
    for (int i = 0; i < 7; i++) {
        sfFont_destroy(sfText_getFont(game->game_menu->character->name[i]));
        sfFont_destroy(sfText_getFont(game->game_menu->character->value[i]));
        sfText_destroy(game->game_menu->character->value[i]);
        sfText_destroy(game->game_menu->character->name[i]);
    }
    free(game->game_menu->character->name);
    free(game->game_menu->character->value);
    free(game->game_menu->character);
    sfRectangleShape_destroy(game->game_menu->quest->bar);
    sfFont_destroy(game->game_menu->quest->font);
    sfText_destroy(game->game_menu->quest->achievement);
    sfRectangleShape_destroy(game->game_menu->quest->content);
    sfRectangleShape_destroy(game->game_menu->quest->container);
    free(game->game_menu->quest);
    free(game->game_menu);
}
