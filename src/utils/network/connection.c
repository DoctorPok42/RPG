/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** server_connection
*/

#include <stdio.h>
#include <unistd.h>

#include "game.h"

sfTcpSocket *check_connection (sfTcpSocket *server)
{
    sfSocketSelector* selector = sfSocketSelector_create();
    sfSocketSelector_addTcpSocket(selector, server);

    if (sfSocketSelector_wait(selector, sfMilliseconds(1000)) == 0)
        write(1, "Connected to server\n", 20);
    else {
        sfSocketSelector_removeTcpSocket(selector, server);
        sfSocketSelector_destroy(selector);
        write(1, "Connection refused by server\n", 29);
        sfTcpSocket_destroy(server);
        return NULL;
    }

    sfSocketSelector_removeTcpSocket(selector, server);
    sfSocketSelector_destroy(selector);

    return server;
}

network_t *connect_to_server (void)
{
    network_t *network = malloc(sizeof(network_t));
    network->server = sfTcpSocket_create();
    sfTcpSocket_setBlocking(network->server, sfFalse);

    if (sfTcpSocket_connect(network->server, sfIpAddress_fromString
    ("142.93.35.112"), 6060, sfSeconds(2)) == sfSocketError) {

        write(2, "Connection failed\n", 18);
        sfTcpSocket_destroy(network->server);
        return NULL;

    }

    if (check_connection(network->server) == NULL)
        return NULL;

    return network;
}

// ("185.157.247.171"), 6060, sfSeconds(2)) == sfSocketError) {
