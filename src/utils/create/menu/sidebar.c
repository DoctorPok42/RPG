/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** sidebar
*/

#include "game.h"
#include "create.h"

static void create_buttons(game_t *game, buttons_t *buttons,
    char *names, int i)
{
    sfVector2f pos = sfRectangleShape_getPosition(
        game->game_menu->sidebar->container);
    sfFont *font = sfFont_createFromFile("assets/fonts/dialog.ttf");

    buttons->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(buttons->rect,
        (sfVector2f){sfRectangleShape_getSize(
                game->game_menu->sidebar->container).x - 30, 60});
    buttons->pos = (sfVector2f){pos.x + 30, pos.y + (i * 80) + 60};
    sfRectangleShape_setPosition(buttons->rect, buttons->pos);
    sfRectangleShape_setFillColor(buttons->rect,
        sfColor_fromRGBA(46, 29, 26, 255));
    buttons->text = sfText_create(font);
    sfText_setString(buttons->text, names);
    sfText_setFont(buttons->text, font);
    sfText_setCharacterSize(buttons->text, 30);
    sfText_setPosition(buttons->text,
        (sfVector2f){sfRectangleShape_getPosition(buttons->rect).x + 20,
            sfRectangleShape_getPosition(buttons->rect).y + 10});
}

static void create_sidebar_buttons(game_t *game)
{
    char *buttons[5] = {"inventory", "character", "quest", "options", "quit"};
    int i = 0;

    game->game_menu->sidebar->buttons = malloc(sizeof(buttons_t *) * 6);
    game->game_menu->sidebar->buttons[4] = NULL;
    for (i = 0; i < 5; i++) {
        game->game_menu->sidebar->buttons[i] = malloc(sizeof(buttons_t));
        create_buttons(game, game->game_menu->sidebar->buttons[i],
            buttons[i], i);
        game->game_menu->sidebar->buttons[i]->state = NONE;
        game->game_menu->sidebar->buttons[i]->callback =
            (void *)MENU_FLAGS[i].function;
    }
}

void create_sidebar(game_t *game)
{
    sfVector2f pos = {0};
    sfVector2f size = {0};

    game->game_menu->sidebar = malloc(sizeof(sidebar_t));
    game->game_menu->sidebar->container = sfRectangleShape_create();
    pos = sfRectangleShape_getPosition(game->game_menu->content);
    size = sfRectangleShape_getSize(game->game_menu->content);
    sfRectangleShape_setSize(game->game_menu->sidebar->container,
        (sfVector2f){300, size.y});
    sfRectangleShape_setPosition(game->game_menu->sidebar->container,
        (sfVector2f){pos.x, pos.y});
    sfRectangleShape_setFillColor(game->game_menu->sidebar->container,
        sfColor_fromRGBA(46, 29, 26, 255));
    create_sidebar_buttons(game);
}
