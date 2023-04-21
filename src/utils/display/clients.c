/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** clients
*/

#include "game.h"
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

void receive_clients_infos (game_t *game);
void send_player_position (game_t *game);

void display_clients (game_t *game)
{
    if (game->network == NULL || game->menu < 5 || game->menu >= 10)
        return;

    send_player_position(game);
    receive_clients_infos(game);

    for (int i = 0; i < 100; i++) {

        sfSprite_setTextureRect(game->network->client_sprite,
        game->network->clients[i].rect);

        sfSprite_setPosition(game->network->client_sprite,
        game->network->clients[i].pos);

        sfRenderWindow_drawSprite(game->window->window,
        game->network->client_sprite, NULL);
    }

}
