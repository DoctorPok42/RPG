/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** start_menu
*/

#include "game.h"
#include "create.h"

static void create_start_buttons(buttons_t *button, sfIntRect *rect,
    const sfVector2u *size, int i)
{
    button->texture =
        sfTexture_createFromFile("assets/imgs/button.png", NULL);
    button->sprite = sfSprite_create(button->texture);
    sfSprite_setTexture(button->sprite, button->texture, true);
    sfSprite_setPosition(button->sprite,
        (sfVector2f){size->x / 4.3 + (i * 250), size->y / 1.35});
    button->pos = (sfVector2f){size->x / 4.3 + (i * 250), size->y / 1.35};
    button->rect_text = *rect;
    button->callback = (void *)START_FLAGS[i].functions;
}

void create_start_menu(game_t *game)
{
    sfTexture *texture = NULL;
    sfVector2u win = sfRenderWindow_getSize(game->window->window);
    sfIntRect *rect[4] = {
        &(sfIntRect){.position = {0, 5}, .size = {225, 105}},
        &(sfIntRect){.position = {0, 330}, .size = {225, 105}},
        &(sfIntRect){.position = {0, 223}, .size = {225, 105}},
        &(sfIntRect){.position = {0, 115}, .size = {225, 105}}};
    int i = 0;

    game->window->rect = malloc(sizeof(sfRectangleShape *) * 1);
    game->window->rect[0] = sfRectangleShape_create();
    sfRectangleShape_setSize(game->window->rect[0], (sfVector2f){1920, 1080});
    texture = sfTexture_createFromFile(
        "assets/imgs/start/background.png", NULL);
    sfRectangleShape_setTexture(game->window->rect[0], texture, true);
    game->start = malloc(sizeof(buttons_t *) * 4);
    for (i = 0; i < 4; i++) {
        game->start[i] = malloc(sizeof(buttons_t));
        create_start_buttons(game->start[i], rect[i], &win, i);
    }
}
