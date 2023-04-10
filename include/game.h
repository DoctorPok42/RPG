/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "rpg.h"
    #include "window.h"
    #include "map.h"
    #include "perso.h"
    #include "mobs.h"
    #include "buttons.h"
    #include "params.h"
    #include "keys.h"
    #include "overlay.h"
    #include "clocks.h"

    typedef struct {
        window_t *window;
        map_t *map;
        perso_t *perso;
        mobs_t *mobs;
        buttons_t **start;
        buttons_t **game;
        params_t *params;
        keys_t *keys;
        int menu;
        overlay_t **overlay;
        clocks_t *clock;
    } game_t;

    #include "start.h"

#endif /* !GAME_H_ */