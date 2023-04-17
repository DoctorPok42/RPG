/*
** EPITECH PROJECT, 2023
** mypaint
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 10);
    int nb2 = nb;
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    while (nb2 > 0) {
        nb2 = nb2 / 10;
        i++;
    }
    str[i] = '\0';
    i--;
    while (i >= 0) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
        i--;
    } return (str);
}
