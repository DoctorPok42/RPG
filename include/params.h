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
        buttons_t **button;
    } navbar_t;

    typedef struct {
        sfText *text;
        buttons_t **button;
    } fps_t;

    typedef struct {
        sfRectangleShape *container;
        sfRectangleShape *content;
        sfRectangleShape *bar;
        sfVector2f pos;
        sfVector2f size;
        sfText *text;
        buttons_t *button;
    } music_t;

    typedef struct {
        sfText *text;
        buttons_t **button;
    } keyboard_t;

    typedef struct {
        buttons_t **size;
        buttons_t **resolution;
    } windows_t;

    typedef struct {
        navbar_t *navbar;
        fps_t *fps;
        music_t *music;
        keyboard_t *keyboard;
        windows_t *windows;
    } visu_t;

    typedef struct {
        float volume;
        float scale;
        int fps;
        int fullscreen;
        int tmp;
        bool is_fullscreen;
        sfVector2u resolution;
        sfVector2u window_size;
        sfVideoMode mode;
        visu_t * visu;
    } params_t;

#endif /* !PARAMS_H_ */
