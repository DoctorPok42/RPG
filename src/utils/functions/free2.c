/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** free2
*/

#include "game.h"
#include "free.h"

static void free_navbar(game_t *game)
{
    navbar_t *navbar = game->params->visu->navbar;
    int i = 0;

    for (i = 0; i < 4; i++) {
        sfRectangleShape_destroy(navbar->button[i]->rect);
        sfText_destroy(navbar->button[i]->text);
        sfFont_destroy(navbar->button[i]->font);
        free(navbar->button[i]);
    }
    sfRectangleShape_destroy(navbar->container);
    sfRectangleShape_destroy(navbar->content);
    free(navbar);
}

static void free_params2(game_t *game)
{
    visu_t *visu = game->params->visu;
    int i = 0;

    for (i = 0; i < 4; i++) {
        sfRectangleShape_destroy(visu->fps->button[i]->rect);
        sfText_destroy(visu->fps->button[i]->text);
        sfFont_destroy(visu->fps->button[i]->font);
        free(visu->fps->button[i]);
    }
    free(visu->fps->button);
    free(visu->fps);
    sfRectangleShape_destroy(visu->music->container);
    sfRectangleShape_destroy(visu->music->bar);
    free(visu->music);
    for (i = 0; i < 2; i++) {
        sfFont_destroy(visu->keyboard->button[i]->font);
        free(visu->keyboard->button[i]);
    }
}

static void free_window_buttons(game_t *game)
{
    windows_t *w = game->params->visu->windows;
    int i = 0;

    for (i = 0; i < 2; i++) {
        sfRectangleShape_destroy(w->size[i]->rect);
        sfText_destroy(w->size[i]->text);
        sfFont_destroy(w->size[i]->font);
        free(w->size[i]);
    }
    for (i = 0; i < 3; i++) {
        sfRectangleShape_destroy(w->resolution[i]->rect);
        sfText_destroy(w->resolution[i]->text);
        sfFont_destroy(w->resolution[i]->font);
        free(w->resolution[i]);
    }
    free(w->size);
    free(w->resolution);
    free(w);
}

void free_params(game_t *game)
{
    free_navbar(game);
    free_params2(game);
    free_window_buttons(game);
    free(game->params);
}

void free_save(game_t *game)
{
    int i = 0;

    for (i = 0; i < 3; i++) {
        sfRectangleShape_destroy(game->save->view->rect[i]);
        sfFont_destroy((sfFont *)sfText_getFont(game->save->view->name[i]));
        sfText_destroy(game->save->view->name[i]);
        sfTexture_destroy(game->save->view->texture[i]);
    }
    sfFont_destroy((sfFont *)sfText_getFont(game->save->view->title));
    free(game->save->view->rect);
    free(game->save->view->name);
    free(game->save->view->texture);
    free(game->save->view);
    free(game->save);
}

void free_game_menu2(game_t *game)
{
    game_menu_t *menu = game->game_menu;
    int i = 0;

    for (i = 0; i < 7; i++) {
        sfText_destroy(menu->character->value[i]);
        sfText_destroy(menu->character->name[i]);
    }
    free(menu->character->name);
    free(menu->character->value);
    free(menu->character);
    sfRectangleShape_destroy(menu->quest->bar);
    sfFont_destroy(menu->quest->font);
    sfText_destroy(menu->quest->achievement);
    sfRectangleShape_destroy(menu->quest->content);
    sfRectangleShape_destroy(menu->quest->container);
    free(menu->quest);
    free(menu);
}
