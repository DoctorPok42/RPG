/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** communication
*/

#include "game.h"

void send_player_position (game_t *game)
{
    sfPacket *packet = sfPacket_create();

    sfPacket_writeFloat(packet, game->perso->pos.x + game->map->rect.left * 3);
    sfPacket_writeFloat(packet, game->perso->pos.y + game->map->rect.top * 3);

    sfPacket_writeInt32(packet, game->perso->rect.left);
    sfPacket_writeInt32(packet, game->perso->rect.top);

    sfTcpSocket_sendPacket(game->network->server, packet);

    sfPacket_destroy(packet);
}

void receive_clients_infos (game_t *game)
{
    sfPacket *packet = sfPacket_create();
    sfBool done = sfFalse;

    while (!done) {
        if (sfTcpSocket_receivePacket(game->network->server, packet)
        == sfSocketDone) {

            int32_t i = sfPacket_readInt32(packet);
            game->network->clients[i].pos.x = sfPacket_readFloat(packet)
            - (game->map->rect.left * 3);
            game->network->clients[i].pos.y = sfPacket_readFloat(packet)
            - (game->map->rect.top * 3);
            game->network->clients[i].rect.left = sfPacket_readInt32(packet);
            game->network->clients[i].rect.top = sfPacket_readInt32(packet);

            sfPacket_clear(packet);
        } else
            done = sfTrue;
    }
    sfPacket_destroy(packet);
}
