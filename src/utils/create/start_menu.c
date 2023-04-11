/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** start_menu
*/

#include "game.h"

static void create_start_buttons(buttons_t *button, sfIntRect *rect,
    sfVector2u size, int i)
{
    button->texture =
    sfTexture_createFromFile("assets/imgs/button 1.png",NULL);

    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite,
        (sfVector2f){size.x / 4.3 + (i * 250), size.y / 1.35});

    button->pos = (sfVector2f){size.x / 4.3 + (i * 250), size.y / 1.35};
    button->rect_text = *rect;
    button->callback = (void *)START_FLAGS[i].functions;
}

void create_start_menu(game_t *game)
{
    game->window->rect = malloc(sizeof(sfRectangleShape *) * 1);
    game->window->rect[0] = sfRectangleShape_create();
    sfRectangleShape_setSize(game->window->rect[0], (sfVector2f){1920, 1080});
    sfTexture *texture =
        sfTexture_createFromFile("assets/imgs/start/background.png", NULL);
    sfRectangleShape_setTexture(game->window->rect[0], texture, sfTrue);

    game->start = malloc(sizeof(buttons_t *) * 4);
    sfIntRect *rect[4] = {&(sfIntRect){0, 5, 225, 105},
        &(sfIntRect){0, 330, 225, 105}, &(sfIntRect){0, 223, 225, 105},
        &(sfIntRect){0, 115, 225, 105}};
    sfVector2u window_size = sfRenderWindow_getSize(game->window->window);
    for (int i = 0; i < 4; i++) {
        game->start[i] = malloc(sizeof(buttons_t));
        create_start_buttons(game->start[i], rect[i], window_size, i);
    }
}
