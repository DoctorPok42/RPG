/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** network
*/

#ifndef _NETWORK_H_
    #define _NETWORK_H_

    #include "rpg.h"

    typedef struct {
        sfVector2f pos;
        sfIntRect rect;
        char *name;
    } client_t;

    typedef struct {
        client_t *clients;
        sfTcpSocket *server;
        sfSprite *client_sprite;
    } network_t;

#endif /*_NETWORK_H_*/
