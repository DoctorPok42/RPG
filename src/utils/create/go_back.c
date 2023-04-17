/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** go_back
*/

#include "game.h"

void go_back(game_t *game);

void create_go_back(game_t *game)
{
    game->go_back = malloc(sizeof(buttons_t));
    game->go_back->texture = sfTexture_createFromFile("assets/imgs/button.png",
        NULL);
    game->go_back->sprite = sfSprite_create();
    sfSprite_setTexture(game->go_back->sprite, game->go_back->texture, sfTrue);
    sfSprite_setPosition(game->go_back->sprite, (sfVector2f){100, 100});
    game->go_back->pos = (sfVector2f){100, 100};
    game->go_back->rect_text = (sfIntRect){8, 440, 102, 105};
    sfSprite_setTextureRect(game->go_back->sprite, game->go_back->rect_text);
    game->go_back->callback = (void *)go_back;
}
