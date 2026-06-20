/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** communication
*/

#include "game.h"
#include "network_functions.h"

void send_player_position(game_t *game)
{
    sfPacket *packet = sfPacket_create();

    sfPacket_writeFloat(packet,
        game->perso->pos.x + game->map->rect.position.x * 3);
    sfPacket_writeFloat(packet,
        game->perso->pos.y + game->map->rect.position.y * 3);
    sfPacket_writeInt32(packet, game->perso->rect.position.x);
    sfPacket_writeInt32(packet, game->perso->rect.position.y);
    sfTcpSocket_sendPacket(game->network->server, packet);
    sfPacket_destroy(packet);
}

static void read_client(game_t *game, sfPacket *packet)
{
    int32_t i = sfPacket_readInt32(packet);
    client_t *client = NULL;

    if (i < 0 || i >= MAX_CLIENTS)
        return;
    client = &game->network->clients[i];
    client->pos.x = sfPacket_readFloat(packet)
        - game->map->rect.position.x * 3;
    client->pos.y = sfPacket_readFloat(packet)
        - game->map->rect.position.y * 3;
    client->rect.position.x = sfPacket_readInt32(packet);
    client->rect.position.y = sfPacket_readInt32(packet);
}

void receive_clients_infos(game_t *game)
{
    sfPacket *packet = sfPacket_create();

    while (sfTcpSocket_receivePacket(game->network->server, packet)
        == sfSocketDone) {
        read_client(game, packet);
        sfPacket_clear(packet);
    }
    sfPacket_destroy(packet);
}
