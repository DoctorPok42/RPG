/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** input
*/

#ifndef INPUT_H_
    #define INPUT_H_

    #include "game.h"

void input_handle_event(game_t *game);
bool is_key_held(game_t *game, sfKeyCode key);

#endif /* !INPUT_H_ */
