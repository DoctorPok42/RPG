/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** npc
*/

#ifndef NPC_H_
    #define NPC_H_

    #include "rpg.h"

    enum npc_state {
        None = 0,
        Talking = 1,
    };

    typedef struct {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfIntRect rect;
        sfClock *clock;
        sfTime time;
        float seconds;
        char *dialog;
        int dialog_index;
        float distance_to_player;
        enum npc_state state;
    } npc_t;

#endif /* !NPC_H_ */
