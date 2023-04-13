/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** dialogs
*/

#ifndef DIALOG_H_
    #define DIALOG_H_

    #include "game.h"

    typedef struct dialog_s {
        char **text;
        struct dialog_s *next;
    } dialog_t;

    typedef struct {
        dialog_t *dialog;
        sfTexture *texture;
        sfSprite *sprite;
        sfText *text;
        sfFont *font;
        sfVector2f pos;
        sfClock *clock;
        sfTime time;
        float seconds;
    } dialog_box_t;

#endif /* !DIALOG_H_ */
