/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** save
*/

#include <sys/stat.h>
#include "game.h"

char *my_itoa(int nb);
char *my_strcat(char *dest, char const *src);

static void add_img(game_t *game, int i)
{
    struct stat st;
    char *path = "save/save";
    path = my_strcat(path, my_itoa(i + 1));
    path = my_strcat(path, ".png\0");
    if (stat(path, &st) == 0) {
        game->save->view->texture[i] = sfTexture_createFromFile(path, NULL);
        sfRectangleShape_setTexture(game->save->view->rect[i],
            game->save->view->texture[i], sfTrue);
        sfRectangleShape_setFillColor(game->save->view->rect[i],
            (sfColor){255, 255, 255, 255});
    } else {
        game->save->view->texture[i] = NULL;
        sfText_setString(game->save->view->name[i], "No save");
    }
}

static void create_div(game_t *game, int i, char *txt_save)
{
    game->save->view->rect[i] = sfRectangleShape_create();
    sfRectangleShape_setSize(game->save->view->rect[i],
        (sfVector2f){500, 600});
    sfRectangleShape_setPosition(game->save->view->rect[i],
        (sfVector2f){(i * 600) + game->params->window_size.x / 3 - 530,
        game->params->window_size.y / 2 - 300});
    sfRectangleShape_setFillColor(game->save->view->rect[i],
        (sfColor){46, 29, 26, 255});
    sfRectangleShape_setOutlineColor(game->save->view->rect[i],
        (sfColor){62, 39, 35, 255});
    sfRectangleShape_setOutlineThickness(game->save->view->rect[i], 8);
    sfFont *font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    game->save->view->name[i] = sfText_create();
    sfText_setString(game->save->view->name[i], txt_save);
    sfText_setFont(game->save->view->name[i], font);
    sfText_setCharacterSize(game->save->view->name[i], 50);
    sfText_setPosition(game->save->view->name[i], (sfVector2f){(i * 600) + 150,
    game->params->window_size.y / 2 + 200});
}

void create_save_menu(game_t *game)
{
    game->save = malloc(sizeof(save_t));
    game->save->view = malloc(sizeof(save_view_t));
    game->save->view->rect = malloc(sizeof(sfRectangleShape *) * 3);
    game->save->view->texture = malloc(sizeof(sfTexture *) * 3);
    game->save->view->name = malloc(sizeof(sfText *) * 3);
    game->save->view->title = sfText_create();

    char *txt_save[3] = {"Save 1", "Save 2", "Save 3"};

    for (int i = 0; i < 3; i++) {
        create_div(game, i, txt_save[i]);
        add_img(game, i);
    }
    sfFont *font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    sfText_setString(game->save->view->title, "Save");
    sfText_setFont(game->save->view->title, font);
    sfText_setCharacterSize(game->save->view->title, 100);
    sfText_setPosition(game->save->view->title,
        (sfVector2f){game->params->window_size.x / 2 - 150, 60});
}
