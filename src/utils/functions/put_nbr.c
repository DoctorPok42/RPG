/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-remi.mazat
** File description:
** put_nbr
*/

#include <unistd.h>

int my_putchar(char c, int fd)
{
    write(fd, &c, 1);
    return 1;
}

int int_len(int valeur)
{
    int compteur = 0;
    while (valeur > 0) {
        compteur += 1;
        valeur /= 10;
    }
    return compteur;
}

int my_put_nbr(int valeur, int fd)
{
    int num;
    int compteur = int_len(valeur);
    if (valeur < 0) {
        my_putchar('-', fd);
        valeur = valeur * (-1);
    }
    if (valeur >= 10) {
        num = valeur % 10;
        valeur = valeur / 10;
        my_put_nbr(valeur, fd);
        my_putchar(num + 48, fd);
    } else {
        my_putchar(valeur + 48, fd);
    }
    return compteur;
}
