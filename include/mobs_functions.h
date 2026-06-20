/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** mobs_functions
*/

#ifndef MOBS_FUNCTIONS_H_
    #define MOBS_FUNCTIONS_H_

    #include "game.h"

void manage_mobs(game_t *game);
void move_ennemi(game_t *game, int mob_index, const sfVector2f *offset,
    const sfVector2f *mob_pos);
sfVector2f set_vector_speed(const sfVector2f *vec, float speed);

#endif /* !MOBS_FUNCTIONS_H_ */
