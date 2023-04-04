/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** start
*/

#ifndef START_H_
    #define START_H_

    #include "lists.h"

void change_to_settings(menu_t *menu);
void close_start_all(menu_t *menu);

typedef struct start_flags_s {
    void (*functions)(void *);
} start_flags;

static const start_flags START_FLAGS[] = {
    {},
    {},
    {functions : (void *)&change_to_settings},
    {functions : (void *)&close_start_all},
    {functions : NULL}
};

#endif /* !START_H_ */
