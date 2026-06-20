/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** input
*/

/*
** Event-driven keyboard state. sfKeyboard_isKeyPressed polls the OS and, on
** macOS, returns false without the "Input Monitoring" permission. Tracking the
** key state from KeyPressed/KeyReleased events instead only needs window focus,
** so the game plays anywhere.
*/

#include "game.h"
#include "input.h"

static void clear_keystate(game_t *game)
{
    int i = 0;

    for (i = 0; i < sfKeyCount; i++)
        game->keystate[i] = false;
}

void input_handle_event(game_t *game)
{
    sfEvent *event = &game->window->event;

    if (event->type == sfEvtFocusLost)
        clear_keystate(game);
    if (event->type != sfEvtKeyPressed && event->type != sfEvtKeyReleased)
        return;
    if (event->key.code < 0 || event->key.code >= sfKeyCount)
        return;
    game->keystate[event->key.code] = event->type == sfEvtKeyPressed;
}

bool is_key_held(game_t *game, sfKeyCode key)
{
    if (key < 0 || key >= sfKeyCount)
        return false;
    return game->keystate[key];
}
