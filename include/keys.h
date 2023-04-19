/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** keys
*/

#ifndef KEYS_H_
    #define KEYS_H_

    #include "rpg.h"

    typedef struct {
        sfKeyCode up;
        sfKeyCode down;
        sfKeyCode left;
        sfKeyCode right;
        sfKeyCode space;
        sfKeyCode attack;
        sfKeyCode inventory;
        sfKeyCode pause;
        sfKeyCode interact;
        sfKeyCode escape;
        bool swith_keys;
    } keys_t;

#endif /* !KEYS_H_ */
