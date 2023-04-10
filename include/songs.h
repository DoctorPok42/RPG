/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** songs
*/

#ifndef SONGS_H_
    #define SONGS_H_

    #include "rpg.h"

    typedef struct {
        sfMusic *music;
        sfSound *sound;
        sfSoundBuffer *buffer;
    } song_t;

#endif /* !SONGS_H_ */
