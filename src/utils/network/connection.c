/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** server_connection
*/

#include <unistd.h>

#include "game.h"
#include "network_functions.h"
#include "config.h"

static sfTcpSocket *check_connection(sfTcpSocket *server)
{
    sfSocketSelector *selector = sfSocketSelector_create();

    sfSocketSelector_addTcpSocket(selector, server);
    if (sfSocketSelector_wait(selector, sfMilliseconds(1000)) != 0) {
        sfSocketSelector_removeTcpSocket(selector, server);
        sfSocketSelector_destroy(selector);
        write(1, "Connection refused by server\n", 29);
        sfTcpSocket_destroy(server);
        return NULL;
    }
    write(1, "Connected to server\n", 20);
    sfSocketSelector_removeTcpSocket(selector, server);
    sfSocketSelector_destroy(selector);
    return server;
}

network_t *connect_to_server(void)
{
    network_t *network = malloc(sizeof(network_t));

    if (network == NULL)
        return NULL;
    network->server = sfTcpSocket_create();
    sfTcpSocket_setBlocking(network->server, false);
    if (sfTcpSocket_connect(network->server, sfIpAddress_fromString(
                SERVER_IP), SERVER_PORT, sfSeconds(SERVER_TIMEOUT))
        == sfSocketError) {
        write(2, "Connection failed\n", 18);
        sfTcpSocket_destroy(network->server);
        free(network);
        return NULL;
    }
    if (check_connection(network->server) == NULL) {
        free(network);
        return NULL;
    }
    return network;
}
