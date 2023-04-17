/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** start_game
*/

#include "game.h"

void create_game(game_t *game);
void events_window(game_t *game);
void display_all(game_t *game);
void manage_mobs (game_t *game);

static void init_game(game_t *game)
{
    game->params = malloc(sizeof(params_t));
    game->params->volume = 100;
    game->params->fps = 60;
    game->params->fullscreen = 0;
    game->params->resolution = (sfVector2u){1920, 1080};
    game->params->window_size = (sfVector2u){1920, 1080};
    game->params->mode = (sfVideoMode){1920, 1080, 32};
    game->keys = malloc(sizeof(keys_t));
    game->keys->up = sfKeyUp; game->keys->down = sfKeyDown;
    game->keys->left = sfKeyLeft; game->keys->right = sfKeyRight;
    game->keys->escape = sfKeyEscape;
    game->keys->space = sfKeySpace;
    game->keys->interact = sfKeyE;
    game->keys->inventory = sfKeyI;
    game->keys->pause = sfKeyP;
    game->keys->attack = sfKeyA;
    game->clock = malloc(sizeof(clocks_t));
    game->clock->clock = sfClock_create();
    game->perso = malloc(sizeof(perso_t));
    game->perso->clock = sfClock_create();
}

void add_mob (game_t *game, sfVector2f pos, sfIntRect texture_rec,
sfTexture *texture)
{
    int mob_index = 0;

    for (;game->mobs[mob_index] != NULL; mob_index++);
    game->mobs[mob_index + 1] = NULL;

    game->mobs[mob_index] = malloc(sizeof(mobs_t));
    game->mobs[mob_index]->clock = sfClock_create();
    game->mobs[mob_index]->pos = pos;
    game->mobs[mob_index]->speed = 2;
    game->mobs[mob_index]->is_alive = sfTrue;
    game->mobs[mob_index]->state = Neutral;
    game->mobs[mob_index]->TextureRect = texture_rec;
    game->mobs[mob_index]->sprite = sfSprite_create();
    sfSprite_setTexture(game->mobs[mob_index]->sprite, texture, 0);
}

void create_mobs (game_t *game)
{
    game->mobs = malloc(sizeof(mobs_t *) * 100);
    game->mobs[0] = NULL;

    sfTexture *texture = sfTexture_createFromFile("assets/imgs/mobs.png", NULL);

    add_mob(game, (sfVector2f) {1000, 500}, (sfIntRect)
    {10, 20, 25, 25}, texture);
    add_mob(game, (sfVector2f) {1100, 600}, (sfIntRect)
    {10, 20, 25, 25}, texture);
}

int start_game(game_t *game)
{
    init_game(game);
    create_game(game);
    create_mobs(game);
    while (sfRenderWindow_isOpen(game->window->window)) {
        events_window(game);
        display_all(game);
        if (game->menu != 0)
            manage_mobs(game);
        sfRenderWindow_display(game->window->window);
    }
    return (0);
}
