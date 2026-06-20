/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** start
*/

#ifndef START_H_
    #define START_H_

typedef struct game_s game_t;

void exit_start_all(game_t *game);
void close_start_all(game_t *game);
void change_to_save(game_t *game);
void change_to_settings(game_t *game);
void go_back(game_t *game);

typedef struct start_flags_s {
    void (*functions)(void *);
} start_flags_t;

extern const start_flags_t START_FLAGS[];

#endif /* !START_H_ */
