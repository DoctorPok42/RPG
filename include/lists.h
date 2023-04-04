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

typedef struct {
    sfRectangleShape *container;
    sfRectangleShape *content;
    sfRectangleShape *bar;
    sfVector2f pos;
    sfVector2f size;
    sfText *text;
} settings_t;

typedef struct {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2u window_size;
    sfRectangleShape **rect;
    button_t **button;
    song_t *song;
    bool close;
    const char *title;
    int current;
    settings_t **set;
} menu_t;

typedef struct {
    sfVector2u window_size;
    menu_t **menu;
    int frameRate;
    float volume;
    sfVideoMode mode;
    int scale;
} game_t;

    #include "start.h"

#endif /* !LISTS_H_ */
