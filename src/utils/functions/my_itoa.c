/*
** EPITECH PROJECT, 2023
** mypaint
** File description:
** my_itoa
*/

#include <stdlib.h>
#include "my_str.h"

static int itoa_len(long nb)
{
    int len = 1;

    if (nb < 0)
        len = 2;
    while (nb <= -10 || nb >= 10) {
        len++;
        nb /= 10;
    }
    return len;
}

char *my_itoa(int nb)
{
    long value = nb;
    int len = itoa_len(value);
    char *str = malloc(sizeof(char) * (len + 1));
    int i = len - 1;

    if (str == NULL)
        return NULL;
    str[len] = '\0';
    if (value < 0) {
        str[0] = '-';
        value = -value;
    }
    if (value == 0)
        str[0] = '0';
    while (value != 0) {
        str[i] = '0' + value % 10;
        value /= 10;
        i--;
    }
    return str;
}
