/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** params
*/

#ifndef PARAMS_H_
    #define PARAMS_H_

    #include "rpg.h"

    typedef struct {
        float volume;
        float scale;
        int fps;
        int fullscreen;
        int tmp;
        sfVector2u resolution;
        sfVector2u window_size;
        sfVideoMode mode;
    } params_t;

#endif /* !PARAMS_H_ */
