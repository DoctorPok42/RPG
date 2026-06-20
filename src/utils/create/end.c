/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** win
*/

#include "game.h"
#include "create.h"

static void create_scene_box(game_t *game, end_t *scene)
{
    sfVector2u win = game->params->window_size;

    scene->container = sfRectangleShape_create();
    sfRectangleShape_setSize(scene->container, (sfVector2f){win.x, win.y});
    sfRectangleShape_setPosition(scene->container, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(scene->container,
        sfColor_fromRGBA(0, 0, 0, 100));
    scene->content = sfRectangleShape_create();
    sfRectangleShape_setSize(scene->content,
        (sfVector2f){win.x / 1.5, win.y / 1.5});
    sfRectangleShape_setPosition(scene->content,
        (sfVector2f){win.x / 6.5, win.y / 6.5});
    sfRectangleShape_setFillColor(scene->content,
        sfColor_fromRGBA(85, 61, 51, 255));
}

static void create_scene_text(game_t *game, end_t *scene, char *str)
{
    sfVector2u win = game->params->window_size;

    scene->font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    scene->text = sfText_create(scene->font);
    sfText_setString(scene->text, str);
    sfText_setPosition(scene->text, (sfVector2f){win.x / 2.8, win.y / 2.4});
    sfText_setFont(scene->text, scene->font);
    sfText_setCharacterSize(scene->text, 100);
}

static void create_scene(game_t *game, end_t *scene, char *str)
{
    create_scene_box(game, scene);
    create_scene_text(game, scene, str);
}

void create_win_loose(game_t *game)
{
    game->win = malloc(sizeof(end_t));
    game->loose = malloc(sizeof(end_t));
    create_scene(game, game->win, "You  Win");
    create_scene(game, game->loose, "You  Lose");
}
