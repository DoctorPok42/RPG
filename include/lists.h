/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** lists
*/

#ifndef LISTS_H_
    #define LISTS_H_

    #include "rpg.h"

enum stats {
    none,
    HOVER,
    CLICK,
    RELEASE,
};


typedef struct {
    sfMusic *music;
    sfSound *sound;
    sfSoundBuffer *buffer;
} song_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *rect;
    sfText *text;
    sfFont *font;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect_text;
    enum stats state;
    void (*callback)(void *);
} button_t;

typedef struct menu_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2u window_size;
    sfRectangleShape **rect;
    button_t **button;
    song_t *song;
    bool close;
} menu_t;

typedef struct {
    sfVector2u window_size;
    menu_t **menu;
    int frameRate;
} game_t;

void close_start_all(menu_t *menu);

typedef struct flags_s {
    void (*functions)(void *);
} flags;

static const flags FLAGS[] = {
    {},
    {},
    {},
    {functions : (void *)close_start_all},
    {functions : NULL}
};

#endif /* !LISTS_H_ */
