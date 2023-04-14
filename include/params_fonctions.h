/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** params_fonctions
*/

#ifndef PARAMS_FONCTIONS_H_
    #define PARAMS_FONCTIONS_H_

    #include "game.h"

    void set_fullscreen(game_t *game);
    void set_windowed(game_t *game);
    void set_1920x1080(game_t *game);
    void set_1280x720(game_t *game);
    void set_800x600(game_t *game);

    typedef struct {
        void (*fonctions)(game_t *game);
    } params_functions_t;

    static const params_functions_t PARAMS_FLAGS[] = {
        {fonctions : &set_fullscreen},
        {fonctions : &set_windowed},
        {fonctions : &set_1920x1080},
        {fonctions : &set_1280x720},
        {fonctions : &set_800x600},
        {fonctions : NULL},
    };

#endif /* !PARAMS_FONCTIONS_H_ */
