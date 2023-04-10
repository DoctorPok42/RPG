/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** start
*/

#ifndef START_H_
    #define START_H_

    #include "game.h"

void exit_start_all(game_t *game);
void close_start_all(game_t *game);
void change_to_settings(game_t *game);

typedef struct start_flags_s {
    void (*functions)(void *);
} start_flags;

static const start_flags START_FLAGS[] = {
    {functions : (void *)&close_start_all},
    {},
    {functions : (void *)&change_to_settings},
    {functions : (void *)&exit_start_all},
    {functions : NULL}
};

#endif /* !START_H_ */
