/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** clients
*/

#include "game.h"
#include "display.h"
#include "network_functions.h"
#include "menu.h"

void display_clients(game_t *game)
{
    int i = 0;

    if (game->network == NULL || !menu_in_overworld(game))
        return;
    send_player_position(game);
    receive_clients_infos(game);
    for (i = 0; i < 100; i++) {
        sfSprite_setTextureRect(game->network->client_sprite,
            game->network->clients[i].rect);
        sfSprite_setPosition(game->network->client_sprite,
            game->network->clients[i].pos);
        sfRenderWindow_drawSprite(game->window->window,
            game->network->client_sprite, NULL);
    }
}
