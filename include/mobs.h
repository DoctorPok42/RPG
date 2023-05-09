/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** mobs
*/

#ifndef MOBS_H_
    #define MOBS_H_

    #include "rpg.h"

    enum mob_state {
        Neutral = 0,
        Attacking = 1,
    };

    typedef struct combat_s {
        int attack;
        int life;
    } mob_combat_t;

    typedef struct {
        sfVector2f pos;
        sfClock *clock;
        sfClock *clock_anime;
        enum mob_state state;
        float distance_to_player;
        float speed;
        sfSprite *sprite;
        sfIntRect TextureRect;
        sfBool is_alive;
        mob_combat_t *combat;
        int mob_type;
        int left_display;
    } mobs_t;

#endif /* !MOBS_H_ */
