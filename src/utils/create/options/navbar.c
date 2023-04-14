/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** navbar
*/

#include "game.h"

void create_button(buttons_t *button, char *text, int i, game_t *game)
{
    button->rect = sfRectangleShape_create();
    button->text = sfText_create();
    button->font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    button->pos = (sfVector2f){game->params->window_size.x /
        10 + (i * 200), 20};
    button->size = (sfVector2f){140, 45};
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setFillColor(button->rect, (sfColor){25, 118, 210, 100});
    sfRectangleShape_setOutlineColor(button->rect, (sfColor){62, 39, 35, 255});
    sfRectangleShape_setOutlineThickness(button->rect, 3);
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 15);
    sfText_setPosition(button->text, (sfVector2f){button->pos.x + 15,
        button->pos.y + 15});
    sfText_setString(button->text, text);
}

static void create_navabar_buttons(game_t *game)
{
    game->params->visu->navbar->button = malloc(sizeof(buttons_t *) * 5);
    char *text[] = {"FPS", "Music", "Keybinds", "Save", "Window"};
    for (int i = 0; i < 5; i++) {
        game->params->visu->navbar->button[i] = malloc(sizeof(buttons_t));
        create_button(game->params->visu->navbar->button[i], text[i], i, game);
    }
}

void create_navbar(game_t *game)
{
    game->params->visu->navbar = malloc(sizeof(navbar_t));
    create_navabar_buttons(game);
    navbar_t *navbar = game->params->visu->navbar;
    sfVector2u size = game->params->window_size;
    navbar->container = sfRectangleShape_create();
    navbar->content = sfRectangleShape_create();

    sfRectangleShape_setSize(navbar->container, (sfVector2f){size.x, 80});
    sfRectangleShape_setPosition(navbar->container, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(navbar->container,
        (sfColor){62, 39, 35, 255});
    sfRectangleShape_setOutlineColor(navbar->container,
        (sfColor){46, 29, 26, 255});

    sfRectangleShape_setSize(navbar->content, (sfVector2f){size.x, 80});
    sfRectangleShape_setPosition(navbar->content, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(navbar->content, (sfColor){46, 29, 26, 255});
    sfRectangleShape_setOutlineColor(navbar->content,
        (sfColor){62, 39, 35, 255});
    sfRectangleShape_setOutlineThickness(navbar->content, 5);
}
