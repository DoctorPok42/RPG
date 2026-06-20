/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** network_functions
*/

#ifndef NETWORK_FUNCTIONS_H_
    #define NETWORK_FUNCTIONS_H_

    #include "game.h"

void send_player_position(game_t *game);
void receive_clients_infos(game_t *game);
network_t *connect_to_server(void);

#endif /* !NETWORK_FUNCTIONS_H_ */
