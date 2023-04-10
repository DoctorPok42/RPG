/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** change_to_game
*/

#include "game.h"

void fade_out(game_t *game, float duration)
{
    sfClock *clock = sfClock_create();
    sfTime elapsed;
    float alpha = 1.0f;

    while (alpha > 0.0f) {
        elapsed = sfClock_getElapsedTime(clock);
        alpha = 1.0f - (sfTime_asSeconds(elapsed) / duration);
        if (alpha < 0.0f) alpha = 0.0f;

        sfRectangleShape_setFillColor(game->window->rect[0],
            sfColor_fromRGBA(255, 255, 255, alpha * 255.0f));

        sfRenderWindow_clear(game->window->window, sfBlack);
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->window->rect[0], NULL);
        sfRenderWindow_display(game->window->window);
    }

    sfClock_destroy(clock);
}

void change_to_game(game_t *game)
{
    if (game->menu == 1 && game->params->tmp == 0) {
        sfMusic_stop(game->window->song->music);
        sfMusic_destroy(game->window->song->music);

        game->window->song->music = sfMusic_createFromFile(
            "assets/songs/overworld.ogg");
        sfMusic_setLoop(game->window->song->music, sfTrue);
        sfMusic_setVolume(game->window->song->music, game->params->volume);
        sfMusic_play(game->window->song->music);

        fade_out(game, 1.5f);
        game->params->tmp = 1;
        game->window->title = "Link's Awakening";
    }
}
