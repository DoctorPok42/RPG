/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** clock
*/

#ifndef CLOCKS_H_
    #define CLOCKS_H_

    #include "game.h"

    typedef struct {
        sfClock *clock;
        sfTime time;
        float seconds;
    } clocks_t;

#endif /* !CLOCKS_H_ */
