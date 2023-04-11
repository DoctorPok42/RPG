/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include "rpg.h"
    #include "songs.h"

    typedef struct {
        sfRenderWindow *window;
        sfView *view;
        sfEvent event;
        sfRectangleShape **rect;
        song_t *song;
        int close;
        const char *title;
    } window_t;

#endif /* !WINDOW_H_ */
