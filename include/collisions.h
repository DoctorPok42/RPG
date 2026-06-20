/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** collisions
*/

#ifndef COLLISIONS_H_
    #define COLLISIONS_H_

    #include "game.h"

int is_colliding(game_t *game, const sfVector2f *pos,
    const sfVector2f *offset);

#endif /* !COLLISIONS_H_ */
