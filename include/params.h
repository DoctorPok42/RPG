/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** params
*/

#ifndef PARAMS_H_
    #define PARAMS_H_

    #include "rpg.h"
    #include "buttons.h"

    typedef struct {
        sfRectangleShape *container;
        sfRectangleShape *content;
        sfRectangleShape *bar;
        sfVector2f pos;
        sfVector2f size;
        sfText *text;
        buttons_t *button;
    } visu_t;

    typedef struct {
        float volume;
        float scale;
        int fps;
        int fullscreen;
        int tmp;
        sfVector2u resolution;
        sfVector2u window_size;
        sfVideoMode mode;
        visu_t **visu;
    } params_t;

    typedef struct params_flags_s {
        void (*functions)(void *);
    } params_flags;

    static const params_flags PARAMS_FLAGS[] = {
        {functions : NULL}
    };

#endif /* !PARAMS_H_ */
