/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** my_str
*/

#ifndef MY_STR_H_
    #define MY_STR_H_

    #include <stddef.h>

int my_strlen(char const *str);
int my_tablen(char **tab);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_getnbr(char const *str);
char *my_itoa(int nb);
char *my_strcat(char *dest, char const *src);
char *my_strndup(char *str, int n);
char **my_str_to_word_array(char *str, char const separator);
int free_tab(char **tab);
int my_putchar(char c, int fd);
int my_put_nbr(int value, int fd);
int my_float(int prec, double n, int fd);

#endif /* !MY_STR_H_ */
