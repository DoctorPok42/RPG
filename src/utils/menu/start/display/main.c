/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** display
*/

#include "lists.h"

static void create_buttons(button_t *button, sfIntRect *rect, sfVector2u size,
    int i)
{
    button->texture =
    sfTexture_createFromFile("assets/imgs/button.png",NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite,
        (sfVector2f){size.x / 4.3 + (i * 250), size.y / 1.35});
    button->pos = (sfVector2f){size.x / 4.3 + (i * 250), size.y / 1.35};
    button->rect_text = *rect;
}

void create_start_all(menu_t *menu, sfIntRect *rect[4])
{
    menu->button = malloc(sizeof(button_t *) * 5);
    sfVector2u window_size = sfRenderWindow_getSize(menu->window);
    for (int i = 0; i < 4; i++) {
        menu->button[i] = malloc(sizeof(button_t));
        create_buttons(menu->button[i], rect[i], window_size, i);
        menu->button[i]->callback = (void *)START_FLAGS[i].functions;
    }
    menu->rect = malloc(sizeof(sfRectangleShape *) * 1);
    menu->rect[0] = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->rect[0], (sfVector2f){1920, 1080});
    sfTexture *texture =
        sfTexture_createFromFile("assets/imgs/start/background.png", NULL);
    sfRectangleShape_setTexture(menu->rect[0], texture, sfTrue);
    menu->song = malloc(sizeof(song_t));
    menu->song->music = sfMusic_createFromFile("assets/songs/start.ogg");
    sfMusic_play(menu->song->music);
    sfMusic_setLoop(menu->song->music, sfTrue);
}

static void display_buttons(menu_t *menu, sfVector2i mpos)
{
    for (int i = 0; i < 4; i++) {
        sfVector2f pos = menu->button[i]->pos;
        if (mpos.x >= pos.x && mpos.x <= pos.x + 225 && mpos.y >= pos.y &&
            mpos.y <= pos.y + 105) {
            menu->button[i]->rect_text.left = 5 + 225;
            sfSprite_setTextureRect(menu->button[i]->sprite,
                menu->button[i]->rect_text);
                (sfMouse_isButtonPressed(sfMouseLeft)) ?
                menu->button[i]->callback(menu) : 0;
        } else {
            menu->button[i]->rect_text.left = 5;
            sfSprite_setTextureRect(menu->button[i]->sprite,
                menu->button[i]->rect_text);
        }
        sfRenderWindow_drawSprite(menu->window, menu->button[i]->sprite, NULL);
    }
}

void display_start_all(game_t *game, menu_t *menu)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(menu->window);
    sfRenderWindow_setTitle(menu->window, "Start | RPG");
    sfRenderWindow_clear(menu->window, sfBlue);
    sfRenderWindow_drawRectangleShape(menu->window, menu->rect[0], NULL);
    display_buttons(menu, mpos);
    sfMusic_setVolume(menu->song->music, game->volume);
    sfRenderWindow_display(menu->window);
}
