/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** clients
*/

#include "game.h"

void create_clients(game_t *game)
{
    game->network->clients = malloc(sizeof(client_t) * 100);
    game->network->client_sprite = sfSprite_create();
    sfSprite_setScale(game->network->client_sprite, (sfVector2f) {0.7, 0.7});

    sfTexture *texture = sfTexture_createFromFile("assets/imgs/perso.png", 0);

    sfSprite_setTexture(game->network->client_sprite, texture, 0);
    sfSprite_setTextureRect(game->network->client_sprite,
    (sfIntRect) {0, 0, 70, 85});

    for (int i = 0; i < 100; i++) {
        game->network->clients[i].pos.x = -100;
        game->network->clients[i].pos.y = -100;
        game->network->clients[i].name = NULL;
        game->network->clients[i].rect = (sfIntRect) {0, 0, 70, 85};
    }
}
